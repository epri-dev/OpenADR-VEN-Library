/*
 * SleepTimer.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#include "ConditionalSleep.h"

ConditionalSleep::ConditionalSleep()
{
}

/********************************************************************************/

ConditionalSleep::~ConditionalSleep()
{
}

/********************************************************************************/

bool ConditionalSleep::waitUntil(std::unique_lock<std::mutex> &lock, time_t t)
{
	if (m_condition.wait_until(lock, chrono::system_clock::from_time_t(t)) == std::cv_status::timeout)
		return true;

	return false;
}

/********************************************************************************/

bool ConditionalSleep::waitFor(std::unique_lock<std::mutex> &lock, std::chrono::seconds s)
{
	if (m_condition.wait_for(lock, s) == std::cv_status::timeout)
		return true;

	return false;
}

/********************************************************************************/

void ConditionalSleep::notifyOne()
{
	m_condition.notify_one();
}

/********************************************************************************/

void ConditionalSleep::notifyAll()
{
	m_condition.notify_all();
}
