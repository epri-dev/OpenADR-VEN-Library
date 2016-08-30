/*
 * SleepTimer.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_HELPER_CONDITIONALSLEEP_CONDITIONALSLEEP_H_
#define OADR_OADR_HELPER_CONDITIONALSLEEP_CONDITIONALSLEEP_H_

#include <condition_variable>
#include <chrono>

#include "IConditionalSleep.h"

using namespace std;
using namespace std::chrono;

class ConditionalSleep : public IConditionalSleep
{
private:
    std::condition_variable m_condition;

public:
	ConditionalSleep();
	virtual ~ConditionalSleep();

	virtual bool waitUntil(std::unique_lock<std::mutex> &lock, time_t t);
	virtual bool waitFor(std::unique_lock<std::mutex> &lock, std::chrono::seconds s);
	virtual void notifyOne();
	virtual void notifyAll();
};

#endif /* OADR_OADR_HELPER_CONDITIONALSLEEP_CONDITIONALSLEEP_H_ */
