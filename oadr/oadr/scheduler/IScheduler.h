/*
 * IScheduler.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_SCHEDULER_ISCHEDULER_H_
#define OADR_OADR_VEN_VENMANAGER_SCHEDULER_ISCHEDULER_H_

#include "SchedulerJob.h"

#include "../helper/thread/IRun.h"

#include <string>
#include <memory>

using namespace std;

class IScheduler : public IRun
{
public:
	IScheduler();
	virtual ~IScheduler();

	virtual bool addJob(unique_ptr<SchedulerJob> schedulerJob) = 0;
	virtual bool removeJob(string schedulerJobID) = 0;

	virtual void executeNext() = 0;

	virtual size_t getNumScheduledJobs() = 0;
};

#endif /* OADR_OADR_VEN_VENMANAGER_SCHEDULER_ISCHEDULER_H_ */
