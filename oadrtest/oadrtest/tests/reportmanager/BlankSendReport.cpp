/*
 * BlankSendReport.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: dupes
 */

#include "BlankSendReport.h"

BlankSendReport::BlankSendReport()
{
	SendUpdateReportCount = 0;
	SendCreatedReportCount = 0;
	PendingReportSize = 0;
	SendCanceledReportCount = 0;
}

/********************************************************************************/

BlankSendReport::~BlankSendReport()
{
}

/********************************************************************************/

void BlankSendReport::sendUpdateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, string reportRequestID, time_t createdDateTime)
{
	SendUpdateReportCount++;
}

/********************************************************************************/

void BlankSendReport::sendCreatedReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription)
{
	ResponseCode = responseCode;
	ResponseDescription = responseDescription;

	PendingReportSize = pendingReports.size();

	SendCreatedReportCount++;
}

/********************************************************************************/

void BlankSendReport::sendCanceledReport(const set<string> &pendingReports, string requestID, string responseCode, string responseDescription)
{
	SendCanceledReportCount++;
}
