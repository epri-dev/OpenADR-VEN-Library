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
	unique_ptr<VEN2b> m_ven;
	unique_ptr<Scheduler> m_scheduler;
	unique_ptr<EventManager> m_eventManager;
	unique_ptr<ReportManager> m_reportManager;

	IReportService *m_reportService;

	IOADRExceptionService *m_exceptionService;

    condition_variable m_condition;
    mutex m_mutex;

	bool m_shutdown;

	virtual void sendCreatedEvent(string responseCode, string responseDescription, string requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses);

	virtual void sendUpdateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, string reportRequestID, time_t createdDateTime);
	virtual void sendCreatedReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription);
	virtual void sendCanceledReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription);

	VENManager(unique_ptr<VEN2b> ven, IEventService *eventService, IReportService *reportService, IOADRExceptionService *exceptionService);

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
