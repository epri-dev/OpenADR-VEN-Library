/*
 * JobEventIntervalStart.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "JobEventIntervalStart.h"

JobEventIntervalStart::JobEventIntervalStart(IEventService *service, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, string uid, float payload, time_t dtstart, int durationInSeconds) :
	m_service(service),
	m_event(event),
	m_eventSignal(eventSignal),
	m_uid(uid),
	m_payload(payload),
	m_dtstart(dtstart),
	m_durationInSeconds(durationInSeconds)
{
}

/********************************************************************************/

JobEventIntervalStart::~JobEventIntervalStart()
{
}

/********************************************************************************/

void JobEventIntervalStart::execute(time_t now)
{
	string eventID = m_event->eiEvent().eventDescriptor().eventID();

	m_service->OnEventIntervalStart(eventID, m_event, m_eventSignal, m_uid, m_payload, m_dtstart, m_durationInSeconds);
}
