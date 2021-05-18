/*
 * VENManagerConfig.cpp
 *
 *  Created on: Feb 22, 2021
 *      Author: Michał Kowalczyk
 */


#include "../manager/VENManagerConfig.h"

#include <curl/curl.h>

#include "../ven/IOadrMessage.h"

ttls::ttls() :
	useTls(false),
	privateKeyPath(),
	caBundlePath(),
	verifyHostname(true),
	cipherList("AES128-SHA256:ECDHE-ECDSA-AES128-SHA256"),
	sslVersion(CURL_SSLVERSION_TLSv1_2)
{
}

tsignature::tsignature() :
	certPath(),
	signingKeyPath(),
	caBundlePath(),
	canonicalizationMethod(),
	signatureMethod(),
	digestMethod()
{
}

tservices::tservices() :
	eventService(nullptr),
	reportService(nullptr),
	exceptionService(nullptr),
	oadrMessage(&OadrMessageBlank::oadrMessageBlank)
{
}

ttimeouts::ttimeouts() :
	connectTimeout(120),
	requestTimeout(30)
{
}

VENManagerConfig::VENManagerConfig() :
	vtnURL(),
	venName(),
	venID(),
	registrationID(),
	tls(),
	services(),
	timeouts(),
	registerRetryInterval(10),
	exceptionRetryInterval(10)
{
}
