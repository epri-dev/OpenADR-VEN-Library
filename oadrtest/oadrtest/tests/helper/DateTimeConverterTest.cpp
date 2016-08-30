//*********************************************************************************************************************
// DateTimeConverterTest.cpp
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
#include <gtest/gtest.h>

#include <oadr/helper/DateTimeConverter.h>

#include <oadrsd/2b/DateTimeType.hxx>

using namespace icalendar_2_0;
using namespace xml_schema;

/********************************************************************************/

TEST(DateTimeConverterTest, ConvertToTime_t)
{
	char buffer[256];

	icalendar_2_0::dtstart::date_time_type dt(DateTimeType(date_time(2015, 06, 22, 6, 44, 0)));

	Timezone tz;

	// Set the timezone to central to ensure these tests run the same on any computer regardless of timezone
	tz.StoreEnvTZ();
	tz.SetTimezone("US/Central");

	time_t t = DateTimeConverter::DateTimeToTime_t(dt);
	strftime(buffer, 256, "%a %b %d %H:%M:%S %Y %Z", localtime(&t));
	EXPECT_STREQ("Mon Jun 22 01:44:00 2015 CDT", buffer);

	dt = DateTimeType(date_time(2015, 1, 1, 6, 44, 0));

	t = DateTimeConverter::DateTimeToTime_t(dt);
	strftime(buffer, 256, "%a %b %d %H:%M:%S %Y %Z", localtime(&t));
	EXPECT_STREQ("Thu Jan 01 00:44:00 2015 CST", buffer);

	//
	// Convert back to date_time
	//
	icalendar_2_0::dtstart::date_time_type dt2 = DateTimeConverter::Time_tToDateTime(t);

	EXPECT_EQ(dt.year(), dt2.year());
	EXPECT_EQ(dt.month(), dt2.month());
	EXPECT_EQ(dt.day(), dt2.day());
	EXPECT_EQ(dt.hours(), dt2.hours());
	EXPECT_EQ(dt.minutes(), dt2.minutes());
	EXPECT_EQ(dt.seconds(), dt2.seconds());

	tz.RestoreEnvTZ();
}


