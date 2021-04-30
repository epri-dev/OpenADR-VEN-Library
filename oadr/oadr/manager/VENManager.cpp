/*
 * VENManager.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: dupes
 */

#include "../manager/VENManager.h"
#include "../helper/SignatureContext.h"

VENManager::VENManager(unique_ptr<VEN2b> ven, IEventService *eventService, IReportService *reportService, IOADRExceptionService *exceptionService, seconds registerRetryInterval, seconds exceptionRetryInterval) :
	m_ven(std::move(ven)),
	m_reportService(reportService),
	m_exceptionService(exceptionService),
	m_registerRetryInterval(registerRetryInterval),
	m_exceptionRetryInterval(exceptionRetryInterval)
{
	m_scheduler = unique_ptr<Scheduler>(new Scheduler());

	m_eventManager = unique_ptr<EventManager>(new EventManager(
			m_scheduler.get(),
			eventService,
			this
			));

	m_reportManager = unique_ptr<ReportManager>(new ReportManager(
			m_scheduler.get(),
			reportService,
			this
			));

	m_shutdown = false;
}

/********************************************************************************/

VENManager::~VENManager()
{
}

/********************************************************************************/

void VENManager::sendCreatedEvent(string responseCode, string responseDescription, string requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses)
{
	m_ven->createdEvent(responseCode, responseDescription, eventResponses);
}

/********************************************************************************/

void VENManager::sendUpdateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, string reportRequestID, time_t createdDateTime)
{
	m_ven->updateReport(sequence, dtstart, reportRequestID, createdDateTime);
}

/********************************************************************************/

void VENManager::sendCreatedReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription)
{
	m_ven->createdReport(requestID, responseCode, responseDescription, pendingReports);
}

/********************************************************************************/

void VENManager::sendCanceledReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription)
{
	m_ven->canceledReport(requestID, responseCode, responseDescription, pendingReports);
}

/********************************************************************************/

IVENManager *VENManager::init(VENManagerConfig &config)
{
	unique_ptr<HttpCurl> http(new HttpCurl());

	http->setTimeouts(config.timeouts.connectTimeout, config.timeouts.requestTimeout);

	if (config.tls.useTls)
	{
		http->setParameters(config.tls.certPath,
				config.tls.privateKeyPath,
				config.tls.caBundlePath,
				config.tls.verifyHostname,
				config.tls.cipherList,
				config.tls.sslVersion);
	}

	auto SignatureContextCreator = [&]()
	{
		std::unique_ptr<SignatureContext> result;
		if (config.signature.certPath.empty() &&
			config.signature.signingKeyPath.empty() &&
			config.signature.caBundlePath.empty())
		{
			return result;
		}
		if (!config.signature.certPath.empty() &&
			!config.signature.signingKeyPath.empty() &&
			!config.signature.caBundlePath.empty())
		{
			result.reset(new SignatureContext(config.signature.certPath,
			                                  config.signature.signingKeyPath,
			                                  config.signature.caBundlePath));
			return result;
		}
		throw std::runtime_error("Signature config incomplete! Expected all certPath, signingKeyPath, and caBundlePath.");
	};

	unique_ptr<VEN2b> ven(new VEN2b(std::move(http),
			config.vtnURL,
			config.venName,
			config.venID,
			config.registrationID,
			SignatureContextCreator()));

	ven->setOadrMessage(config.services.oadrMessage);

	VENManager *venManager = new VENManager(std::move(ven),
			config.services.eventService,
			config.services.reportService,
			config.services.exceptionService,
			config.registerRetryInterval,
			config.exceptionRetryInterval);

	return venManager;
}

/********************************************************************************/

void VENManager::exceptionWait()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	m_condition.wait_for(lock, seconds(m_exceptionRetryInterval));
}

/********************************************************************************/

