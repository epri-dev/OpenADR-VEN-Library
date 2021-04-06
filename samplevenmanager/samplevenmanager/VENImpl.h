/*
 * VENImpl.h
 *
 *  Created on: Jul 8, 2015
 *      Author: dupes
 */

#ifndef SAMPLEVENMANAGER_SAMPLEVENMANAGER_VENIMPL_H_
#define SAMPLEVENMANAGER_SAMPLEVENMANAGER_VENIMPL_H_

#include <oadr/manager/eventmanager/IEventService.h>
#include <oadr/manager/reportmanager/IReportService.h>

#include <oadr/ven/IOadrMessage.h>

#include <oadr/manager/IOADRExceptionService.h>

#include "easylogging++.h"

namespace samplevenmanager
{

class VENImpl : public IEventService, public IReportService, public IOadrMessage, public IOADRExceptionService
{

public:
	VENImpl(string venName, bool logToStdout);
	~VENImpl() override;

public: // from IReportService
	void OnPeriodicReportStart(const oadrReportRequestType &reportRequest) override;

	void OnPeriodicReportComplete(const oadrReportRequestType &reportRequest) override;

	void OnGenerateOneshotReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence) override;

	void OnGeneratePeriodicReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
			unsigned int durationInSeconds) override;

	void OnGenerateHistoricalReport(const oadrReportRequestType &reportRequest, oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart,
			unsigned int durationInSeconds) override;

	void OnGenerateRegisterReport(oadrRegisterReportType::oadrReport_sequence &sequence) override;

public: // from IEventService
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

public: // from IOadrMessage
	void OnOadrMessageReceived(std::string &message) override;
	void OnOadrMessageSent(std::string &message) override;

public: // from IOADRExceptionService
	void OnCurlException(CurlException &ex) override;
	void OnException(std::exception &ex) override;
};

} /* namespace samplevenmanager */

#endif /* SAMPLEVENMANAGER_SAMPLEVENMANAGER_VENIMPL_H_ */
