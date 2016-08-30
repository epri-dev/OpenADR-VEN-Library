/*
 * TimeZone.h
 *
 *  Created on: Jun 29, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_HELPER_TIMEZONE_H_
#define OADRTEST_OADRTEST_HELPER_TIMEZONE_H_

#include <string>

#include <time.h>

class Timezone
{
private:
	char *m_envTZ;

	bool m_envIsStored;

public:
	Timezone();
	virtual ~Timezone();

	/**
	 * Set the timezone (US/Central, US/Eastern, etc,)
	 * Use an empty string to set UTC/GMT
	 * On Linux, timezone files can be found in /usr/share/zoneinfo
	 * The timezone parameter points to a file under the zoneinfo directory
	 */
	void SetTimezone(std::string timeZone);

	/**
	 * Stores the existing TZ environment variable
	 */
	void StoreEnvTZ();

	/**
	 * Restore the TZ environment variable (StoreEnvTZ must be called first)
	 */
	void RestoreEnvTZ();
};

#endif /* OADRTEST_OADRTEST_HELPER_TIMEZONE_H_ */
