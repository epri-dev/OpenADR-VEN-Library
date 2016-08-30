/*
 * JobLambda.cpp
 *
 *  Created on: Jul 7, 2015
 *      Author: dupes
 */

#include "JobLambda.h"

JobLambda::JobLambda(const std::function<void (time_t)> &function) :
	m_function(function)
{
}

/********************************************************************************/

JobLambda::~JobLambda()
{

}

/********************************************************************************/

void JobLambda::execute(time_t now)
{
	m_function(now);
}
