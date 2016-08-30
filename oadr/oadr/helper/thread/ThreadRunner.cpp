/*
 * ThreadRunner.cpp
 *
 *  Created on: May 15, 2015
 *      Author: dupes
 */

#include "ThreadRunner.h"

ThreadRunner::ThreadRunner(IRun *run, string name) :
	m_run(run),
	m_name(name)
{
	m_thread = NULL;
}

//===============================================================================================

ThreadRunner::~ThreadRunner()
{
	if (m_thread != NULL)
	{
		stop();
		join();
	}
}

//===============================================================================================

void ThreadRunner::start()
{
	m_thread = new thread(&IRun::run, m_run);
}

//===============================================================================================

void ThreadRunner::stop()
{
	m_run->stop();
}

//===============================================================================================

void ThreadRunner::join()
{
	if (m_thread == NULL)
	{
		return;
	}

	m_thread->join();

	delete (m_thread);
	m_thread = NULL;
}
