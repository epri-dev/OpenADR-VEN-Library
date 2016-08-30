/*
 * MockScheduler.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "MockScheduler.h"

MockScheduler::MockScheduler()
{
	AddJobCalledCount = 0;
	RemoveJobCalledCount = 0;
}

/********************************************************************************/

MockScheduler::~MockScheduler()
{
}

/********************************************************************************/

bool MockScheduler::addJob(unique_ptr<SchedulerJob> schedulerJob)
{
	AddJobCalledCount++;

	scheduleIDs.insert(schedulerJob->getID());

	return true;
}

/********************************************************************************/

bool MockScheduler::removeJob(string schedulerJobID)
{
	RemoveJobCalledCount++;

	removedScheduleIDs.push_back(schedulerJobID);

	if (scheduleIDs.erase(schedulerJobID) > 0)
		return true;

	return false;
}

/********************************************************************************/

void MockScheduler::executeNext()
{

}

/********************************************************************************/

size_t MockScheduler::getNumScheduledJobs()
{
	return scheduleIDs.size();
}
