/*
 * BlankSendCreatedEvent.cpp
 *
 *  Created on: Jul 7, 2015
 *      Author: dupes
 */

#include "BlankSendCreatedEvent.h"

BlankSendCreatedEvent::BlankSendCreatedEvent()
{
	SendCreatedEventCount = 0;
	EventResponseCount = 0;
}

/********************************************************************************/

BlankSendCreatedEvent::~BlankSendCreatedEvent()
{
}

/********************************************************************************/

void BlankSendCreatedEvent::sendCreatedEvent(string responseCode, string responseDescription, string requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses)
{
	SendCreatedEventCount++;

	EventResponseCount = eventResponses.size();
}