void VENManager::poll()
{
	unique_ptr<Poll> poll = m_ven->poll();

	oadrPayload *response = poll->response();

	if (response == NULL)
	{
		stringstream s;

		s << "invalid response from poll: " << poll->responseBody() << endl;

		std::runtime_error ex(s.str());

		m_exceptionService->OnException(ex);

		return;
	}

	if (response->oadrSignedObject().oadrResponse().present())
	{
		// processMessage(response->oadrSignedObject().oadrResponse().get());
	}
	else if (response->oadrSignedObject().oadrDistributeEvent().present())
	{
		m_eventManager->manageEvents(response->oadrSignedObject().oadrDistributeEvent().get());
	}
	else if (response->oadrSignedObject().oadrCreateReport().present())
	{
		m_reportManager->manageCreateReport(response->oadrSignedObject().oadrCreateReport().get());
	}
	else if (response->oadrSignedObject().oadrRegisterReport().present())
	{
		m_ven->registeredReport(response->oadrSignedObject().oadrRegisterReport()->requestID(), "200", "OK");
	}
	else if (response->oadrSignedObject().oadrCancelReport().present())
	{
		m_reportManager->manageCancelReport(response->oadrSignedObject().oadrCancelReport().get());
	}
	else if (response->oadrSignedObject().oadrUpdateReport().present())
	{
		// Not supported
	}
	else if (response->oadrSignedObject().oadrCancelPartyRegistration().present())
	{
		// processMessage(response->oadrSignedObject().oadrCancelPartyRegistration().get());
		// TODO: what's the proper response when a cancel registration message is received?

		m_ven->clearRegistration();
	}
	else if (response->oadrSignedObject().oadrRequestReregistration().present())
	{
		m_ven->clearRegistration();
	}

}

/********************************************************************************/

void VENManager::registerReports()
{
	oadrRegisterReportType::oadrReport_sequence sequence;

	m_reportService->OnGenerateRegisterReport(sequence);

	m_reportManager->setRegisteredReports(sequence);

	m_ven->registerReport(sequence);
}

/********************************************************************************/

void VENManager::requestEvents()
{
	unique_ptr<RequestEvent> request = m_ven->requestEvent();

	auto& distributedEvent = request->response()->oadrSignedObject().oadrDistributeEvent();
	if (distributedEvent.present())
	{
		m_eventManager->manageEvents(distributedEvent.get());
	}
	else
	{
		// TODO: throw an exception or send response with non-200 code
	}
}

/********************************************************************************/

void VENManager::registerVen()
{
	// register as an HTTP pull VEN
	unique_ptr<CreatePartyRegistration> createPartyRegistration = m_ven->createPartyRegistration(oadrProfileType(oadrProfileType::cxx_2_0b),
			oadrTransportType(oadrTransportType::simpleHttp), "", false, false, true);

	oadrPayload *response = createPartyRegistration->response();

	if (response == NULL || !response->oadrSignedObject().oadrCreatedPartyRegistration().present())
	{
		// TODO: throw an exception
		return;
	}

	oadrCreatedPartyRegistrationType *cpr = &response->oadrSignedObject().oadrCreatedPartyRegistration().get();

	if (cpr->eiResponse().responseCode().compare("200") != 0)
	{
		// TODO: throw an exception
		return;
	}

	registerReports();

	poll();

	requestEvents();
}

/********************************************************************************/

void VENManager::registerVenState()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	while (!m_shutdown)
	{
		registerVen();

		if (m_ven->isRegistered())
			return;

		m_condition.wait_for(lock, m_registerRetryInterval);
	}
}

/********************************************************************************/

void VENManager::pollState()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	while (!m_shutdown)
	{
		poll();

		if (!m_ven->isRegistered())
			break;

		m_condition.wait_for(lock, seconds(m_ven->pollFrequencyInSeconds()));
	}
}

/********************************************************************************/

void VENManager::run()
{
	ThreadRunner schedulerThread(m_scheduler.get());

	schedulerThread.start();

	while (!m_shutdown)
	{
		try
		{
			if (!m_ven->isRegistered())
				registerVenState();
			else
				pollState();
		}
		catch (CurlException &ex)
		{
			m_exceptionService->OnCurlException(ex);
			exceptionWait();
		}
		catch (exception &ex)
		{
			m_exceptionService->OnException(ex);
			exceptionWait();
		}
	}
}

/********************************************************************************/

void VENManager::stop()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	m_shutdown = true;

	m_condition.notify_all();
}

/********************************************************************************/

Scheduler *VENManager::getScheduler()
{
	return m_scheduler.get();
}
