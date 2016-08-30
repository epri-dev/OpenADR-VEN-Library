/*
 * Scheduler.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: dupes
 */

#include "Scheduler.h"

Scheduler::Scheduler(shared_ptr<IConditionalSleep> conditionalSleep) :
	m_schedulerJobs(shared_ptr<SchedulerJobs>(new SchedulerJobs)),
	m_conditionalSleep(conditionalSleep)
{
	m_shutdown = false;


}

/********************************************************************************/

Scheduler::~Scheduler()
{
}

/********************************************************************************/

size_t Scheduler::getNumScheduledJobs()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	return m_schedulerJobs->size();
}

/********************************************************************************/

void Scheduler::sortJobs()
{
	m_schedulerJobs->sort();

	m_conditionalSleep->notifyAll();
}

/********************************************************************************/

bool Scheduler::addJob(unique_ptr<SchedulerJob> schedulerJob)
{
	std::unique_lock<std::mutex> lock(m_mutex);

	if (!m_schedulerJobs->addJob(std::move(schedulerJob)))
		return false;

	sortJobs();

	return true;
}

/********************************************************************************/

bool Scheduler::removeJobInternal(string schedulerJobID)
{
	m_schedulerJobs->removeJob(schedulerJobID);

	return true;
}

/********************************************************************************/

bool Scheduler::removeJob(string schedulerJobID)
{
	std::unique_lock<std::mutex> lock(m_mutex);

	return removeJobInternal(schedulerJobID);
}

/********************************************************************************/

/*
 * map<string, unique_ptr<ISchedule> > m_idToSchedule;
	list<ISchedule*> m_schedule;

 *
 * While the getRuntime() value of the front() item in m_schedule is <= runtime,
 * pop the front item and run execute on the job.  After calling execute on
 *  the job, check if the job isComplete().  If the job isn't
 *  complete, push the job back onto scheduler.
 *
 *  NOTE: when sorting is
 *  implemented, you would resort the list at this point but don't worry about
 *  sorting just yet.  If the schedule is complete, remove the schedule
 *  from m_idToSchedule.
 */
void Scheduler::execute(time_t runtime)
{
	SchedulerJob* schedulerJob;
	bool jobsOutOfOrder = false;

	schedulerJob = m_schedulerJobs->front();

	string firstID = schedulerJob->getID();

	time_t now = runtime;

	while (schedulerJob->getRuntime() <= now)
	{
		// run execute
		schedulerJob->execute(runtime);

		// check if schedulerJob isComplete()
		if(schedulerJob->isComplete() == true)
		{
			removeJobInternal(schedulerJob->getID());
		}
		else
		{
			m_schedulerJobs->rotate();

			jobsOutOfOrder = true;
		}

		if (m_schedulerJobs->size() == 0)
			break;

		schedulerJob = m_schedulerJobs->front();

		if (schedulerJob->getID() == firstID)
			break;

		now = GlobalTime::Instance()->now();
	}

	if (jobsOutOfOrder)
	{
		sortJobs();
	}
}

/********************************************************************************/

void Scheduler::executeNext()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	time_t now = GlobalTime::Instance()->now();

	if (m_schedulerJobs->size() == 0)
	{
		m_conditionalSleep->waitUntil(lock, now + 10);
		return;
	}

	SchedulerJob* schedulerJob = m_schedulerJobs->front();

	time_t nextRuntime = schedulerJob->getRuntime();

	if (nextRuntime - now < 0)
	{
		// TODO: log a message that the scheduler is "behind"
		// this condition can occur if jobs take long to run,
		// or a new job is created and the job start time passes
		// the job is added to the scheduler
		execute(nextRuntime);
	}
	else
	{
		// If the timeout occurs, it's time to run the next job
		// If we're woken for any other reason, the schedule changed, or its time to
		// to shutdown and the next job should not be executed
		if (m_conditionalSleep->waitFor(lock, std::chrono::seconds(nextRuntime - now)))
			execute(nextRuntime);
	}
}

/********************************************************************************/

map<string, unique_ptr<SchedulerJob>> &Scheduler::jobMap()
{
	return m_schedulerJobs->jobMap();
}

/********************************************************************************/

list<SchedulerJob*> &Scheduler::jobList()
{
	return m_schedulerJobs->jobList();
}

/********************************************************************************/

void Scheduler::run()
{
	while (!m_shutdown)
	{
		executeNext();
	}
}

/********************************************************************************/

void Scheduler::stop()
{
	std::unique_lock<std::mutex> lock(m_mutex);

	m_shutdown = true;

	m_conditionalSleep->notifyAll();
}

/********************************************************************************/

void Scheduler::visitJobs(std::function<void (const SchedulerJob *schedulerJob)> callback)
{
	std::unique_lock<std::mutex> lock(m_mutex);

	for (auto &schedulerJob : m_schedulerJobs->jobList())
	{
		callback(schedulerJob);
	}
}
