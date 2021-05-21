/*
 * MockEventService.h
 *
 *  Created on: May 20, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef MOCKSERVICE_H_
#define MOCKSERVICE_H_

#include <oadr/manager/eventmanager/IEventService.h>

class MockEventService : public IEventService
{
public:
	MOCK_METHOD(void, OnEventStart, (const std::string&, const oadr2b::oadr::oadrEvent*, unsigned int));
	MOCK_METHOD(void, OnEventComplete, (const std::string&, const oadr2b::oadr::oadrEvent*));
	MOCK_METHOD(void, OnEventIntervalStart, (const std::string&, const oadr2b::oadr::oadrEvent*, const oadr2b::ei::eiEventSignalType*, std::string, float, time_t, unsigned int));
	MOCK_METHOD(void, OnEventNew, (const std::string&, const oadr2b::oadr::oadrEvent*, oadr2b::ei::OptTypeType::value&));
	MOCK_METHOD(void, OnEventNew, (const std::string&, const oadr2b::oadr::oadrEvent*));
	MOCK_METHOD(void, OnEventModify, (const std::string&, const oadr2b::oadr::oadrEvent*, const oadr2b::oadr::oadrEvent*, oadr2b::ei::OptTypeType::value&));
	MOCK_METHOD(void, OnEventModify, (const std::string&, const oadr2b::oadr::oadrEvent*, const oadr2b::oadr::oadrEvent*));
	MOCK_METHOD(void, OnEventCancel, (const std::string&, const oadr2b::oadr::oadrEvent*, oadr2b::ei::OptTypeType::value&));
	MOCK_METHOD(void, OnEventCancel, (const std::string&, const oadr2b::oadr::oadrEvent*));
	MOCK_METHOD(void, OnEventImplicitCancel, (const std::string&, const oadr2b::oadr::oadrEvent*));
};

#endif /* MOCKSERVICE_H_ */
