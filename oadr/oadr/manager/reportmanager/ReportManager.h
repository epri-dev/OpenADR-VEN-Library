/*
 * ReportManager.h
 *
 *  Created on: Mar 11, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_REPORT_REPORTMANAGER_H_
#define OADR_OADR_VEN_VENMANAGER_REPORT_REPORTMANAGER_H_

#include "../../scheduler/IScheduler.h"
#include "../../scheduler/JobLambda.h"

#include "IReportService.h"
#include "RegisteredReports.h"

#include "ISendReport.h"

#include <string>
#include <map>

#include <oadrsd/2b/ReportSpecifierType.hxx>
#include <oadrsd/2b/SpecifierPayloadType.hxx>
#include <oadrsd/2b/oadrReportRequestType.hxx>
#include <oadrsd/2b/oadrRegisterReportType.hxx>
#include <oadrsd/2b/oadrCreateReportType.hxx>
#include <oadrsd/2b/oadrCancelReportType.hxx>

using namespace oadr2b::oadr;
using namespace std;

class ReportManager
{
private:
	const static string C_REPORT;
	const static string C_UPDATE;
	const static string C_COMPLETE;

	IScheduler *m_scheduler;
	IReportService *m_service;

	ISendReport *m_sendReport;

	RegisteredReports m_registeredReports;

	set<string> m_pendingReports;

	map<string, unique_ptr<oadrReportRequestType>> m_periodicReports;

	bool validateCreateReport(oadrCreateReportType &createReport);

	void processReportRequest(oadrReportRequestType &reportRequest);

	void processCancelReport(string reportRequestID, bool reportToFollow);

public:
	ReportManager(IScheduler *scheduler, IReportService *service, ISendReport *sendReport);
	virtual ~ReportManager();

	void generatePeriodicReport(string reportRequestID, time_t now, bool finalReport);

	void setRegisteredReports(oadrRegisterReportType::oadrReport_sequence &sequence);

	void manageCreateReport(oadrCreateReportType &createReport);

	void manageCancelReport(oadrCancelReportType &cancelReport);

	set<string> &getPendingReports();
	map<string, unique_ptr<oadrReportRequestType>> &getPeriodicReports();

	static string buildJobID(string reportRequestID);
};

#endif /* OADR_OADR_VEN_VENMANAGER_REPORT_REPORTMANAGER_H_ */
