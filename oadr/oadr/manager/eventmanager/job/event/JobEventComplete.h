/*
 * JobEventComplete.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTCOMPLETE_H_
#define OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTCOMPLETE_H_

#include "../../../../scheduler/IJob.h"
#include "../../IEventService.h"

class JobEventComplete : public IJob
{
private:
	IEventService *m_service;
	const oadr2b::oadr::oadrEvent *m_event;

public:
	JobEventComplete(IEventService *service, const oadr2b::oadr::oadrEvent *event);
	virtual ~JobEventComplete();

	virtual void execute(time_t now);
};

#endif /* OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTCOMPLETE_H_ */
