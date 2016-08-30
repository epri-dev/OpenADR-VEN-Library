/*
 * MockGlobalIncrementingTime.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: dupes
 */

#include "MockGlobalIncrementingTime.h"

MockGlobalIncrementingTime::MockGlobalIncrementingTime()
{
	m_now = 0;
	m_offset = 0;
}

/********************************************************************************/

MockGlobalIncrementingTime::~MockGlobalIncrementingTime()
{
}

/********************************************************************************/

time_t MockGlobalIncrementingTime::now()
{
	return time(NULL) + m_offset;
}

/********************************************************************************/

void MockGlobalIncrementingTime::setNow(time_t now)
{
	m_now = now;

	m_offset = m_now - time(NULL);
}
