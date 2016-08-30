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
	virtual ~IEventService();

	virtual void OnEventStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, unsigned int remainingDurationInSeconds) = 0;
	virtual void OnEventComplete(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) = 0;
	virtual void OnEventIntervalStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, std::string uid, float payload, time_t dtstart, unsigned int remainingDurationInSeconds) = 0;

	virtual void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType) = 0;
	virtual void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent, oadr2b::ei::OptTypeType::value &optType) = 0;

	virtual void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType) = 0;

	virtual void OnEventImplicitCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) = 0;
};

#endif /* OADR_OADR_VEN_VENMANAGER_IEVENTSERVICE_H_ */
