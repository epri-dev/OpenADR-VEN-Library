/*
 * ISleepTimer.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_HELPER_CONDITIONALSLEEP_ICONDITIONALSLEEP_H_
#define OADR_OADR_HELPER_CONDITIONALSLEEP_ICONDITIONALSLEEP_H_

#include <mutex>

using namespace std;

class IConditionalSleep
{
public:
	IConditionalSleep();
	virtual ~IConditionalSleep();

	virtual bool waitUntil(std::unique_lock<std::mutex> &lock, time_t t) = 0;

	virtual bool waitFor(std::unique_lock<std::mutex> &lock, std::chrono::seconds s) = 0;

	virtual void notifyOne() = 0;
	virtual void notifyAll() = 0;
};

#endif /* OADR_OADR_HELPER_CONDITIONALSLEEP_ICONDITIONALSLEEP_H_ */
