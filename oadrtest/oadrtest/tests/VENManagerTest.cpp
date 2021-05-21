/*
 * VENManagerTest.cpp
 *
 *  Created on: May 20, 2021
 *      Author: Michal Kowalczyk
 */

#include <gmock/gmock.h>

#include <oadr/manager/VENManager.h>

#include <oadrtest/helper/HttpDelegate.h>
#include <oadrtest/helper/LoadFile.h>
#include <oadrtest/helper/MockEventService.h>
#include <oadrtest/helper/MockOADRExceptionService.h>

#include "reportmanager/BlankReportService.h"

namespace
{
	// This class has a G prefix since there already exists MockHttp class which doesn't use GoogleMock
	// Consider porting the code using the latter mock to switch to use the former.
	class GMockHttp : public IHttp
	{
	public:
		MOCK_METHOD(bool, post, (std::string, std::string));

		MOCK_METHOD(void, setParameters, (std::string, std::string, std::string, bool, std::string, long));

		MOCK_METHOD(std::string&, getRequestBody, ());
		MOCK_METHOD(std::string&, getResponseBody, ());

		MOCK_METHOD(std::string&, getResponseCode, ());
		MOCK_METHOD(std::string&, getResponseMessage, ());

		MOCK_METHOD(time_t, getResponseTime, ());
		MOCK_METHOD(std::string&, getServerDate, ());
	};

	std::unique_ptr<IVENManager> createVENManager(IHttp &http,
	                                              IEventService &eventService,
	                                              IReportService &reportService,
	                                              IOADRExceptionService &exceptionService)
	{
		VENManagerConfig config;
		config.registerRetryInterval = std::chrono::seconds(0);
		config.exceptionRetryInterval = std::chrono::seconds(0);
		config.services.eventService = &eventService;
		config.services.reportService = &reportService;
		config.services.exceptionService = &exceptionService;
		config.services.oadrMessage = &OadrMessageBlank::oadrMessageBlank;

		return std::unique_ptr<IVENManager>(VENManager::init(config, std::unique_ptr<IHttp>(new HttpDelegate(http))));
	}
}

TEST(VENManagerTest, venGetsRegistrated_vtnRespondsToFirstPollWithReregister_getIntoUnregisteredState)
{
	using namespace testing;

	StrictMock<GMockHttp> http;
	StrictMock<MockEventService> eventService;
	BlankReportService reportService;
	StrictMock<MockOADRExceptionService> exceptionService;

	std::string createPartyRegistrationResponse = LoadFile::loadTestInputFile("created_party_registration.xml");
	std::string requestReregistration = LoadFile::loadTestInputFile("request_reregistration.xml");

	std::unique_ptr<IVENManager> venManager(createVENManager(http, eventService, reportService, exceptionService));

	const auto stopVENManager = [&]()
	{
		venManager->stop();
		return true;
	};

	// If IHttp::post() is called but none of expected calls is satisfied, let the VENManager to stop.
	ON_CALL(http, post(_, _)).WillByDefault(stopVENManager);

	// TODO: consider removing IHttp::getResponseMessage since nobody is using that
	std::string empty = "";
	EXPECT_CALL(http, getResponseMessage()).WillRepeatedly(ReturnRef(empty));

	std::string responseCode = "200";
	EXPECT_CALL(http, getResponseCode()).WillRepeatedly(ReturnRef(responseCode));

	InSequence expectCallsInSequence;
	// The first attempt to register the VEN.
	{
		// Send oadrCreatePartyRegistration and receive oadrCreatedPartyRegistration
		EXPECT_CALL(http, post(_, HasSubstr("oadrCreatePartyRegistration"))).WillOnce(Return(true));
		EXPECT_CALL(http, getResponseBody()).Times(AtLeast(1)).WillRepeatedly(ReturnRef(createPartyRegistrationResponse));

		// Send oadrRegisterReport and receive any message (it is ignored anyway)
		EXPECT_CALL(http, post(_, HasSubstr("oadrRegisterReport"))).WillOnce(Return(true));
		EXPECT_CALL(http, getResponseBody()).Times(AtLeast(1)).WillRepeatedly(ReturnRef(requestReregistration));

		// Send oadrPoll and receive oadrRequestReregistration
		EXPECT_CALL(http, post(_, HasSubstr("oadrPoll"))).WillOnce(Return(true));//.WillOnce(Return(true));
		EXPECT_CALL(http, getResponseBody()).Times(AtLeast(1)).WillRepeatedly(ReturnRef(requestReregistration));
	}
	// The second attempt to register the VEN.
	{
		// Restart the process but this time command the VENManager to stop after the process finishes
		EXPECT_CALL(http, post(_, HasSubstr("oadrCreatePartyRegistration"))).WillOnce(stopVENManager);
		EXPECT_CALL(http, getResponseBody()).Times(AtLeast(1)).WillRepeatedly(ReturnRef(createPartyRegistrationResponse));

		EXPECT_CALL(http, post(_, HasSubstr("oadrRegisterReport"))).WillOnce(Return(true));
		EXPECT_CALL(http, getResponseBody()).Times(AtLeast(1)).WillRepeatedly(ReturnRef(requestReregistration));

		EXPECT_CALL(http, post(_, HasSubstr("oadrPoll"))).WillOnce(Return(true));
		EXPECT_CALL(http, getResponseBody()).Times(AtLeast(1)).WillRepeatedly(ReturnRef(requestReregistration));
	}

	venManager->run();
}
