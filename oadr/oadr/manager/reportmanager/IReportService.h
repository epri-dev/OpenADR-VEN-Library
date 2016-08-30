/*
 * IReportService.h
 *
 *  Created on: Sep 10, 2014
 *      Author: dupes
 */

#ifndef IREPORTSERVICE_H_
#define IREPORTSERVICE_H_

#include <oadrsd/2b/ReportSpecifierType.hxx>
#include <oadrsd/2b/SpecifierPayloadType.hxx>
#include <oadrsd/2b/oadrReportRequestType.hxx>
#include <oadrsd/2b/oadrUpdateReportType.hxx>
#include <oadrsd/2b/oadrRegisterReportType.hxx>

using namespace oadr2b::oadr;
using namespace std;

class IReportService
{
public:
	IReportService();
	virtual ~IReportService();

	virtual void OnPeriodicReportStart(const oadrReportRequestType &reportRequest) = 0;

	virtual void OnPeriodicReportComplete(const oadrReportRequestType &reportRequest) = 0;

	virtual void OnGenerateOneshotReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence) = 0;

	virtual void OnGeneratePeriodicReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
			unsigned int durationInSeconds) = 0;

	virtual void OnGenerateHistoricalReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
			unsigned int durationInSeconds) = 0;

	virtual void OnGenerateRegisterReport(oadrRegisterReportType::oadrReport_sequence &sequence) = 0;
};

#endif /* IREPORTSERVICE_H_ */
