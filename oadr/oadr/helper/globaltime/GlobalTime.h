/*
 * GlobalTime.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_HELPER_GLOBALTIME_GLOBALTIME_H_
#define OADR_OADR_HELPER_GLOBALTIME_GLOBALTIME_H_

#include "IGlobalTime.h"

#include "GlobalTimeStandard.h"

class GlobalTime : public IGlobalTime
{
private:
	static IGlobalTime *m_instance;

	static GlobalTimeStandard m_defaultGlobalTime;

public:
	GlobalTime();
	virtual ~GlobalTime();

	static void SetDefaultGlobalTime();
	static void SetGlobalTime(IGlobalTime *globalTime);

	static IGlobalTime *Instance();
};

#endif /* OADR_OADR_HELPER_GLOBALTIME_GLOBALTIME_H_ */
