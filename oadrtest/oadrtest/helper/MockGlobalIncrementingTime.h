/*
 * MockGlobalIncrementingTime.h
 *
 *  Created on: Jun 26, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_HELPER_MOCKGLOBALINCREMENTINGTIME_H_
#define OADRTEST_OADRTEST_HELPER_MOCKGLOBALINCREMENTINGTIME_H_

#include <oadr/helper/globaltime/IGlobalTime.h>

class MockGlobalIncrementingTime : public IGlobalTime
{
private:
	time_t m_now;
	long int m_offset;

public:
	MockGlobalIncrementingTime();
	virtual ~MockGlobalIncrementingTime();

	virtual time_t now();

	void setNow(time_t now);
};

#endif /* OADRTEST_OADRTEST_HELPER_MOCKGLOBALINCREMENTINGTIME_H_ */
