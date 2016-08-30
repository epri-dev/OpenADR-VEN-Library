/*
 * MockSleepTimer.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#include "MockConditionalSleep.h"

MockConditionalSleep::MockConditionalSleep(MockGlobalTime *globalTime) :
	m_globalTime(globalTime),
	m_timeoutOccurred(true),
	m_waitUntilTime(0)
{
}

/********************************************************************************/

MockConditionalSleep::~MockConditionalSleep()
{
}

/********************************************************************************/

bool MockConditionalSleep::waitUntil(std::unique_lock<std::mutex> &lock, time_t t)
{
	m_waitUntilTime = t;

	if (m_globalTime != NULL)
		m_globalTime->setNow(t);

	return m_timeoutOccurred;
}

/********************************************************************************/

bool MockConditionalSleep::waitFor(std::unique_lock<std::mutex> &lock, std::chrono::seconds s)
{
	if (m_globalTime != NULL)
		m_globalTime->setNow(m_globalTime->now() + s.count());

	return m_timeoutOccurred;
}

/********************************************************************************/

void MockConditionalSleep::notifyOne()
{

}

/********************************************************************************/

void MockConditionalSleep::notifyAll()
{

}

/********************************************************************************/

void MockConditionalSleep::setTimeoutOccurred(bool timeoutOccurred)
{
	m_timeoutOccurred = timeoutOccurred;
}

/********************************************************************************/

time_t MockConditionalSleep::getWaitUntilTime()
{
	return m_waitUntilTime;
}
