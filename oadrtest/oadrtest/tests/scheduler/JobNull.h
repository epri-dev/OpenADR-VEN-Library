/*
 * JobNull.h
 *
 *  Created on: Mar 11, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_SCHEDULER_JOBNULL_H_
#define OADRTEST_OADRTEST_TESTS_SCHEDULER_JOBNULL_H_

#include <oadr/scheduler/IJob.h>

class JobNull : public IJob
{
private:
	int *m_executeCalledCount;

	int m_internalExecuteCalledCount;
public:
	JobNull(int *executeCalledCount = NULL);
	virtual ~JobNull();

	virtual void execute(time_t t);
};

#endif /* OADRTEST_OADRTEST_TESTS_SCHEDULER_JOBNULL_H_ */
