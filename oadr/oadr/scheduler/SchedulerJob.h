/*
 * SchedulerJob.h
 *
 *  Created on: Mar 11, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_SCHEDULER_SCHEDULERJOB_H_
#define OADR_OADR_VEN_VENMANAGER_SCHEDULER_SCHEDULERJOB_H_

#include "IJob.h"

#include <list>
#include <string>
#include <stdexcept>

#include <memory>

using namespace std;

class SchedulerJob
{
private:
	unique_ptr<IJob> m_job;

	string m_id;

	time_t m_runTime;

	time_t m_nextRuntime;

	bool m_isOnetime;

	unsigned int m_intervalInSeconds;
	unsigned int m_durationInSeconds;

	bool m_isComplete;

	list<SchedulerJob*>::iterator m_pos;


	/**
	 * runTime: time to execute the job
	 * intervalInSeconds: used for repeating jobs.  execute every `intervalInSeconds`.
	 * durationInSeconds: periodic job will execute until runTime + durationInSeconds has passed.
	 *   a value of zero (0) means indefinite
	 */
	SchedulerJob(unique_ptr<IJob> job, string id, time_t runTime, bool isOnetime, unsigned int intervalInSeconds = 0, unsigned int durationInSeconds = 0);

public:

	virtual ~SchedulerJob();

	time_t getRuntime() const;

	/**
	 * time: current time
	 * calculate the next runtime and set isComplete to true
	 * if the job is complete
	 *
	 */
	void setNextRuntime(time_t now);

	void execute(time_t time);

	int getIntervalInSeconds();
	int getDurationInSeconds();

	bool isComplete();

	string &getID();

	bool isOnetime();
	bool isPeriodic();

	void setPos(list<SchedulerJob*>::iterator &pos);
	list<SchedulerJob*>::iterator &getPos();

	static unique_ptr<SchedulerJob> CreatePeriodicSchedulerJob(unique_ptr<IJob> job, string id, time_t runTime, unsigned int intervalInSeconds, unsigned int durationInSeconds);
	static unique_ptr<SchedulerJob> CreateOnetimeSchedulerJob(unique_ptr<IJob> job, string id, time_t runTime);
};

#endif /* OADR_OADR_VEN_VENMANAGER_SCHEDULER_SCHEDULERJOB_H_ */
