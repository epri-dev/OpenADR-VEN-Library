/*
 * BlankReportService.cpp
 *
 *  Created on: Jul 6, 2015
 *      Author: dupes
 */

#include "BlankReportService.h"

BlankReportService::BlankReportService()
{
	OneshotReportCount = 0;
	PeriodicReportCount = 0;
	HistoricalReportCount = 0;

	PeriodicReportStartCount = 0;
	PeriodicReportCompleteCount = 0;
}

/********************************************************************************/

BlankReportService::~BlankReportService()
{
}

/********************************************************************************/

void BlankReportService::OnPeriodicReportStart(const oadrReportRequestType &reportRequest)
{
	PeriodicReportStartCount++;
}

/********************************************************************************/

void BlankReportService::OnPeriodicReportComplete(const oadrReportRequestType &reportRequest)
{
	PeriodicReportCompleteCount++;
}

/********************************************************************************/

void BlankReportService::OnGenerateOneshotReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence)
{
	OneshotReportCount++;
}

/********************************************************************************/

void BlankReportService::OnGeneratePeriodicReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
		unsigned int durationInSeconds)
{
	PeriodicReportCount++;
}

/********************************************************************************/

void BlankReportService::OnGenerateHistoricalReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
		unsigned int durationInSeconds)
{
	HistoricalReportCount++;
}

/********************************************************************************/

void BlankReportService::OnGenerateRegisterReport(oadrRegisterReportType::oadrReport_sequence &sequence)
{
}
