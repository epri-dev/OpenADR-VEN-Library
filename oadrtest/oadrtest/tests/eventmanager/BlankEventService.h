/*
 * MockEventService.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKEVENTSERVICE_H_
#define OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKEVENTSERVICE_H_

#include <oadr/manager/eventmanager/IEventService.h>

class BlankEventService : public IEventService
{
public:
	BlankEventService();
	virtual ~BlankEventService();

	virtual void OnEventStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, unsigned int remainingDurationInSeconds);
	virtual void OnEventComplete(const std::string &eventID, const oadr2b::oadr::oadrEvent *event);
	virtual void OnEventIntervalStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, std::string uid, float payload, time_t dtstart, unsigned int remainingDurationInSeconds);

	virtual void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType);
	virtual void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent, oadr2b::ei::OptTypeType::value &optType);
	virtual void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType);
	virtual void OnEventImplicitCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event);

	unsigned int OnStartCount;
	unsigned int OnCompleteCount;
	unsigned int OnIntervalStartCount;

	unsigned int OnNewCount;
	unsigned int OnModifyCount;
	unsigned int OnCancelCount;
	unsigned int OnImplicitCancelCount;

	bool OnNewCalledFirst;

	unsigned int remainingDuration;
	unsigned int remainingIntervalDuration;
};

#endif /* OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKEVENTSERVICE_H_ */
