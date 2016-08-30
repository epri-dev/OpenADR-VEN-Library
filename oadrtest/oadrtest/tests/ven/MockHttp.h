/*
 * MockHttp.h
 *
 *  Created on: May 17, 2016
 *      Author: dupes
 */

#ifndef OADRTEST_OADRTEST_TESTS_VEN_MOCKHTTP_H_
#define OADRTEST_OADRTEST_TESTS_VEN_MOCKHTTP_H_

#include <oadr/ven/http/IHttp.h>

class MockHttp : public IHttp
{
private:
	string m_requestBody;
	string m_responseBody;
	string m_responseCode;
	string m_responseMessage;
	string m_serverDate;

public:
	MockHttp();
	virtual ~MockHttp();

	bool post(string url, string content) override;

	void setParameters(string clientCertificatePath, string clientPrivateKeyPath, string certificateAuthorityBundlePath, bool verifyCertificate, string sslCipherList, long sslVersion) override;

	string &getRequestBody() override;
	string &getResponseBody() override;

	string &getResponseCode() override;
	string &getResponseMessage() override;

	time_t getResponseTime() override;
	string &getServerDate() override;

	void setRequestBody(string requestBody);
	void setResponseBody(string responseBody);
	void setResponseCode(string responseCode);
	void setResponseMessage(string responseMessage);
	void setServerDate(string serverDate);
};

#endif /* OADRTEST_OADRTEST_TESTS_VEN_MOCKHTTP_H_ */
