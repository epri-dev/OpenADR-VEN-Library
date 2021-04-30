/*
 * VENManagerConfig.h
 *
 *  Created on: May 17, 2016
 *      Author: dupes
 */

#ifndef OADR_OADR_MANAGER_VENMANAGERCONFIG_H_
#define OADR_OADR_MANAGER_VENMANAGERCONFIG_H_

#include <chrono>
#include <string>

class IEventService;
class IReportService;
class IOADRExceptionService;
class IOadrMessage;

struct ttls
{
	bool useTls;

	std::string certPath;
	std::string privateKeyPath;
	std::string caBundlePath;
	bool verifyHostname;
	std::string cipherList;
	long sslVersion;

	ttls();
};

struct tsignature
{
	std::string certPath;
	std::string signingKeyPath;
	std::string caBundlePath;

	tsignature();
};

struct tservices
{
	IEventService *eventService;
	IReportService *reportService;
	IOADRExceptionService *exceptionService;
	IOadrMessage *oadrMessage;

	tservices();
};

struct ttimeouts
{
	unsigned int connectTimeout;
	unsigned int requestTimeout;

	ttimeouts();
};

struct VENManagerConfig
{
	std::string vtnURL;
	std::string venName;
	std::string venID;
	std::string registrationID;

	ttls tls;

	tservices services;

	ttimeouts timeouts;

	tsignature signature;

	std::chrono::seconds registerRetryInterval;
	std::chrono::seconds exceptionRetryInterval;

	VENManagerConfig();
};

#endif /* OADR_OADR_MANAGER_VENMANAGERCONFIG_H_ */
