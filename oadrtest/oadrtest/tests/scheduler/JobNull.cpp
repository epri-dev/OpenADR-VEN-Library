/*
 * JobNull.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: dupes
 */

#include "JobNull.h"

JobNull::JobNull(int *executeCalledCount)
{
	if (executeCalledCount != NULL)
	{
		m_executeCalledCount = executeCalledCount;
	}
	else
	{
		m_executeCalledCount = &m_internalExecuteCalledCount;
	}

	m_internalExecuteCalledCount = 0;
}

/********************************************************************************/

JobNull::~JobNull()
{
}

/********************************************************************************/

void JobNull::execute(time_t t)
{
	(*m_executeCalledCount)++;
}

