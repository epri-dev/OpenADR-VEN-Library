/*
 * SchedulerJobs.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_SCHEDULER_SCHEDULERJOBS_H_
#define OADR_OADR_SCHEDULER_SCHEDULERJOBS_H_

#include "SchedulerJob.h"

#include <map>
#include <list>
#include <stdexcept>
#include <memory>

using namespace std;

class SchedulerJobs
{
private:
	map<string, unique_ptr<SchedulerJob>> m_idToSchedule;
	list<SchedulerJob*> m_schedule;

public:
	SchedulerJobs();
	virtual ~SchedulerJobs();

	bool addJob(unique_ptr<SchedulerJob> schedulerJob);
	bool removeJob(string schedulerJobID);

	void sort();

	SchedulerJob *front();

	void rotate();

	size_t size();

	map<string, unique_ptr<SchedulerJob>> &jobMap();
	list<SchedulerJob*> &jobList();
};

#endif /* OADR_OADR_SCHEDULER_SCHEDULERJOBS_H_ */
