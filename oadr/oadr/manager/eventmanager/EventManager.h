/*
 * EventManager.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_EVENTMANAGER_H_
#define OADR_OADR_VEN_VENMANAGER_EVENTMANAGER_H_

#include "../../scheduler/IScheduler.h"

#include "IEventService.h"
#include "ISendCreatedEvent.h"

#include <oadrsd/2b/oadr_20b.hxx>
#include <oadrsd/2b/intervals.hxx>
#include <oadrsd/2b/oadrDistributeEventType.hxx>

#include <set>

class EventManager
{
private:
	const static string C_EVENT;
	const static string C_START;
	const static string C_COMPLETE;
	const static string C_INTERVAL;

	IScheduler *m_scheduler;
	IEventService *m_service;

	ISendCreatedEvent *m_sendCreatedEvent;

	map<string, unique_ptr<oadr2b::oadr::oadrEvent>> m_events;
	map<string, list<string>> m_jobIDs;

	void scheduleEventStart(const string &eventID, const oadr2b::oadr::oadrEvent *event, time_t dtstart);
	void scheduleEventComplete(const string &eventID, const oadr2b::oadr::oadrEvent *event, time_t dtend);
	void scheduleEventIntervalStart(const string &eventID, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, string uid, float payload, time_t dtstart, int durationInSeconds);

	void handleNewEvent(const string &eventID, const oadr2b::oadr::oadrEvent *event, const string &requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses);
	void handleExistingEvent(const string &eventID, const oadr2b::oadr::oadrEvent *event, const string &requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses);

public:
	EventManager(IScheduler *scheduler, IEventService *service, ISendCreatedEvent *sendCreatedEvent);

	virtual ~EventManager();

	void scheduleEvent(const string &eventID, const oadr2b::oadr::oadrEvent *event);

	void removeSchedule(const string &eventID);

	void manageEvents(oadr2b::oadr::oadrDistributeEventType &message);
};

#endif /* OADR_OADR_VEN_VENMANAGER_EVENTMANAGER_H_ */
