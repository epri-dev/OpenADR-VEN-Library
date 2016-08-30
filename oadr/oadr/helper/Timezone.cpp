/*
 * TimeZone.cpp
 *
 *  Created on: Jun 29, 2015
 *      Author: dupes
 */

#include "Timezone.h"

#include <stdlib.h>
#include <string.h>

Timezone::Timezone() :
	m_envTZ(NULL),
	m_envIsStored(false)
{
}

/********************************************************************************/

Timezone::~Timezone()
{
	RestoreEnvTZ();
}

/********************************************************************************/

void Timezone::SetTimezone(std::string timeZone)
{
	setenv("TZ", timeZone.c_str(), 1);

	tzset();
}

/********************************************************************************/

void Timezone::StoreEnvTZ()
{
	m_envIsStored = true;

	char *tz = getenv("TZ");

	if (tz)
		m_envTZ = strdup(tz);
}

/********************************************************************************/

void Timezone::RestoreEnvTZ()
{
	// StoreEnvTZ was never called so there's nothing to restore
	if (!m_envIsStored)
		return;

	// m_envTZ != NULL indicates the TZ environment variable
	// was set and needs to be restored
	if (m_envTZ)
	{
		setenv("TZ", m_envTZ, 1);
		free(m_envTZ);
		m_envTZ = NULL;
	}
	else
	{
		// The TZ environment variable was not set and need to be removed
		unsetenv("TZ");
	}

	tzset();

	m_envIsStored = false;
}
