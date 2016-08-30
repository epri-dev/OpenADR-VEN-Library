/*
 * JobEventStart.h
 *
 *  Created on: Jun 22, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTSTART_H_
#define OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTSTART_H_

#include <oadrsd/2b/oadr_20b.hxx>

#include "../../../../scheduler/IJob.h"
#include "../../IEventService.h"

class JobEventStart : public IJob
{
private:
	IEventService *m_service;
	const oadr2b::oadr::oadrEvent *m_event;

public:
	JobEventStart(IEventService *service, const oadr2b::oadr::oadrEvent *event);
	virtual ~JobEventStart();

	virtual void execute(time_t now);
};

#endif /* OADR_OADR_VEN_VENMANAGER_JOB_EVENT_JOBEVENTSTART_H_ */
