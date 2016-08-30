/*
 * JobException.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: dupes
 */

#include "JobException.h"

JobException::JobException()
{
}

/********************************************************************************/

JobException::~JobException()
{
}

/********************************************************************************/

void JobException::execute(time_t now)
{
	throw std::runtime_error("JobException::execute : something bad happened");
}
