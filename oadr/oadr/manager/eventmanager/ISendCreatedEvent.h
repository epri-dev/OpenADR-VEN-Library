/*
 * ISendCreatedEvent.h
 *
 *  Created on: Jul 7, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_MANAGER_EVENTMANAGER_ISENDCREATEDEVENT_H_
#define OADR_OADR_MANAGER_EVENTMANAGER_ISENDCREATEDEVENT_H_

#include <oadrsd/2b/eventResponses.hxx>

#include <string>

using namespace std;

class ISendCreatedEvent
{
public:
	ISendCreatedEvent();
	virtual ~ISendCreatedEvent();

	virtual void sendCreatedEvent(string responseCode, string responseDescription, string requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses) = 0;
};

#endif /* OADR_OADR_MANAGER_EVENTMANAGER_ISENDCREATEDEVENT_H_ */
