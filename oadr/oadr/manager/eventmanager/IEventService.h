/*
 * IEventService.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_IEVENTSERVICE_H_
#define OADR_OADR_VEN_VENMANAGER_IEVENTSERVICE_H_

#include <oadrsd/2b/oadr_20b.hxx>
#include <oadrsd/2b/eventResponses.hxx>

#include <string>

class IEventService
{
public:
	IEventService();
	virtual ~IEventService() = default;

	virtual void OnEventStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, unsigned int remainingDurationInSeconds) = 0;
	virtual void OnEventComplete(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) = 0;
	virtual void OnEventIntervalStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, std::string uid, float payload, time_t dtstart, unsigned int remainingDurationInSeconds) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType with an oadrEvent of:
	 * - the eventId that is not known yet, and
	 * - the eventStatus that is not cancelled, and
	 * - oadrResponseRequired that is set to always.
	 */
	virtual void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType with an oadrEvent of:
	 * - the eventId that is not known yet, and
	 * - the eventStatus that is not cancelled, and
	 * - oadrResponseRequired that is set to never.
	 */
	virtual void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType with an oadrEvent of:
	 * - the eventId that is known, and
	 * - the eventStatus that is not cancelled, and
	 * - oadrResponseRequired that is set to always.
	 */
	virtual void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent, oadr2b::ei::OptTypeType::value &optType) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType with an oadrEvent of:
	 * - the eventId that is known, and
	 * - the eventStatus that is not cancelled, and
	 * - oadrResponseRequired that is set to never.
	 */
	virtual void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType with an oadrEvent of:
	 * - the eventStatus that is cancelled, and
	 * - oadrResponseRequired that is set to always.
	 * @param optType optIn = Confirm to cancellation; optOut = Cannot cancel.
	 */
	virtual void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType with an oadrEvent of:
	 * - the eventStatus that is cancelled, and
	 * - oadrResponseRequired that is set to never.
	 */
	virtual void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) = 0;

	/**
	 * Called when the VEN receives a message of the type oadrDistributeEventType without the oadrEvent of the eventId that is known.
	 */
	virtual void OnEventImplicitCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) = 0;
};

#endif /* OADR_OADR_VEN_VENMANAGER_IEVENTSERVICE_H_ */
