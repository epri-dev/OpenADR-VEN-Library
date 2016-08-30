/*
 * VENManagerConfig.h
 *
 *  Created on: May 17, 2016
 *      Author: dupes
 */

#ifndef OADR_OADR_MANAGER_VENMANAGERCONFIG_H_
#define OADR_OADR_MANAGER_VENMANAGERCONFIG_H_

#include <string>

// TODO: needed for TLS default version
// remove reliance on curl
#include <curl/curl.h>

#include "eventmanager/IEventService.h"
#include "reportmanager/IReportService.h"
#include "IOADRExceptionService.h"
#include "../ven/IOadrMessage.h"

struct ttls
{
	bool useTls;

	std::string certPath;
	std::string privateKeyPath;
	std::string caBundlePath;
	bool verifyHostname;
	std::string cipherList;
	long sslVersion;
};

struct tservices
{
	IEventService *eventService;
	IReportService *reportService;
	IOADRExceptionService *exceptionService;
	IOadrMessage *oadrMessage;
};

struct ttimeouts
{
	unsigned int connectTimeout;
	unsigned int requestTimeout;
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

	VENManagerConfig()
	{
		tls.useTls = false;
		tls.verifyHostname = true;
		tls.cipherList = "AES128-SHA256:ECDHE-ECDSA-AES128-SHA256";
		tls.sslVersion = CURL_SSLVERSION_TLSv1_2;

		services.eventService = NULL;
		services.reportService = NULL;
		services.exceptionService = NULL;
		services.oadrMessage = &OadrMessageBlank::oadrMessageBlank;

		timeouts.connectTimeout = 120;
		timeouts.requestTimeout = 30;
	};
};

#endif /* OADR_OADR_MANAGER_VENMANAGERCONFIG_H_ */
