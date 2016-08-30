/*
 * JobException.h
 *
 *  Created on: Dec 10, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_SCHEDULER_JOBEXCEPTION_H_
#define OADRTEST_OADRTEST_TESTS_SCHEDULER_JOBEXCEPTION_H_

#include <stdexcept>
#include <oadr/scheduler/IJob.h>

class JobException: public IJob
{
public:
	JobException();
	virtual ~JobException();

	virtual void execute(time_t now);
};

#endif /* OADRTEST_OADRTEST_TESTS_SCHEDULER_JOBEXCEPTION_H_ */
