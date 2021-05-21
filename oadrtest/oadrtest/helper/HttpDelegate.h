/*
 * HttpDelegate.h
 *
 *  Created on: May 20, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef HTTPDELEGATE_H_
#define HTTPDELEGATE_H_

#include <oadr/ven/http/IHttp.h>

class HttpDelegate : public IHttp
{
private:
	IHttp &m_http;

public:
	HttpDelegate(IHttp &http);

	bool post(std::string url, std::string content) override;

	void setParameters(std::string clientCertificatePath,
	                   std::string clientPrivateKeyPath,
	                   std::string certificateAuthorityBundlePath,
	                   bool verifyCertificate,
	                   std::string sslCipherList,
	                   long sslVersion) override;

	std::string &getRequestBody() override;

	std::string &getResponseBody() override;

	std::string &getResponseCode() override;

	std::string &getResponseMessage() override;

	time_t getResponseTime() override;

	std::string &getServerDate() override;

	void setTimeouts(long connectTimeout, long requestTimeout) override;
};

#endif /* HTTPDELEGATE_H_ */
