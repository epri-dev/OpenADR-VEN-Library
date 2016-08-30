/*
 * MockSleepTimer.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_SCHEDULER_MOCKCONDITIONALSLEEP_H_
#define OADRTEST_OADRTEST_TESTS_SCHEDULER_MOCKCONDITIONALSLEEP_H_

#include <oadr/helper/conditionalsleep/IConditionalSleep.h>

#include "../../helper/MockGlobalTime.h"

class MockConditionalSleep : public IConditionalSleep
{
private:
	MockGlobalTime *m_globalTime;

	bool m_timeoutOccurred;

	time_t m_waitUntilTime;

public:
	MockConditionalSleep(MockGlobalTime *globalTime = NULL);
	virtual ~MockConditionalSleep();

	virtual bool waitUntil(std::unique_lock<std::mutex> &lock, time_t t);
	virtual bool waitFor(std::unique_lock<std::mutex> &lock, std::chrono::seconds s);
	virtual void notifyOne();
	virtual void notifyAll();

	void setTime(time_t t);
	void setTimeoutOccurred(bool stimeoutOccurred);

	time_t getWaitUntilTime();
};

#endif /* OADRTEST_OADRTEST_TESTS_SCHEDULER_MOCKCONDITIONALSLEEP_H_ */
