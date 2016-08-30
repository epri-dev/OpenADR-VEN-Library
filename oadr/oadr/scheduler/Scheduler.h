/*
 * Scheduler.h
 *
 *  Created on: Oct 5, 2014
 *      Author: dupes
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <memory>

#include <map>
#include <list>
#include <stdexcept>

#include <condition_variable>
#include <mutex>
#include <chrono>
#include <memory>

#include <functional>

#include "../helper/conditionalsleep/ConditionalSleep.h"
#include "../helper/globaltime/GlobalTime.h"

#include "SchedulerJobs.h"
#include "IScheduler.h"

using namespace std;
using namespace std::chrono;

class Scheduler : public IScheduler
{
private:
	shared_ptr<SchedulerJobs> m_schedulerJobs;
	shared_ptr<IConditionalSleep> m_conditionalSleep;

    mutex m_mutex;

    bool m_shutdown;

	void sortJobs();

	void execute(time_t runtime);

	virtual bool removeJobInternal(string schedulerJobID);

public:
	Scheduler(shared_ptr<IConditionalSleep> conditionalSleep = shared_ptr<IConditionalSleep>(new ConditionalSleep()));
	virtual ~Scheduler();

	virtual size_t getNumScheduledJobs();

	virtual bool addJob(unique_ptr<SchedulerJob> schedulerJob);
	virtual bool removeJob(string schedulerJobID);

	virtual void executeNext();

	// TODO: remove these.  they're only exposed to
	// allow unit tests to examine internal state
	map<string, unique_ptr<SchedulerJob>> &jobMap();
	list<SchedulerJob*> &jobList();

	virtual void run();
	virtual void stop();

	void visitJobs(std::function<void (const SchedulerJob *schedulerJob)> callback);
};

#endif /* SCHEDULER_H_ */
