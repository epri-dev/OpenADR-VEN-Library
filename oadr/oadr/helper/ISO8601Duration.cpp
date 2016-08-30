//*********************************************************************************************************************
// ISO8601Duration.cpp
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

#include "ISO8601Duration.h"
#include <cstdlib>

using namespace std;

ISO8601Duration::ISO8601Duration() :
	m_Years(0),
	m_Months(0),
	m_Days(0),
	m_Hours(0),
	m_Minutes(0),
	m_Seconds(0)
{
}

/********************************************************************************/

ISO8601Duration::~ISO8601Duration()
{
}

/********************************************************************************/

bool ISO8601Duration::parse(string duration){

	char* p;
	char c;
	int timeFlag = 0;		//Flag thrown when encountering T in string
	int monthFlag = 0;
	int dayFlag = 0;
	int hourFlag = 0;
	int minuteFlag = 0;
	int secondFlag = 0;
	double decimalBuffer = 0;

	//Reset all variables
	m_Years = 0;
	m_Months = 0;
	m_Days = 0;
	m_Hours = 0;
	m_Minutes = 0;
	m_Seconds = 0;

	//Sets p to beginning of the string
	p = &duration[0];

	//Loop through the string and parse the time units
	c = *p;

	if(c != 'P') {
		return false;
	}

	//Test if P is last character in string
	p++;

	if(*p == '\0')
		return false;

	c = *p;

	while (c != '\0')
	{

		//Set flag so 'M' after this point means minutes
		if(c == 'T')
		{
			timeFlag = 1;

			if (hourFlag == 1 || minuteFlag == 1 || secondFlag == 1)
				return false;

			// if T is the end of the string, the string is invalid
			if (*(p + 1) == '\0')
				return false;
		}
		else
		{

			char *pNew = p;

			//Store the decimal, move p to after decimal
			decimalBuffer = strtod(p, &pNew);

			//If the end of string is reached now, there wasn't a number, character pair
			if(*pNew == '\0')
				return false;

			//strtod did not find a decimal
			if(pNew == p)
			{
				return false;
			}

			//Get the next char
			c = *pNew;

			p = pNew;

			//Assign d to proper variable according to c's value
			if(c == 'Y')
			{
				m_Years = decimalBuffer;

				if (timeFlag == 1 || hourFlag == 1 || minuteFlag == 1 || secondFlag == 1 || monthFlag == 1 || dayFlag == 1)
					return false;


			}
			else if (c == 'M' && timeFlag == 0)
			{
				m_Months = decimalBuffer;

				if (monthFlag == 1 || hourFlag == 1 || minuteFlag == 1 || secondFlag == 1 || dayFlag == 1)
					return false;

				monthFlag = 1;
			}
			else if (c == 'M' && timeFlag == 1)
			{
				m_Minutes = decimalBuffer;

				if (secondFlag == 1 || minuteFlag == 1)
					return false;

				minuteFlag = 1;
			}
			else if(c == 'D')
			{
				m_Days = decimalBuffer;

				if (dayFlag == 1 || timeFlag == 1 || hourFlag == 1 || minuteFlag == 1 || secondFlag == 1)
					return false;

				dayFlag = 1;
			}
			else if(c == 'H')
			{
				m_Hours = decimalBuffer;

				if (hourFlag == 1 || minuteFlag == 1 || secondFlag == 1)
						return false;

				hourFlag = 1;
			}
			else if (c == 'S')
			{
				m_Seconds = decimalBuffer;

				if(secondFlag == 1)
					return false;

				secondFlag = 1;
			}
			else if (c == '\0')
			{
				continue;
			}
			else
			{
				return false;
			}


		}

		//Advance pointer
		p++;
		c = *p;

	}

	return true;
}

/********************************************************************************/

//The following return their respective variables
double ISO8601Duration::getYears()
{
	return m_Years;
}

/********************************************************************************/

double ISO8601Duration::getMonths()
{
	return m_Months;
}

/********************************************************************************/

double ISO8601Duration::getDays()
{
	return m_Days;
}

/********************************************************************************/

double ISO8601Duration::getHours()
{
	return m_Hours;
}

/********************************************************************************/

double ISO8601Duration::getMinutes()
{
	return m_Minutes;
}

/********************************************************************************/

double ISO8601Duration::getSeconds()
{
	return m_Seconds;
}

/********************************************************************************/
//The following functions assume exactly 365 days per year and 30 days per month

double ISO8601Duration::getTotalSeconds()
{
	return (m_Years * 31536000) + (m_Months * 2592000) + (m_Days * 86400) + (m_Hours * 3600) + (m_Minutes * 60) + m_Seconds;
}

/********************************************************************************/

double ISO8601Duration::getTotalMinutes()
{
	return (m_Years * 525600) + (m_Months * 4320) + (m_Days * 1440) + (m_Hours * 60) + (m_Minutes * 1) + (m_Seconds / 60 );
}

/********************************************************************************/

double ISO8601Duration::getTotalHours()
{
	return (m_Years * 8760) + (m_Months * 720) + (m_Days * 24) + (m_Hours * 1) + (m_Minutes / 60) + (m_Seconds / 3600 );
}

/********************************************************************************/

unsigned int ISO8601Duration::TotalSeconds(string duration)
{
	ISO8601Duration d;

	if (!d.parse(duration))
		throw runtime_error("ISO8601Duration::TotalSeconds : failed to parse duration");

	return d.getTotalSeconds();
}
