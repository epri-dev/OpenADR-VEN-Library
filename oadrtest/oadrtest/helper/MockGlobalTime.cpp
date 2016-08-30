/*
 * MockGlobalTime.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#include "MockGlobalTime.h"

#include <string.h>

MockGlobalTime::MockGlobalTime() :
	m_now(0)
{
	GlobalTime::SetGlobalTime(this);
}

/********************************************************************************/

MockGlobalTime::~MockGlobalTime()
{
	GlobalTime::SetDefaultGlobalTime();
}

/********************************************************************************/

time_t MockGlobalTime::now()
{
	return m_now;
}

/********************************************************************************/

void MockGlobalTime::setNow(time_t now)
{
	m_now = now;
}

/********************************************************************************/

void MockGlobalTime::setNow(int year, int month, int day, int hours, int minutes, int seconds)
{
	tm t;

	memset(&t, 0, sizeof(t));

	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_hour = hours;
	t.tm_min = minutes;
	t.tm_sec = seconds;

	m_now = mktime(&t);
}
