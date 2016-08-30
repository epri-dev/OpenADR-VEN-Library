/*
 * JobEventIntervalStart.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTINTERVALSTART_H_
#define OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTINTERVALSTART_H_

#include "../../../../scheduler/IJob.h"
#include "../../IEventService.h"

class JobEventIntervalStart : public IJob
{
private:
	IEventService *m_service;
	const oadr2b::oadr::oadrEvent *m_event;
	const oadr2b::ei::eiEventSignalType *m_eventSignal;

	string m_uid;
	float m_payload;

	time_t m_dtstart;
	unsigned int m_durationInSeconds;

public:
	JobEventIntervalStart(IEventService *service, const oadr2b::oadr::oadrEvent *event, const oadr2b::ei::eiEventSignalType *eventSignal, string uid, float payload, time_t dtstart, int durationInSeconds);
	virtual ~JobEventIntervalStart();

	virtual void execute(time_t now);
};

#endif /* OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTINTERVALSTART_H_ */
