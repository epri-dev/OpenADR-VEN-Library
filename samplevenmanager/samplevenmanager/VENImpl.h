/*
 * VENImpl.h
 *
 *  Created on: Jul 8, 2015
 *      Author: dupes
 */

#ifndef SAMPLEVENMANAGER_SAMPLEVENMANAGER_VENIMPL_H_
#define SAMPLEVENMANAGER_SAMPLEVENMANAGER_VENIMPL_H_

#include <oadr/manager/eventmanager/IEventService.h>
#include <oadr/manager/reportmanager/IReportService.h>

#include <oadr/ven/IOadrMessage.h>

#include <oadr/manager/IOADRExceptionService.h>

#include "easylogging++.h"

namespace samplevenmanager
{

class VENImpl : public IEventService, public IReportService, public IOadrMessage, public IOADRExceptionService
{

public:
	VENImpl(string venName, bool logToStdout);
	virtual ~VENImpl();

	virtual void OnPeriodicReportStart(const oadrReportRequestType &reportRequest);

	virtual void OnPeriodicReportComplete(const oadrReportRequestType &reportRequest);

	virtual void OnGenerateOneshotReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence);

	virtual void OnGeneratePeriodicReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
			unsigned int durationInSeconds);

	virtual void OnGenerateHistoricalReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
			unsigned int durationInSeconds);

	virtual void OnGenerateRegisterReport(oadrRegisterReportType::oadrReport_sequence &sequence);

	virtual void OnEventStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, unsigned int remainingDurationInSeconds);
	virtual void OnEventComplete(const std::string &eventID, const oadr2b::oadr::oadrEvent *event);
	virtual void OnEventIntervalStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, std::string uid, float payload, time_t dtstart, unsigned int remainingDurationInSeconds);

	virtual void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType);
	virtual void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent, oadr2b::ei::OptTypeType::value &optType);
	virtual void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType);
	virtual void OnEventImplicitCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event);

	virtual void OnProcessDistributeEventStart();
	virtual void OnGenerateCreatedEvent(oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses);
	virtual void OnProcessDistributeEventComplete();

	virtual void OnOadrMessageReceived(std::string &message);
	virtual void OnOadrMessageSent(std::string &message);

	virtual void OnCurlException(CurlException &ex);
	virtual void OnException(std::exception &ex);
};

} /* namespace samplevenmanager */

#endif /* SAMPLEVENMANAGER_SAMPLEVENMANAGER_VENIMPL_H_ */
