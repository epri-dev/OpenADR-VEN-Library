/*
 * MockScheduler.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_HELPER_MOCKSCHEDULER_H_
#define OADRTEST_OADRTEST_HELPER_MOCKSCHEDULER_H_

#include <set>

#include <oadr/scheduler/IScheduler.h>

using namespace std;

class MockScheduler : public IScheduler
{

public:
	MockScheduler();
	virtual ~MockScheduler();

	virtual bool addJob(unique_ptr<SchedulerJob> schedulerJob);
	virtual bool removeJob(string schedulerJobID);

	virtual void executeNext();

	virtual size_t getNumScheduledJobs();

	virtual void run() {};
	virtual void stop() {};

	set<string> scheduleIDs;

	list<string> removedScheduleIDs;

	size_t AddJobCalledCount;
	size_t RemoveJobCalledCount;
};

#endif /* OADRTEST_OADRTEST_HELPER_MOCKSCHEDULER_H_ */
