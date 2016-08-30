//
// Created by dupes on 12/9/15.
//

#include "JobSlow.h"


JobSlow::JobSlow(MockGlobalTime *globalTime) :
        m_globalTime(globalTime)
{
}

/********************************************************************************/

JobSlow::~JobSlow()
{
}

/********************************************************************************/

void JobSlow::execute(time_t now)
{
    m_globalTime->setNow(now + 200);
}
