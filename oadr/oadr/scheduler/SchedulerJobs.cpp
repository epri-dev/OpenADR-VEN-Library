/*
 * SchedulerJobs.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#include "SchedulerJobs.h"

SchedulerJobs::SchedulerJobs()
{
}

/********************************************************************************/

SchedulerJobs::~SchedulerJobs()
{
}

/********************************************************************************/

bool SchedulerJobs::addJob(unique_ptr<SchedulerJob> schedulerJob)
{
	if (m_idToSchedule.find(schedulerJob->getID()) != m_idToSchedule.end())
		return false;

	// add schedule to the beginning of the list
	m_schedule.push_back(schedulerJob.get());

	// store the position of this item to make
	// it easy to find and delete from the list
	list<SchedulerJob*>::iterator itr = m_schedule.end();
	itr--;

	schedulerJob->setPos(itr);

	// lastly, insert schedule into map keying on schedule's ID
	// since we're moving the pointer, perform this action last so the function can continue
	// to operate on schedulerJob
	m_idToSchedule[schedulerJob->getID()] = std::move(schedulerJob);

	return true;
}

/********************************************************************************/

bool SchedulerJobs::removeJob(string schedulerJobID)
{
	map<string, unique_ptr<SchedulerJob>>::iterator itr;

	// get a handle on schedule from the map
	itr = m_idToSchedule.find(schedulerJobID);

	// check that s_ptr isn't NULL, or that the schedule is in the map
	if(itr == m_idToSchedule.end())
		return false;

	// remove schedule from list using handle from map
	m_schedule.erase(itr->second->getPos());

	// Remove schedule from the map
	m_idToSchedule.erase(schedulerJobID);

	return true;
}

/********************************************************************************/

void SchedulerJobs::sort()
{
	m_schedule.sort([](const SchedulerJob *first, const SchedulerJob *second)
			{ return (first->getRuntime() < second->getRuntime()); });
}

/********************************************************************************/

SchedulerJob *SchedulerJobs::front()
{
	return m_schedule.front();
}

/********************************************************************************/

void SchedulerJobs::rotate()
{
	if (m_schedule.size() == 0)
		throw runtime_error("SchedulerJobs::rotate : schedule is emtpy");

	SchedulerJob *schedulerJob = m_schedule.front();

	// pop schedulerJob from front and put it in the back of the list
	m_schedule.pop_front();
	m_schedule.push_back(schedulerJob);

	// update the list iterator
	list<SchedulerJob*>::iterator itr = m_schedule.end();
	schedulerJob->setPos(--itr);
}


/********************************************************************************/

size_t SchedulerJobs::size()
{
	return m_schedule.size();
}

/********************************************************************************/

map<string, unique_ptr<SchedulerJob>> &SchedulerJobs::jobMap()
{
	return m_idToSchedule;
}

/********************************************************************************/

list<SchedulerJob*> &SchedulerJobs::jobList()
{
	return m_schedule;
}
