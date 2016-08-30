/*
 * GlobalTimeStandard.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: dupes
 */

#include "GlobalTimeStandard.h"

GlobalTimeStandard::GlobalTimeStandard()
{
	// TODO Auto-generated constructor stub

}

/********************************************************************************/

GlobalTimeStandard::~GlobalTimeStandard()
{
	// TODO Auto-generated destructor stub
}

/********************************************************************************/

time_t GlobalTimeStandard::now()
{
	return time(NULL);
}
