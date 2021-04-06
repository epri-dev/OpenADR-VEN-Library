/*
 * EventManager.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "../../helper/globaltime/GlobalTime.h"
#include "EventManager.h"

#include "../../helper/ISO8601Duration.h"
#include "../../helper/DateTimeConverter.h"

#include "../../request/Oadr2bHelper.h"

#include <sstream>

#include "job/event/JobEventComplete.h"
#include "job/event/JobEventIntervalStart.h"
#include "job/event/JobEventStart.h"

using namespace oadr2b::oadr;
using namespace oadr2b::ei;
using namespace payloads;
using namespace stream;

/********************************************************************************/

const string EventManager::C_EVENT = "event.";

const string EventManager::C_START = ".start";
const string EventManager::C_COMPLETE = ".complete";

const string EventManager::C_INTERVAL = ".interval";

/********************************************************************************/

EventManager::EventManager(IScheduler *scheduler, IEventService *service, ISendCreatedEvent *sendCreatedEvent) :
	m_scheduler(scheduler),
	m_service(service),
	m_sendCreatedEvent(sendCreatedEvent)
{
}

/********************************************************************************/

EventManager::~EventManager()
{
}

/********************************************************************************/

void EventManager::removeSchedule(const string &eventID)
{
	auto itr = m_jobIDs.find(eventID);

	if (itr == m_jobIDs.end())
		return;


	for (auto &id : itr->second)
	{
		m_scheduler->removeJob(id);
	}

	m_jobIDs.erase(itr);
}

/********************************************************************************/

void EventManager::scheduleEventStart(const string &eventID, const oadr2b::oadr::oadrEvent *event, time_t dtstart)
{
	time_t now = GlobalTime::Instance()->now();

	if (now >= dtstart)
	{
		string duration = event->eiEvent().eiActivePeriod().properties().duration().duration();
		int durationInSeconds = ISO8601Duration::TotalSeconds(duration);

		// The event is active; send a start message
		// durationInSeconds == 0 means the event runs forever
		if (dtstart + durationInSeconds > now)
		{
			m_service->OnEventStart(eventID, event, durationInSeconds - (now - dtstart));
		}
		else if (durationInSeconds == 0)
		{
			m_service->OnEventStart(eventID, event, 0);
		}

		return;
	}

	string jobID = string(C_EVENT + eventID + C_START);

	m_jobIDs[eventID].push_back(jobID);

	unique_ptr<JobEventStart> jobEventStart(new JobEventStart(m_service, event));
	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreateOnetimeSchedulerJob(std::move(jobEventStart), jobID, dtstart);

	m_scheduler->addJob(std::move(schedulerJob));
}

/********************************************************************************/

void EventManager::scheduleEventComplete(const string &eventID, const oadr2b::oadr::oadrEvent *event, time_t dtend)
{
	time_t now = GlobalTime::Instance()->now();

	if (now > dtend)
		return;

	string jobID = string(C_EVENT + eventID + C_COMPLETE);

	m_jobIDs[eventID].push_back(jobID);

	unique_ptr<JobEventComplete> jobEventStart(new JobEventComplete(m_service, event));
	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreateOnetimeSchedulerJob(std::move(jobEventStart), jobID, dtend);

	m_scheduler->addJob(std::move(schedulerJob));
}

/********************************************************************************/

void EventManager::scheduleEventIntervalStart(const string &eventID, const oadr2b::oadr::oadrEvent *event,
		const oadr2b::ei::eiEventSignalType *eventSignal, string uid, float payload, time_t dtstart, int durationInSeconds)
{
	time_t now = GlobalTime::Instance()->now();

	if (now >= dtstart)
	{
		// The event interval is active
		if (dtstart + durationInSeconds > now)
		{
			m_service->OnEventIntervalStart(eventID, event, eventSignal, uid, payload, dtstart, durationInSeconds - (now - dtstart));
		}
		else if (durationInSeconds == 0)
		{
			m_service->OnEventIntervalStart(eventID, event, eventSignal, uid, payload, dtstart, durationInSeconds);
		}

		return;
	}

	stringstream jobID;

	jobID << C_EVENT << eventID << C_INTERVAL << "." << eventSignal->signalID() << "." << uid << C_START;

	m_jobIDs[eventID].push_back(jobID.str());

	unique_ptr<JobEventIntervalStart> jobEventIntervalStart(new JobEventIntervalStart(m_service, event, eventSignal, uid, payload, dtstart, durationInSeconds));
	unique_ptr<SchedulerJob> schedulerJob = SchedulerJob::CreateOnetimeSchedulerJob(std::move(jobEventIntervalStart), jobID.str(), dtstart);

	m_scheduler->addJob(std::move(schedulerJob));
}

/********************************************************************************/

