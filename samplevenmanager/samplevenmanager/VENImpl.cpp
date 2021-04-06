/*
 * VENImpl.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: dupes
 */

#include "VENImpl.h"

#include <iostream>

#include <oadr/request/report/ReportHelper.h>

#include <stdlib.h>

using namespace std;

namespace samplevenmanager
{

VENImpl::VENImpl(string venName, bool logToStdout)
{
	el::Configurations conf;


	conf.setGlobally(el::ConfigurationType::ToStandardOutput, (logToStdout ? "true" : "false"));

	conf.setGlobally(el::ConfigurationType::ToFile, "true");
	conf.setGlobally(el::ConfigurationType::Filename, "logs/" + venName + ".log");

	el::Loggers::reconfigureLogger("default", conf);
}

/********************************************************************************/

VENImpl::~VENImpl()
{
}

/********************************************************************************/

void VENImpl::OnPeriodicReportStart(const oadrReportRequestType& reportRequest)
{
	LOG(INFO) << " periodic report start";
}

/********************************************************************************/

void VENImpl::OnPeriodicReportComplete(
		const oadrReportRequestType& reportRequest)
{
	LOG(INFO) << " periodic report complete";
}

/********************************************************************************/

void VENImpl::OnGenerateOneshotReport(
		const oadrReportRequestType& reportRequest,
		oadrUpdateReportType::oadrReport_sequence &sequence)
{
	LOG(INFO) << " generate oneshot report";
}

/********************************************************************************/

void VENImpl::OnGeneratePeriodicReport(
		const oadrReportRequestType& reportRequest,
		oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
		unsigned int durationInSeconds)
{
	LOG(INFO) << "generate periodic report: " << reportRequest.reportRequestID();

	time_t dtend = dtstart - durationInSeconds;
	intervals::interval_sequence intervals;

	// find the nearest time_t that ends on the minute
	dtend = dtend + (60 - (dtend % 60));

	while (dtend <= dtstart)
	{
		IntervalType intervalType = ReportHelper::generateInterval(dtend, 1, &DurationModifier::MINUTES);

		// for each rid, add a payload to IntervalType
		for (auto &specifier : reportRequest.reportSpecifier().specifierPayload())
		{
			string rid = specifier.rID();

			float value = (float)(rand() % 10);

			oadrReportPayloadType payload = ReportHelper::generateOadrReportPayloadFloat(rid, value,
					oadr2b::oadr::oadrDataQualityType::Quality_Good___Non_Specific,
					1, 1);

			intervalType.streamPayloadBase().push_back(payload);
		}

		intervals.push_back(intervalType);

		// increment to the next minute
		dtend += 60;
	}

	if (intervals.size() > 0)
	{
		time_t now = time(NULL);

		oadrReportType report = ReportHelper::generateReport(&ReportName::TELEMETRY_USAGE, reportRequest.reportSpecifier().reportSpecifierID(),
				reportRequest.reportRequestID(), now, intervals);

		sequence.push_back(report);
	}
}

/********************************************************************************/

void VENImpl::OnGenerateHistoricalReport(
		const oadrReportRequestType& reportRequest,
		oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
		unsigned int durationInSeconds)
{
	LOG(INFO) << "generate historical report";
}

/********************************************************************************/

void VENImpl::OnGenerateRegisterReport(oadrRegisterReportType::oadrReport_sequence &sequence)
{
	LOG(INFO) << "register report";

	oadrReportType::oadrReportDescription_sequence description;

	// 1 minute energy interval
	oadrReportDescriptionType energy = ReportHelper::generateDescriptionEnergyItem("rid_energy_4184bb93", "DEVICE1", ReportEnumeratedType::reading,
			ReadingTypeEnumeratedType::Direct_Read, "", 1, 1, false, &DurationModifier::MINUTES,
			ReportHelper::eEnergyReal, "Wh", SiScaleCodeType::none);

	// 1 minute power interval
	oadrReportDescriptionType power = ReportHelper::generateDescriptionPowerItem("rid_power_4184bb93", "DEVICE1", ReportEnumeratedType::reading,
			ReadingTypeEnumeratedType::Direct_Read, "", 1, 1, false, &DurationModifier::MINUTES,
			ReportHelper::ePowerReal, "W", SiScaleCodeType::none, 60.0, 120, true);

	// ...
	// Create additional oadrReportDescriptionType objects...
	// ...

	// put each oadrReportDescriptionType into the description container
	description.push_back(energy);
	description.push_back(power);

	// create a report with the descriptions
	// there are two main report types: TELEMETRY_USAGE and HISTORY_USAGE
	// the structure of these report types is identical.  the only difference is how the reports can be used
	oadrReportType telemetryUsage = ReportHelper::generateReportDescription(&ReportName::TELEMETRY_USAGE, 120, &DurationModifier::MINUTES,
			"DEMO_TELEMETRY_USAGE", 0, description);

	// push the telemtry usage report onto the container
	// if there are additional reports (such as a history usage report), push those
	// reports as well.
	sequence.push_back(telemetryUsage);
}

/********************************************************************************/

void VENImpl::OnEventStart(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event, unsigned int remainingDurationInSeconds)
{
	LOG(INFO) << "event start: "  << eventID;
}

/********************************************************************************/

void VENImpl::OnEventComplete(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event)
{
	LOG(INFO) << "event complete: "  << eventID;
}

/********************************************************************************/

void VENImpl::OnEventIntervalStart(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event,
		const oadr2b::ei::eiEventSignalType* eventSignal, std::string uid,
		float payload, time_t dtstart, unsigned int remainingDurationInSeconds)
{
	LOG(INFO) << "event interval start: " << eventID << payload << " " << remainingDurationInSeconds;
}

/********************************************************************************/

void VENImpl::OnEventNew(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event, oadr2b::ei::OptTypeType::value &optType)
{
	LOG(INFO) << "new event received: " << eventID;
}

/********************************************************************************/

void VENImpl::OnEventNew(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event)
{
	LOG(INFO) << "new event received: " << eventID << " (no response expected)";
}

/********************************************************************************/

void VENImpl::OnEventModify(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* newEvent,
		const oadr2b::oadr::oadrEvent* oldEvent, oadr2b::ei::OptTypeType::value &optType)
{
	LOG(INFO) << "event modified: " << eventID;
}

/********************************************************************************/

void VENImpl::OnEventModify(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* newEvent,
		const oadr2b::oadr::oadrEvent* oldEvent)
{
	LOG(INFO) << "event modified: " << eventID << " (no response expected)";
}

/********************************************************************************/

void VENImpl::OnEventCancel(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event, oadr2b::ei::OptTypeType::value &optType)
{
	LOG(INFO) << "event cancelled: " << eventID;
}

/********************************************************************************/

void VENImpl::OnEventCancel(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event)
{
	LOG(INFO) << "event cancelled: " << eventID;
}

/********************************************************************************/

void VENImpl::OnEventImplicitCancel(const std::string& eventID,
		const oadr2b::oadr::oadrEvent* event)
{
	LOG(INFO) << "event imiplicitly cancelled: " << eventID;
}

/********************************************************************************/

void VENImpl::OnOadrMessageReceived(std::string &message)
{
	LOG(INFO) << "\nVEN <--- VTN\n" << message << "\n=================================\n";
}

/********************************************************************************/

void VENImpl::OnOadrMessageSent(std::string &message)
{
	LOG(INFO) << "\nVEN ---> VTN\n" << message << "\n=================================\n";
}

/********************************************************************************/

void VENImpl::OnCurlException(CurlException &ex)
{
	LOG(ERROR) << "curl exception : " << ex.what();
}

/********************************************************************************/

void VENImpl::VENImpl::OnException(std::exception &ex)
{
	LOG(ERROR) << "std exception : " << ex.what();
}

} /* namespace samplevenmanager */

