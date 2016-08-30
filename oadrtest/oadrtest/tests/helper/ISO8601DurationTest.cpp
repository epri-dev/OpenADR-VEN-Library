//*********************************************************************************************************************
// ISO8601DurationTest.cpp
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

#include <oadr/helper/ISO8601Duration.h>

/**
 * validate ISO8601 string parsing
 */

/********************************************************************************/

TEST(ISO8601DurationTest, ParseDuration) {

	ISO8601Duration duration;

	// validate getMinutes and getTotalMinutes==10 and other get*== 0
	EXPECT_TRUE(duration.parse("PT2H5M10S"));
	EXPECT_EQ(0.0, duration.getYears());
	EXPECT_EQ(0.0, duration.getMonths());
	EXPECT_EQ(0.0, duration.getDays());
	EXPECT_EQ(2.0, duration.getHours());
	EXPECT_EQ(5.0, duration.getMinutes());
	EXPECT_EQ(10.0, duration.getSeconds());
	EXPECT_EQ(7510.0, duration.getTotalSeconds());

	EXPECT_TRUE(duration.parse("PT5M1S"));
	EXPECT_EQ(5.0, duration.getMinutes());
	EXPECT_EQ(1.0, duration.getSeconds());
	EXPECT_EQ(301.0, duration.getTotalSeconds());


	EXPECT_TRUE(duration.parse("PT5.03M"));
	EXPECT_EQ(5.03, duration.getMinutes());

	EXPECT_TRUE(duration.parse("P5Y2MT3M"));
	EXPECT_EQ(5, duration.getYears());
	EXPECT_EQ(2, duration.getMonths());
	EXPECT_EQ(3, duration.getMinutes());
}

/********************************************************************************/

TEST(ISO8601DurationTest, ParseBadStrings) {

	ISO8601Duration duration;

	EXPECT_FALSE(duration.parse("BADSTRING"));
	EXPECT_FALSE(duration.parse(""));
	EXPECT_FALSE(duration.parse("\n"));

}

/********************************************************************************/

TEST(ISO8601DurationTest, CompleteCorrectReturn) {

	ISO8601Duration duration;

	EXPECT_TRUE(duration.parse("P1Y2M3DT4H5M6S"));

	EXPECT_EQ(1, duration.getYears());
	EXPECT_EQ(2, duration.getMonths());
	EXPECT_EQ(3, duration.getDays());
	EXPECT_EQ(4, duration.getHours());
	EXPECT_EQ(5, duration.getMinutes());
	EXPECT_EQ(6, duration.getSeconds());

}

/********************************************************************************/

TEST(ISO8601DurationTest, NegativeTests) {

	ISO8601Duration duration;

	EXPECT_FALSE(duration.parse("PT5S2M"));

	EXPECT_FALSE(duration.parse("T5M"));

	EXPECT_FALSE(duration.parse("TP5M"));

	EXPECT_FALSE(duration.parse("PTM"));

	EXPECT_FALSE(duration.parse("PTS"));

	EXPECT_FALSE(duration.parse("PT"));

	EXPECT_FALSE(duration.parse("P"));

	EXPECT_FALSE(duration.parse("P5YTS"));

	EXPECT_FALSE(duration.parse("P5Y2M3"));

	EXPECT_FALSE(duration.parse("P5Y2M4M"));

	EXPECT_FALSE(duration.parse("P5Y2MT"));

	EXPECT_FALSE(duration.parse("5Y"));

	EXPECT_FALSE(duration.parse("T5Y2M"));

	EXPECT_FALSE(duration.parse("P5Y2MP"));

	EXPECT_FALSE(duration.parse("P2M5Y"));

	EXPECT_FALSE(duration.parse("P3"));

	EXPECT_FALSE(duration.parse("P3T5S"));
}
