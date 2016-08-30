/*
 * BlankSendCreatedEvent.h
 *
 *  Created on: Jul 7, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKSENDCREATEDEVENT_H_
#define OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKSENDCREATEDEVENT_H_

#include <oadr/manager/eventmanager/ISendCreatedEvent.h>

class BlankSendCreatedEvent : public ISendCreatedEvent
{
public:
	BlankSendCreatedEvent();
	virtual ~BlankSendCreatedEvent();

	virtual void sendCreatedEvent(string responseCode, string responseDescription, string requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses);

	unsigned int SendCreatedEventCount;

	size_t EventResponseCount;
};

#endif /* OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKSENDCREATEDEVENT_H_ */
