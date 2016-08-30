/*
 * JobLambda.h
 *
 *  Created on: Jul 7, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_SCHEDULER_JOBLAMBDA_H_
#define OADR_OADR_SCHEDULER_JOBLAMBDA_H_

#include "IJob.h"

#include <functional>

class JobLambda : public IJob
{
private:
	std::function<void (time_t)> m_function;

public:
	JobLambda(const std::function<void (time_t)> &function);

	virtual ~JobLambda();

	virtual void execute(time_t now);
};

#endif /* OADR_OADR_SCHEDULER_JOBLAMBDA_H_ */
