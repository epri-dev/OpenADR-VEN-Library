/*
 * GlobalTime.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: dupes
 */

#include "GlobalTime.h"

/********************************************************************************/

IGlobalTime *GlobalTime::m_instance = nullptr;

GlobalTimeStandard GlobalTime::m_defaultGlobalTime;

/********************************************************************************/

GlobalTime::GlobalTime()
{
}

/********************************************************************************/

GlobalTime::~GlobalTime()
{
}

/********************************************************************************/

void GlobalTime::SetDefaultGlobalTime()
{
	m_instance = &m_defaultGlobalTime;
}

/********************************************************************************/

void GlobalTime::SetGlobalTime(IGlobalTime *globalTime)
{
	m_instance = globalTime;
}

/********************************************************************************/

IGlobalTime *GlobalTime::Instance()
{
	if (m_instance == nullptr)
		m_instance = &m_defaultGlobalTime;

	return m_instance;
}
