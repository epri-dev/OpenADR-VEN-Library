/*
 * IRun.h
 *
 *  Created on: May 15, 2015
 *      Author: dupes
 */

#ifndef IRUN_H_
#define IRUN_H_

class IRun
{
public:
	virtual ~IRun() = default;

	virtual void run() = 0;
	virtual void stop() = 0;
};

#endif /* IRUN_H_ */
