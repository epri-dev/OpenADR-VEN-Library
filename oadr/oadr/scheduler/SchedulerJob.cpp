/*
 * SchedulerJob.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: dupes
 */

#include "SchedulerJob.h"

#include "../helper/globaltime/GlobalTime.h"

SchedulerJob::SchedulerJob(unique_ptr<IJob> job, string id, time_t runTime, bool isOnetime, unsigned int intervalInSeconds, unsigned int durationInSeconds) :
	m_job(std::move(job)),
	m_id(id),
	m_runTime(runTime),
	m_nextRuntime(runTime),
	m_isOnetime(isOnetime),
	m_intervalInSeconds(intervalInSeconds),
	m_durationInSeconds(durationInSeconds),
	m_isComplete(false)
{
}

/********************************************************************************/

SchedulerJob::~SchedulerJob()
{
}

/********************************************************************************/

unique_ptr<SchedulerJob> SchedulerJob::CreatePeriodicSchedulerJob(unique_ptr<IJob> job, string id, time_t runTime, unsigned int intervalInSeconds, unsigned int durationInSeconds)
{
	unique_ptr<SchedulerJob> schedulerJob;

	if (intervalInSeconds == 0)
		throw runtime_error("invalid scheduler parameters: interval cannot be 0");

	time_t now = GlobalTime::Instance()->now();

	if (runTime + durationInSeconds < now && durationInSeconds != 0)
		throw runtime_error("invalid scheduler parameters: start time + duration > now");

	if (now > runTime)
	{
		// the job should execute on multiples of m_runTime + (m_intervalInSeconds * count)
		// if the start time is in the past, the following code ensures the job is
		// executed on the next multiple
		int index = (now - runTime) / intervalInSeconds;

		runTime = (intervalInSeconds * index) + runTime;

		if (runTime < now)
			runTime += intervalInSeconds;
	}

	//
	// parameters are valid; create the SchedulerJob
	//
	schedulerJob = unique_ptr<SchedulerJob>(new SchedulerJob(std::move(job), id, runTime, false, intervalInSeconds, durationInSeconds));

	return schedulerJob;
}

/********************************************************************************/

unique_ptr<SchedulerJob> SchedulerJob::CreateOnetimeSchedulerJob(unique_ptr<IJob> job, string id, time_t runTime)
{
	unique_ptr<SchedulerJob> schedulerJob;

	time_t now = GlobalTime::Instance()->now();

	if (runTime < now)
		throw runtime_error("invalid scheduler parameters: runtime must be > now for onetime schedules");

	//
	// parameters are valid; create the SchedulerJob
	//
	schedulerJob = unique_ptr<SchedulerJob>(new SchedulerJob(std::move(job), id, runTime, true));

	return schedulerJob;
}

/********************************************************************************/

void SchedulerJob::setNextRuntime(time_t now)
{
	if (m_isComplete)
		throw runtime_error("SchedulerJob::setNextRuntime: function called on a complete job");

	// setNextRuntime shouldn't be called on a onetime job
	if (isOnetime())
		throw runtime_error("SchedulerJob::setNextRuntime: function called on onetime job");

	while (m_nextRuntime <= now)
		m_nextRuntime += m_intervalInSeconds;

	if (m_nextRuntime > m_durationInSeconds + m_runTime && m_durationInSeconds > 0)
	{
		m_isComplete = true;
		return;
	}
}

/********************************************************************************/

time_t SchedulerJob::getRuntime() const
{
	return m_nextRuntime;
}

/********************************************************************************/

void SchedulerJob::execute(time_t time)
{
	if (isComplete())
		throw runtime_error("SchedulerJob::execute : completed job executed");

	// TODO: exceptions need to be passed back to the scheduler and sent
	// in a callback to user space
	try
	{
		m_job->execute(time);
	}
	catch (exception &ex)
	{
	}

	// these values are set before executing the job to cover the
	// case where the job raises an exception
	// we don't want to catch the exception here and we must
	// make sure the state is set appropriately

	if (isPeriodic())
	{
		//
		// time has elapsed after executing the job
		// use the current time when determining the next runtime
		time_t now = GlobalTime::Instance()->now();

		setNextRuntime(now);
	}
	else
	{
		// onetime schedules are complete after being executed
		m_isComplete = true;
	}
}

/********************************************************************************/

int SchedulerJob::getIntervalInSeconds()
{
	return m_intervalInSeconds;
}

/********************************************************************************/

int SchedulerJob::getDurationInSeconds()
{
	return m_durationInSeconds;
}

/********************************************************************************/

bool SchedulerJob::isComplete()
{
	return m_isComplete;
}

/********************************************************************************/

string &SchedulerJob::getID()
{
	return m_id;
}

/********************************************************************************/

bool SchedulerJob::isOnetime()
{
	return m_isOnetime;
}

/********************************************************************************/

bool SchedulerJob::isPeriodic()
{
	return !m_isOnetime;
}

/********************************************************************************/

void SchedulerJob::setPos(list<SchedulerJob*>::iterator &pos)
{
	m_pos = pos;
}

/********************************************************************************/

list<SchedulerJob*>::iterator &SchedulerJob::getPos()
{
	return m_pos;
}
