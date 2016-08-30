//
// Created by dupes on 12/9/15.
//

#ifndef OADR_JOBSLOW_H
#define OADR_JOBSLOW_H

#include "../../helper/MockGlobalTime.h"

#include <oadr/scheduler/IJob.h>

class JobSlow : public IJob
{
private:
    MockGlobalTime *m_globalTime;

public:
    JobSlow(MockGlobalTime *globalTime);
    ~JobSlow();

    virtual void execute(time_t now);
};


#endif //OADR_JOBSLOW_H
