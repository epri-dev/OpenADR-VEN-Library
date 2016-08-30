/*
 * CreateEventHelper.h
 *
 *  Created on: Jun 26, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_EVENTMANAGER_CREATEEVENTHELPER_H_
#define OADRTEST_OADRTEST_TESTS_EVENTMANAGER_CREATEEVENTHELPER_H_

#include <oadrsd/2b/oadr_20b.hxx>
#include <oadrsd/2b/intervals.hxx>
#include <oadrsd/2b/oadrDistributeEventType.hxx>

#include <oadr/helper/DateTimeConverter.h>

#include <memory>

#include <string>

using namespace oadr2b::oadr;
using namespace oadr2b::ei;
using namespace oadr2b::emix;
using namespace std;

class CreateEventHelper
{
public:
	CreateEventHelper();
	virtual ~CreateEventHelper();

	static oadrEvent::eiEvent_type::eventDescriptor_type *CreateEventDescriptor(string eventID, unsigned int modificationNumber,
			string marketContext, time_t createdAt, EventStatusEnumeratedType status);

	static oadr2b::oadr::oadrEvent *CreateEvent(time_t dtstart, int duration, std::string eventID);
};

#endif /* OADRTEST_OADRTEST_TESTS_EVENTMANAGER_CREATEEVENTHELPER_H_ */
