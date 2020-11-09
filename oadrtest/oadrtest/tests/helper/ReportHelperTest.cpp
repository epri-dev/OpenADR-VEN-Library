//*********************************************************************************************************************
// ReportHelperTest.cpp
//
// Copyright (c) 2013 ELECTRIC POWER RESEARCH INSTITUTE, INC. All rights reserved.
//
// OpenADR ("this software") is licensed under BSD 3-Clause license.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
// following conditions are met:
//
// *    Redistributions of source code must retain the above copyright  notice, this list of conditions and
//      the following disclaimer.
//
// *    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
//      the following disclaimer in the documentation and/or other materials provided with the distribution.
//
// *    Neither the name of the Electric Power Research Institute, Inc. ("EPRI") nor the names of its contributors
//      may be used to endorse or promote products derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL EPRI BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include <oadr/request/report/ReportHelper.h>
#include <oadr/request/report/UpdateReport.h>

#include <oadrsd/2b/oadrPayload.hxx>
#include <oadrsd/2b/oadr_20b.hxx>

#include <string>

#include "../../helper/LoadFile.h"

#include <xercesc/util/PlatformUtils.hpp>

#include <xsd/cxx/tree/elements.hxx>

#include <oadr/request/report/ReportHelper.h>

#include <oadr/request/report/RegisterReport.h>

#include <oadrsd/2b/DateTimeType.hxx>

#include <oadr/helper/DateTimeConverter.h>

#include <time.h>

using namespace icalendar_2_0;
using namespace xml_schema;

using namespace oadr2b::oadr;

using namespace XERCES_CPP_NAMESPACE;

/********************************************************************************/

TEST(ReportHelperTest, GenerateReport)
{
	intervals::interval_sequence intervals;

	time_t now = 1436828340;

	intervals.push_back(ReportHelper::generateInterval(now, 10, &DurationModifier::SECONDS));

	oadrReportPayloadType payload = ReportHelper::generateOadrReportPayloadFloat("rid", 102.2, oadrDataQualityType::Quality_Good___Non_Specific,
			1, 1);

	intervals.back().streamPayloadBase().push_back(payload);

	oadrReportPayloadType status = ReportHelper::generateOadrReportPayloadResourceStatus("rid2", true, false, oadrDataQualityType::Quality_Good___Non_Specific,
			1.0, 1.0);

	intervals.back().streamPayloadBase().push_back(status);

	oadrReportType report = ReportHelper::generateReport(&ReportName::TELEMETRY_USAGE, "reportSpecifierID",
			"reportRequestID", now, intervals);

	oadrUpdateReportType::oadrReport_sequence sequence;

	sequence.push_back(report);

	UpdateReport ur("venID", "requestID", sequence, now, "reportRequestID", now);

	std::string output = ur.generateRequestXML();

	// cout << output << std::endl;

	std::string expectedOutput = LoadFile::loadExpectedOutputFile("UpdateReport_XMLOutput1.xml");

	ASSERT_EQ(expectedOutput, output);
}

/********************************************************************************/

TEST(ReportHelperTest, GenerateReportDescription)
{
	oadrReportType::oadrReportDescription_sequence sequence;

	// time_t now = 1406066761;
	// 2014-07-22T22:06:01Z

	icalendar_2_0::dtstart::date_time_type dt(DateTimeType(date_time(2014, 07, 22, 22, 06, 01, 0, 0)));

	time_t now = DateTimeConverter::DateTimeToTime_t(dt);

	XMLPlatformUtils::Initialize();

	//
	// generate the report description for the telemetry usage report
	//
	oadrReportDescriptionType energy = ReportHelper::generateDescriptionEnergyItem("rid1", "resourceID1", ReportEnumeratedType::reading,
			ReadingTypeEnumeratedType::Direct_Read, "http://MarketContext1", 5, 5, false, &DurationModifier::MINUTES,
			ReportHelper::eEnergyReal, "kWh", SiScaleCodeType::none);


	oadrReportDescriptionType power = ReportHelper::generateDescriptionPowerItem("rid2", "resourceID1", ReportEnumeratedType::reading,
			ReadingTypeEnumeratedType::Direct_Read, "http://MarketContext1", 5, 5, false, &DurationModifier::MINUTES,
			ReportHelper::ePowerReal, "kW", SiScaleCodeType::none, 60.0, 120, true);

	oadrReportDescriptionType custom = ReportHelper::generateDescriptionCustom("rid3", "resourceID1", ReportEnumeratedType::reading,
			ReadingTypeEnumeratedType::Direct_Read, "http://MarketContext1", 5, 5, false, &DurationModifier::MINUTES,
			"desc", "units", SiScaleCodeType::none);

	oadrReportDescriptionType temp = ReportHelper::generateDescriptionTemperature("rid4", "resourceID1", ReportEnumeratedType::reading,
			ReadingTypeEnumeratedType::Direct_Read, "http://MarketConext1", 5, 5, false, &DurationModifier::MINUTES,
			temperatureUnitType::celsius, SiScaleCodeType::none);

	sequence.push_back(energy);
	sequence.push_back(power);
	sequence.push_back(custom);
	sequence.push_back(temp);

	oadrReportType telemetryUsage = ReportHelper::generateReportDescription(&ReportName::TELEMETRY_USAGE, 120, &DurationModifier::MINUTES,
			"1234", now, sequence);


	//
	// generate the report description for the telemetry status report
	//
	oadrReportDescriptionType status = ReportHelper::generateDescriptionResourceStatus("rid3", "resoruceID1", "http://MarketContext1",
			5, 5, false, &DurationModifier::MINUTES);

	sequence.clear();

	sequence.push_back(status);

	oadrReportType telemetryStatus = ReportHelper::generateReportDescription(&ReportName::TELEMETRY_STATUS, 120, &DurationModifier::MINUTES,
			"5678", now, sequence);

	oadrRegisterReportType::oadrReport_sequence reports;

	reports.push_back(telemetryUsage);
	reports.push_back(telemetryStatus);

	// string venID, string requestID, oadrRegisterReportType::oadrReport_sequence sequence
	RegisterReport registreReport("venID", "requestID", reports);

	std::string output = registreReport.generateRequestXML();
	std::string expectedOutput = LoadFile::loadExpectedOutputFile("RegisterReport_XMLOutput1.xml");

	// cout << output << endl;

	ASSERT_EQ(expectedOutput, output);

	XMLPlatformUtils::Terminate();
}
