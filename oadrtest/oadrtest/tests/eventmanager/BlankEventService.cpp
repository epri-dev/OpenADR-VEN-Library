/*
 * MockEventService.cpp
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#include "BlankEventService.h"

BlankEventService::BlankEventService()
	: OnStartCount(0)
	, OnCompleteCount(0)
	, OnIntervalStartCount(0)

	, OnNewCount(0)
	, OnNewNoResponseExpectedCount(0)
	, OnModifyCount(0)
	, OnModifyNoResponseExpectedCount(0)
	, OnCancelCount(0)
	, OnCancelNoResponseExpectedCount(0)
	, OnImplicitCancelCount(0)

	, OnNewCalledFirst(false)

	, remainingDuration(0)
	, remainingIntervalDuration(0)
{
}

/********************************************************************************/

void BlankEventService::OnEventStart(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/, unsigned int remainingDurationInSeconds)
{
	OnStartCount++;
	remainingDuration = remainingDurationInSeconds;
}

/********************************************************************************/

void BlankEventService::OnEventComplete(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/)
{
	OnCompleteCount++;
}

/********************************************************************************/

void BlankEventService::OnEventIntervalStart(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/, const oadr2b::ei::eiEventSignalType */*eventSignal*/, std::string /*uid*/, float /*payload*/, time_t /*dtstart*/, unsigned int remainingDurationInSeconds)
{
	OnIntervalStartCount++;
	remainingIntervalDuration = remainingDurationInSeconds;
}

/********************************************************************************/

void BlankEventService::OnEventNew(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/, oadr2b::ei::OptTypeType::value &/*optType*/)
{
	if (OnNewCount == 0 && OnStartCount == 0)
		OnNewCalledFirst = true;

	OnNewCount++;
}

/********************************************************************************/

void BlankEventService::OnEventNew(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/)
{
	OnNewNoResponseExpectedCount++;
}

/********************************************************************************/

void BlankEventService::OnEventModify(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*newEvent*/, const oadr2b::oadr::oadrEvent */*oldEvent*/, oadr2b::ei::OptTypeType::value &/*optType*/)
{
	OnModifyCount++;
}

/********************************************************************************/

void BlankEventService::OnEventModify(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*newEvent*/, const oadr2b::oadr::oadrEvent */*oldEvent*/)
{
	OnModifyNoResponseExpectedCount++;
}

/********************************************************************************/

void BlankEventService::OnEventCancel(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/, oadr2b::ei::OptTypeType::value &/*optType*/)
{
	OnCancelCount++;
}

/********************************************************************************/

void BlankEventService::OnEventCancel(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/)
{
	OnCancelNoResponseExpectedCount++;
}

/********************************************************************************/

void BlankEventService::OnEventImplicitCancel(const std::string &/*eventID*/, const oadr2b::oadr::oadrEvent */*event*/)
{
	OnImplicitCancelCount++;
}
