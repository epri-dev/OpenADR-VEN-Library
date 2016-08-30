/*
 * IGlobalTime.h
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_HELPER_GLOBALTIME_IGLOBALTIME_H_
#define OADR_OADR_HELPER_GLOBALTIME_IGLOBALTIME_H_

#include <time.h>

class IGlobalTime
{
public:
	IGlobalTime();
	virtual ~IGlobalTime();

	virtual time_t now() = 0;
};

#endif /* OADR_OADR_HELPER_GLOBALTIME_IGLOBALTIME_H_ */