void EventManager::scheduleEvent(const string &eventID, const oadr2b::oadr::oadrEvent *event)
{
	try
	{
		auto eventStatus = event->eiEvent().eventDescriptor().eventStatus();

		// Don't schedule cancelled or completed events
		if (eventStatus == oadr2b::ei::EventStatusEnumeratedType::cancelled || eventStatus == oadr2b::ei::EventStatusEnumeratedType::completed)
			return;

		time_t eventDtstart = DateTimeConverter::DateTimeToTime_t(event->eiEvent().eiActivePeriod().properties().dtstart().date_time());
		int durationInSeconds = ISO8601Duration::TotalSeconds(event->eiEvent().eiActivePeriod().properties().duration().duration());

		scheduleEventStart(eventID, event, eventDtstart);

		// durationInSeconds == 0 means run forever so don't schedule an eventComplete job
		if (durationInSeconds != 0)
			scheduleEventComplete(eventID, event, eventDtstart + durationInSeconds);

		for (const auto &signal : event->eiEvent().eiEventSignals().eiEventSignal())
		{
			int durationOffset = 0;

			for (const auto &interval : signal.intervals().interval())
			{
				string uid = interval.uid()->text();

				const signalPayloadType *spt = (signalPayloadType*)(&(interval.streamPayloadBase().front()));
				PayloadFloatType *pft = &(PayloadFloatType&)spt->payloadBase();

				int durationInSeconds = ISO8601Duration::TotalSeconds(interval.duration()->duration());

				scheduleEventIntervalStart(eventID, event, &signal, uid, pft->value(), eventDtstart + durationOffset, durationInSeconds);

				durationOffset += durationInSeconds;
			}
		}
	}
	catch (runtime_error &ex)
	{
		removeSchedule(eventID);

		throw(ex);
	}
}

/********************************************************************************/

void EventManager::handleExistingEvent(const string &eventID, const oadr2b::oadr::oadrEvent *event, const string &requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses)
{
	oadr2b::oadr::oadrEvent *existingEvent = m_events[eventID].get();

	// The event hasn't been modified
	if (existingEvent->eiEvent().eventDescriptor().modificationNumber() ==
			event->eiEvent().eventDescriptor().modificationNumber())
	{
		return;
	}

	oadr2b::oadr::oadrEvent *eventCopy = event->_clone();

	if (event->eiEvent().eventDescriptor().eventStatus() == EventStatusEnumeratedType::cancelled)
	{
		if (oadr2b::oadr::ResponseRequiredType::value::always == event->oadrResponseRequired())
		{
			oadr2b::ei::OptTypeType::value optType = oadr2b::ei::OptTypeType::optIn;

			m_service->OnEventCancel(eventID, event, optType);

			Oadr2bHelper::appendEventResponse(eventResponses, "200", "OK", eventID,
					event->eiEvent().eventDescriptor().modificationNumber(), optType, requestID);
		}
		else // oadr2b::oadr::ResponseRequiredType::value::never
		{
			m_service->OnEventCancel(eventID, event);
		}

		removeSchedule(eventID);
	}
	else
	{
		if (oadr2b::oadr::ResponseRequiredType::value::always == event->oadrResponseRequired())
		{
			oadr2b::ei::OptTypeType::value optType = oadr2b::ei::OptTypeType::optOut;

			m_service->OnEventModify(eventID, event, existingEvent, optType);

			Oadr2bHelper::appendEventResponse(eventResponses, "200", "OK", eventID,
					event->eiEvent().eventDescriptor().modificationNumber(), optType, requestID);
		}
		else // oadr2b::oadr::ResponseRequiredType::value::never
		{
			m_service->OnEventModify(eventID, event, existingEvent);
		}

		removeSchedule(eventID);
		scheduleEvent(eventID, eventCopy);
	}

	m_events[eventID] = unique_ptr<oadr2b::oadr::oadrEvent>(eventCopy);
}

/********************************************************************************/

void EventManager::handleNewEvent(const string &eventID, const oadr2b::oadr::oadrEvent *event, const string &requestID, oadr2b::ei::eventResponses::eventResponse_sequence &eventResponses)
{
	oadr2b::oadr::oadrEvent *eventCopy = event->_clone();

	m_events[eventID] = unique_ptr<oadr2b::oadr::oadrEvent>(eventCopy);

	if (oadr2b::oadr::ResponseRequiredType::value::always == event->oadrResponseRequired())
	{
		oadr2b::ei::OptTypeType::value optType = oadr2b::ei::OptTypeType::optOut;

		m_service->OnEventNew(eventID, eventCopy, optType);

		Oadr2bHelper::appendEventResponse(eventResponses, "200", "OK", eventID,
				eventCopy->eiEvent().eventDescriptor().modificationNumber(), optType, requestID);
	}
	else // oadr2b::oadr::ResponseRequiredType::value::never
	{
		m_service->OnEventNew(eventID, event);
	}

	scheduleEvent(eventID, eventCopy);
}

/********************************************************************************/

void EventManager::manageEvents(oadr2b::oadr::oadrDistributeEventType &message)
{
	oadrDistributeEventType::oadrEvent_iterator itr;

	set<string> processedEventIDs;

	oadr2b::ei::eventResponses::eventResponse_sequence eventResponses;

	for (const auto &event : message.oadrEvent())
	{
		const string eventID = event.eiEvent().eventDescriptor().eventID();

		// Does the event exist in the current map?
		if (m_events.find(eventID) == m_events.end())
		{
			// This is a new event that needs to be scheduled
			handleNewEvent(eventID, &event, message.requestID(), eventResponses);
		}
		else
		{
			// Check if the event has been modified
			handleExistingEvent(eventID, &event, message.requestID(), eventResponses);
		}

		processedEventIDs.insert(eventID);
	}

	// Send a cancel event message for any events not included in the incoming message
	for (const auto &event : m_events)
	{
		const string eventID = event.first;

		if (processedEventIDs.find(eventID) == processedEventIDs.end())
		{
			m_service->OnEventImplicitCancel(eventID, event.second.get());

			removeSchedule(eventID);

			m_events.erase(eventID);
		}
	}

	m_sendCreatedEvent->sendCreatedEvent("200", "OK", message.requestID(), eventResponses);
}
