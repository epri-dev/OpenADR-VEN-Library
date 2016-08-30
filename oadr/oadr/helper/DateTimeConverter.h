/*
 * DateTimeConverter.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_HELPER_DATETIMECONVERTER_H_
#define OADR_OADR_HELPER_DATETIMECONVERTER_H_

#include "Timezone.h"

#include <oadrsd/2b/dtstart.hxx>
#include <oadrsd/2b/DateTimeType.hxx>

class DateTimeConverter
{
private:
	DateTimeConverter();

public:
	virtual ~DateTimeConverter();

	static time_t DateTimeToTime_t(icalendar_2_0::dtstart::date_time_type dt);

	static icalendar_2_0::dtstart::date_time_type Time_tToDateTime(time_t t);
};

#endif /* OADR_OADR_HELPER_DATETIMECONVERTER_H_ */
