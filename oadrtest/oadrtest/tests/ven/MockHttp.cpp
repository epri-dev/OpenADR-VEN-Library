/*
 * MockHttp.cpp
 *
 *  Created on: May 17, 2016
 *      Author: dupes
 */

#include "MockHttp.h"

MockHttp::MockHttp()
{
	m_responseCode = "200";
	m_responseMessage = "OK";
}

MockHttp::~MockHttp()
{
}

bool MockHttp::post(string url, string content)
{
	m_requestBody = content;

	return true;
}

void MockHttp::setParameters(string clientCertificatePath,
		string clientPrivateKeyPath, string certificateAuthorityBundlePath,
		bool verifyCertificate, string sslCipherList, long sslVersion)
{
}

string& MockHttp::getRequestBody()
{
	return m_requestBody;
}

string& MockHttp::getResponseBody()
{
	return m_responseBody;
}

string& MockHttp::getResponseCode()
{
	return m_responseCode;
}

string& MockHttp::getResponseMessage()
{
	return m_responseMessage;
}

time_t MockHttp::getResponseTime()
{
	return 0;
}

string& MockHttp::getServerDate()
{
	return m_serverDate;
}

void MockHttp::setRequestBody(string requestBody)
{
	m_requestBody = requestBody;
}

void MockHttp::setResponseBody(string responseBody)
{
	m_responseBody = responseBody;
}

void MockHttp::setResponseCode(string responseCode)
{
	m_responseCode = responseCode;
}

void MockHttp::setResponseMessage(string responseMessage)
{
	m_responseMessage = responseMessage;
}

void MockHttp::setServerDate(string serverDate)
{
	m_serverDate = serverDate;
}
