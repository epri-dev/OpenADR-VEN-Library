/*
 * JobEventComplete.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "JobEventComplete.h"

JobEventComplete::JobEventComplete(IEventService *service, const oadr2b::oadr::oadrEvent *event) :
	m_service(service),
	m_event(event)
{
}

/********************************************************************************/

JobEventComplete::~JobEventComplete()
{

}

/********************************************************************************/

void JobEventComplete::execute(time_t now)
{
	string eventID = m_event->eiEvent().eventDescriptor().eventID();

	m_service->OnEventComplete(eventID, m_event);
}
