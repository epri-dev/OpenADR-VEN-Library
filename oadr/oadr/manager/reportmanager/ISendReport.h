/*
 * ISendReport.h
 *
 *  Created on: Sep 15, 2014
 *      Author: dupes
 */

#ifndef ISENDREPORT_H_
#define ISENDREPORT_H_

#include <oadrsd/2b/oadrUpdateReportType.hxx>

#include <set>
#include <string>

using namespace std;

using namespace oadr2b::oadr;

class ISendReport
{
public:
	virtual ~ISendReport() = default;

	virtual void sendUpdateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, string reportRequestID, time_t createdDateTime) = 0;

	virtual void sendCreatedReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription) = 0;

	virtual void sendCanceledReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription) = 0;
};

#endif /* ISENDREPORT_H_ */
