/*
 * VENManager.h
 *
 *  Created on: Sep 15, 2014
 *      Author: dupes
 */

#ifndef VENMANAGER_H_
#define VENMANAGER_H_

#include "VENManagerConfig.h"

#include "../ven/VEN2b.h"
#include "../ven/http/HttpCurl.h"

#include "../request/report/ReportHelper.h"

#include "../helper/RandomHex.h"
#include "../helper/thread/IRun.h"
#include "../helper/thread/ThreadRunner.h"

#include "eventmanager/EventManager.h"
#include "reportmanager/ReportManager.h"
#include "reportmanager/ISendReport.h"

#include "../scheduler/Scheduler.h"

#include "IVENManager.h"
#include "IOADRExceptionService.h"

#include <thread>
#include <condition_variable>
#include <mutex>

class VENManager : public ISendCreatedEvent, public ISendReport, public IVENManager
{
private:
	std::unique_ptr<VEN2b> m_ven;
	std::unique_ptr<Scheduler> m_scheduler;
	std::unique_ptr<EventManager> m_eventManager;
	std::unique_ptr<ReportManager> m_reportManager;

	IReportService *m_reportService;

	IOADRExceptionService *m_exceptionService;

    std::condition_variable m_condition;
    std::mutex m_mutex;
    std::chrono::seconds m_registerRetryInterval;

	bool m_shutdown;

	virtual void sendCreatedEvent(std::string responseCode, std::string responseDescription, std::string requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses);

	virtual void sendUpdateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, std::string reportRequestID, time_t createdDateTime);
	virtual void sendCreatedReport(const std::set<std::string> &pendingReports, std::string requestID, std::string responseCode, std::string responseDescription);
	virtual void sendCanceledReport(const std::set<std::string> &pendingReports, std::string requestID, std::string responseCode, std::string responseDescription);

	VENManager(std::unique_ptr<VEN2b> ven, IEventService *eventService, IReportService *reportService, IOADRExceptionService *exceptionService, std::chrono::seconds registerRetryInterval);

	void exceptionWait();

	void poll();

	void registerReports();

	void requestEvents();

	void registerVen();

	void registerVenState();

	void pollState();

public:

	virtual ~VENManager();

	static IVENManager *init(VENManagerConfig &config);

	virtual void run();

	virtual void stop();

	Scheduler *getScheduler();
};

#endif /* VENMANAGER_H_ */
