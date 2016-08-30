/*
 * IJob.h
 *
 *  Created on: Oct 5, 2014
 *      Author: dupes
 */

#ifndef IJOB_H_
#define IJOB_H_

#include <time.h>

#include <string>
#include <list>

using namespace std;

class IJob
{
private:

public:
	IJob();
	virtual ~IJob();

	virtual void execute(time_t now) = 0;
};

#endif /* IJOB_H_ */
