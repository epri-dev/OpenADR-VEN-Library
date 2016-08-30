/*
 * CreateEventHelper.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: dupes
 */

#include "CreateEventHelper.h"

CreateEventHelper::CreateEventHelper()
{
}

/********************************************************************************/

CreateEventHelper::~CreateEventHelper()
{
}

/********************************************************************************/

oadrEvent::eiEvent_type::eventDescriptor_type *CreateEventHelper::CreateEventDescriptor(string eventID, unsigned int modificationNumber,
		string marketContext, time_t createdAt, EventStatusEnumeratedType status)
{
	// GCC won't compile if we don't call c_str() on marketContext...
	// but the strange thing is, the eventDescriptor line is where
	// the compile error is generated
	eiMarketContext mc(MarketContextType(marketContext.c_str()));

	oadrEvent::eiEvent_type::eventDescriptor_type *eventDescriptor = new
			oadrEvent::eiEvent_type::eventDescriptor_type(eventID, modificationNumber, mc,
			DateTimeConverter::Time_tToDateTime(createdAt), status);

	return eventDescriptor;
}


/********************************************************************************/

oadr2b::oadr::oadrEvent *CreateEventHelper::CreateEvent(time_t dtstart, int duration, std::string eventID)
{
/*
 *       eiEventType (const eventDescriptor_type&,
                   const eiActivePeriod_type&,
                   const eiEventSignals_type&,
                   const eiTarget_type&);
 */

	oadrEvent::eiEvent_type::eventDescriptor_type *eventDescriptor = CreateEventDescriptor(eventID,
			0, "", dtstart, EventStatusEnumeratedType::far);


	oadr2b::ei::eiActivePeriodType::properties_type pt(DateTimeConverter::Time_tToDateTime(dtstart),
			icalendar_2_0::properties::duration_type(""));

	oadr2b::ei::eiActivePeriodType::components_type ct;

	oadrEvent::eiEvent_type::eiActivePeriod_type activePeriod(pt, ct);

	oadrEvent::eiEvent_type::eiEventSignals_type eventSignals;

	// eventSignals.eiEventSignal().push_back();
/*
	oadrEvent::eiEvent_type::eiTarget_type targets;

	oadrEvent::eiEvent_type eventType;

	oadr2b::oadr::oadrEvent *event = new oadr2b::oadr::oadrEvent(ResponseRequiredType::always);

	return event;
	*/

	return NULL;
}
