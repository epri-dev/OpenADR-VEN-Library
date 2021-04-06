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

	void OnEventStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, unsigned int remainingDurationInSeconds) override;
	void OnEventComplete(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) override;
	void OnEventIntervalStart(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, std::string uid, float payload, time_t dtstart, unsigned int remainingDurationInSeconds) override;

	void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType) override;
	void OnEventNew(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) override;
	void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent, oadr2b::ei::OptTypeType::value &optType) override;
	void OnEventModify(const std::string &eventID, const oadr2b::oadr::oadrEvent *newEvent, const oadr2b::oadr::oadrEvent *oldEvent) override;
	void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event, oadr2b::ei::OptTypeType::value &optType) override;
	void OnEventCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) override;
	void OnEventImplicitCancel(const std::string &eventID, const oadr2b::oadr::oadrEvent *event) override;

	unsigned int OnStartCount;
	unsigned int OnCompleteCount;
	unsigned int OnIntervalStartCount;

	unsigned int OnNewCount;
	unsigned int OnNewNoResponseExpectedCount;
	unsigned int OnModifyCount;
	unsigned int OnModifyNoResponseExpectedCount;
	unsigned int OnCancelCount;
	unsigned int OnCancelNoResponseExpectedCount;
	unsigned int OnImplicitCancelCount;

	bool OnNewCalledFirst;

	unsigned int remainingDuration;
	unsigned int remainingIntervalDuration;
};

#endif /* OADRTEST_OADRTEST_TESTS_EVENTMANAGER_BLANKEVENTSERVICE_H_ */
