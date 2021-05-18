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
	/*
	 * The path to the certificate attached to a signed XML document. Must use the DER format.
	 * The contents are cached in course of running the VENManager, so whenever the certificate must be changed,
	 * the process must be restarted.
	 */
	std::string certPath;

	/*
	 * The path to the private key used for signing an XML document. Must use the DER format.
	 * The key type (RSA vs EC) must match the signatureMethod.
	 * The contents are cached in course of running the VENManager, so whenever the key must be changed,
	 * the process must be restarted.
	 */
	std::string signingKeyPath;

	/*
	 * The path to the X509 certification authority bundle that is used when verifying signatures of
	 * incoming messages. Must be a concatenation of the X509 certicate chain in the PEM format.
	 * The contents are NOT cached in course of running the VENManager. If the CA bundle changes,
	 * it is reread and applied for consecutive incoming messages.
	 */
	std::string caBundlePath;

	/*
	 * The algorithm for transforming an XML document into canonical form.
	 * The OpenADR 2.0b standard allows following values:
	 * - http://www.w3.org/TR/2001/REC-xml-c14n-20010315
	 * - http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments
	 */
	std::string canonicalizationMethod;

	/*
	 * The algorithm for signing XML document elements.
	 * The type of signing key must match the signature method (RSA vs EC).
	 * The OpenADR 2.0b standard allows following values:
	 * - http://www.w3.org/2000/09/xmldsig#rsa-sha1
	 * - http://www.w3.org/2001/04/xmldsig-more#rsa-sha256
	 * - http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1
	 * - http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256
	 */
	std::string signatureMethod;

	/*
	 * The algorithm for computing digest of signed XML document elements.
	 * The OpenADR 2.0b standard allows following values:
	 * - http://www.w3.org/2000/09/xmldsig#sha1
	 * - http://www.w3.org/2001/04/xmlenc#sha256
	 */
	std::string digestMethod;

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
