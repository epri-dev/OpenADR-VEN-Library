/*
 * SchedulerJobTest.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: dupes
 */


#include <gtest/gtest.h>
#include <oadr/scheduler/SchedulerJob.h>
#include <oadr/helper/globaltime/GlobalTime.h>

#include "JobNull.h"
#include "../../helper/MockGlobalTime.h"

/********************************************************************************/

TEST(SchedulerJob, OneTimeSchedule)
{
	int executeCalledCount = 0;
	unique_ptr<JobNull> job(new JobNull(&executeCalledCount));

	time_t now = time(NULL);

	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreateOnetimeSchedulerJob(std::move(std::move(job)), "id", now);

	EXPECT_FALSE(schedulerJob->isComplete()) << "job should NOT be complete before it has been executed";

	schedulerJob->execute(now);

	EXPECT_TRUE(schedulerJob->isComplete()) << "job has been executed and should be complete";

	EXPECT_EQ(1, executeCalledCount) << "SchedulerJob didn't call execute on IJob";

	EXPECT_EQ(now, schedulerJob->getRuntime());

	EXPECT_TRUE(schedulerJob->isOnetime()) << "job should onetime";

	try
	{
		// running a completed job should raise an error
		schedulerJob->execute(now);

		FAIL() << "should have raised an exception";
	}
	catch (exception &ex)
	{
	}
}

/********************************************************************************/

TEST(SchedulerJob, PeriodicSchedule)
{
	MockGlobalTime globalTime;

	int executeCalledCount = 0;
	unique_ptr<JobNull> job(new JobNull(&executeCalledCount));

	time_t now = time(NULL);

	globalTime.setNow(now);

	int interval = 10;
	int duration = 20;

	// job executes every 10 seconds for 120 seconds
	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", now, interval, duration);

	EXPECT_TRUE(schedulerJob->isPeriodic()) << "job should perodic";

	EXPECT_EQ(now, schedulerJob->getRuntime());

	EXPECT_FALSE(schedulerJob->isComplete()) << "job should NOT be complete before it has been executed";

	schedulerJob->execute(now);

	EXPECT_FALSE(schedulerJob->isComplete()) << "job should NOT be complete";

	EXPECT_EQ(now + interval, schedulerJob->getRuntime());

	globalTime.setNow(now + interval);
	schedulerJob->execute(now + interval);

	EXPECT_EQ(2, executeCalledCount) << "SchedulerJob didn't call execute on IJob";

	EXPECT_FALSE(schedulerJob->isComplete()) << "job should NOT be complete";

	globalTime.setNow(now + interval * 2);
	schedulerJob->execute(now + interval * 2);

	EXPECT_TRUE(schedulerJob->isComplete()) << "job should be complete";

	EXPECT_EQ(now + interval * 3, schedulerJob->getRuntime());
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInFutureNextRuntimeSetCorrectly)
{
	// if the runtime is in the future, the runtime shouldn't be modified
	unique_ptr<JobNull> job(new JobNull());

	time_t now = time(NULL);

	time_t startTime = now + 10;

	int interval = 10;
	int duration = 500;

	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", startTime, interval, duration);

	EXPECT_EQ(startTime, schedulerJob->getRuntime());
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInPastNextRuntimeSetCorrectly)
{
	unique_ptr<JobNull> job(new JobNull());

	time_t now = time(NULL);

	time_t startTime = now - 200;

	int interval = 10;
	int duration = 500;

	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", startTime, interval, duration);

	time_t nextRunTime = startTime;

	// the next runtime should be the first date/time that's > now
	while (nextRunTime < now)
		nextRunTime += interval;

	EXPECT_EQ(nextRunTime, schedulerJob->getRuntime());
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInPastInvalidPeriodicTimeInPast)
{
	unique_ptr<JobNull> job(new JobNull());

	time_t t = time(NULL);

	int interval = 10;
	int duration = 120;

	try
	{
		unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", t - 200, interval, duration);

		FAIL() << "schedule completed in the past so constructor should have raised an error";
	}
	catch (exception &e)
	{

	}
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInPastInvalidOnetime)
{
	unique_ptr<JobNull> job(new JobNull());

	time_t t = time(NULL);

	try
	{
		// job executes every 10 seconds for 120 seconds
		unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreateOnetimeSchedulerJob(std::move(job), "id", t - 200);

		FAIL() << "schedule completed in the past so constructor should have raised an error";
	}
	catch (exception &e)
	{

	}
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInPastInvalidPerodicParameters1)
{
	unique_ptr<JobNull> job(new JobNull());

	time_t t = time(NULL);

	try
	{
		// both interval and duration must be specified
		unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", t - 200, 10, 10);

		FAIL() << "schedule completed in the past so constructor should have raised an error";
	}
	catch (exception &e)
	{

	}
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInPastInvalidPerodicParameters2)
{
	unique_ptr<JobNull> job(new JobNull());

	time_t t = time(NULL);

	try
	{
		// both interval and duration must be specified
		unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", t - 200, -1, 10);

		FAIL() << "schedule completed in the past so constructor should have raised an error";
	}
	catch (exception &e)
	{

	}
}

/********************************************************************************/

TEST(SchedulerJob, ScheduleInPastInvalidPerodicParametersIntervalMustBeGreaterThanZero)
{
	unique_ptr<JobNull> job(new JobNull());

	time_t t = time(NULL);

	try
	{
		// both interval and duration must be specified
		unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreatePeriodicSchedulerJob(std::move(job), "id", t - 200, 0, 10);

		FAIL() << "schedule completed in the past so constructor should have raised an error";
	}
	catch (exception &e)
	{

	}
}
