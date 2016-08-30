/*
 * IOADRExceptionService.h
 *
 *  Created on: May 27, 2016
 *      Author: dupes
 */

#ifndef OADR_OADR_MANAGER_IOADREXCEPTIONSERVICE_H_
#define OADR_OADR_MANAGER_IOADREXCEPTIONSERVICE_H_

#include <exception>

#include "../ven/http/CurlException.h"

class IOADRExceptionService
{
public:
	IOADRExceptionService();
	virtual ~IOADRExceptionService();

	virtual void OnCurlException(CurlException &ex) = 0;

	virtual void OnException(std::exception &ex) = 0;
};

#endif /* OADR_OADR_MANAGER_IOADREXCEPTIONSERVICE_H_ */
