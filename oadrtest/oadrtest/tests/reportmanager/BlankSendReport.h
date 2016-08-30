/*
 * BlankSendReport.h
 *
 *  Created on: Jul 6, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_REPORTMANAGER_BLANKSENDREPORT_H_
#define OADRTEST_OADRTEST_TESTS_REPORTMANAGER_BLANKSENDREPORT_H_

#include <oadr/manager/reportmanager/ISendReport.h>

class BlankSendReport : public ISendReport
{
public:
	BlankSendReport();
	virtual ~BlankSendReport();

	virtual void sendUpdateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, string reportRequestID, time_t createdDateTime);

	virtual void sendCreatedReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription);

	virtual void sendCanceledReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription);

	unsigned int SendUpdateReportCount;
	unsigned int SendCreatedReportCount;
	unsigned int SendCanceledReportCount;

	unsigned int PendingReportSize;

	string ResponseCode;
	string ResponseDescription;
};

#endif /* OADRTEST_OADRTEST_TESTS_REPORTMANAGER_BLANKSENDREPORT_H_ */
