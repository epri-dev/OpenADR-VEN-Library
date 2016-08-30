/*
 * ThreadRunner.h
 *
 *  Created on: May 15, 2015
 *      Author: dupes
 */

#ifndef THREADRUNNER_H_
#define THREADRUNNER_H_

#include <thread>
#include <string>

#include "IRun.h"

using namespace std;

class ThreadRunner
{
private:
	IRun *m_run;

	thread *m_thread;

	string m_name;

public:
	ThreadRunner(IRun *run, string name = "<noname>");

	virtual ~ThreadRunner();

	void start();
	void stop();

	void join();
};

#endif /* THREADRUNNER_H_ */
