/*
 * MockGlobalTime.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_HELPER_MOCKGLOBALTIME_H_
#define OADRTEST_OADRTEST_HELPER_MOCKGLOBALTIME_H_

#include <oadr/helper/globaltime/GlobalTime.h>

class MockGlobalTime : public IGlobalTime
{
private:
	time_t m_now;

public:
	MockGlobalTime();
	virtual ~MockGlobalTime();

	virtual time_t now();

	void setNow(time_t now);

	void setNow(int year, int month, int day, int hours, int minutes, int seconds);
};

#endif /* OADRTEST_OADRTEST_HELPER_MOCKGLOBALTIME_H_ */
