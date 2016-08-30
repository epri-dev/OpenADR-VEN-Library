/*
 * JobEventStart.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "JobEventStart.h"
#include "../../../../helper/ISO8601Duration.h"

JobEventStart::JobEventStart(IEventService *service, const oadr2b::oadr::oadrEvent *event) :
	m_service(service),
	m_event(event)
{
}

/********************************************************************************/

JobEventStart::~JobEventStart()
{
}

/********************************************************************************/

void JobEventStart::execute(time_t now)
{
	string eventID = m_event->eiEvent().eventDescriptor().eventID();
	int durationInSeconds = ISO8601Duration::TotalSeconds(m_event->eiEvent().eiActivePeriod().properties().duration().duration());

	m_service->OnEventStart(eventID, m_event, durationInSeconds);
}
