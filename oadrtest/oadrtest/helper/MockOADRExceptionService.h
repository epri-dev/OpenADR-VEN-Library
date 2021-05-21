/*
 * MockOADRExceptionService.h
 *
 *  Created on: May 20, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef MOCKOADREXCEPTIONSERVICE_H_
#define MOCKOADREXCEPTIONSERVICE_H_

#include <oadr/manager/IOADRExceptionService.h>

class MockOADRExceptionService : public IOADRExceptionService
{
public:
	MOCK_METHOD(void, OnCurlException, (CurlException&));
	MOCK_METHOD(void, OnException, (std::exception&));
};

#endif /* MOCKOADREXCEPTIONSERVICE_H_ */
