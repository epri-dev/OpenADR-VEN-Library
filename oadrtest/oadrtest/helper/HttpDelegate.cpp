/*
 * HttpDelegate.cpp
 *
 *  Created on: May 20, 2021
 *      Author: Michal Kowalczyk
 */

#include "HttpDelegate.h"

HttpDelegate::HttpDelegate(IHttp &http)
: m_http(http)
{
}

bool HttpDelegate::post(std::string url, std::string content)
{
	return m_http.post(url, content);
}

void HttpDelegate::setParameters(std::string clientCertificatePath,
                   std::string clientPrivateKeyPath,
                   std::string certificateAuthorityBundlePath,
                   bool verifyCertificate,
                   std::string sslCipherList,
                   long sslVersion)
{
	return m_http.setParameters(clientCertificatePath,
	                     clientPrivateKeyPath,
	                     certificateAuthorityBundlePath,
	                     verifyCertificate,
	                     sslCipherList,
	                     sslVersion);
}

std::string &HttpDelegate::getRequestBody()
{
	return m_http.getRequestBody();
}

std::string &HttpDelegate::getResponseBody()
{
	return m_http.getResponseBody();
}

std::string &HttpDelegate::getResponseCode()
{
	return m_http.getResponseCode();
}

std::string &HttpDelegate::getResponseMessage()
{
	return m_http.getResponseMessage();
}

time_t HttpDelegate::getResponseTime()
{
	return m_http.getResponseTime();
}

std::string &HttpDelegate::getServerDate()
{
	return m_http.getServerDate();
}

void HttpDelegate::setTimeouts(long connectTimeout, long requestTimeout)
{
	m_http.setTimeouts(connectTimeout, requestTimeout);
}
