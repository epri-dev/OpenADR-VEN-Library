/*
 * DateTimeConverter.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "DateTimeConverter.h"

DateTimeConverter::DateTimeConverter()
{
}

/********************************************************************************/

DateTimeConverter::~DateTimeConverter()
{
}

/********************************************************************************/

time_t DateTimeConverter::DateTimeToTime_t(icalendar_2_0::dtstart::date_time_type dt)
{
	struct tm tm_utc;

	memset(&tm_utc , 0, sizeof(tm));

	tm_utc.tm_year = dt.year() - 1900;
	tm_utc.tm_mon = dt.month() - 1;
	tm_utc.tm_mday = dt.day();
	tm_utc.tm_hour = dt.hours();
	tm_utc.tm_min = dt.minutes();
	tm_utc.tm_sec = (int)dt.seconds();
	tm_utc.tm_isdst = -1;

	//
	// The function timegm(...) is non-standard :(.  The man pages suggest
	// setting the TZ variable (implemented below)
	// return timegm(&tm_utc);

	//
	// Before we can call mktime(&tm_utc), we have to set the timezone
	// to utc

	Timezone tz;

	tz.StoreEnvTZ();

	tz.SetTimezone("");

	time_t ret = mktime(&tm_utc);

	tz.RestoreEnvTZ();

	return ret;
}

/********************************************************************************/

icalendar_2_0::dtstart::date_time_type DateTimeConverter::Time_tToDateTime(time_t t)
{
	struct tm parts;

	memset(&parts , 0, sizeof(tm));

	gmtime_r(&t, &parts);

	icalendar_2_0::dtstart::date_time_type dt(::xml_schema::date_time(parts.tm_year + 1900, parts.tm_mon + 1, parts.tm_mday, parts.tm_hour,
			parts.tm_min, parts.tm_sec, 0, 0));

	return dt;
}
