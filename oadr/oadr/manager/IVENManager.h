/*
 * IVENManager.h
 *
 *  Created on: Jul 9, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_MANAGER_IVENMANAGER_H_
#define OADR_OADR_MANAGER_IVENMANAGER_H_

#include <exception>

#include "../helper/thread/IRun.h"
#include "../scheduler/Scheduler.h"

class IVENManager : public IRun
{
public:
	IVENManager();
	virtual ~IVENManager();

	virtual Scheduler *getScheduler() = 0;
};

#endif /* OADR_OADR_MANAGER_IVENMANAGER_H_ */
