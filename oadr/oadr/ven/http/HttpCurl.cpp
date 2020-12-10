//*********************************************************************************************************************
// Copyright (c) 2013, Electric Power Research Institute (EPRI)
// All rights reserved.
// 
// liboadr ("this software") is licensed under BSD 3-Clause license.
// 
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
// 
// *  Redistributions of source code must retain the above copyright notice, this 
//    list of conditions and the following disclaimer.
//    
// *  Redistributions in binary form must reproduce the above copyright notice, 
//    this list of conditions and the following disclaimer in the documentation 
//    and/or other materials provided with the distribution.
//    
// *  Neither the name of EPRI nor the names of its contributors may 
//    be used to endorse or promote products derived from this software without 
//    specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
// OF SUCH DAMAGE.
// 
// This EPRI software incorporates work covered by the following copyright and permission
// notices. You may not use these works except in compliance with their respective 
// licenses, which are provided below.
// 
// These works are provided by the copyright holders and contributors "as is" and any express or
// implied warranties, including, but not limited to, the implied warranties of merchantability
// and fitness for a particular purpose are disclaimed.
// 
// This software relies on the following libraries and licenses:
//
// #########################################################################################
// FLOSSE (released under the FLOSS exception w/a proprietary license)
// #########################################################################################
//
// This software relies on the Code Synthesis XSD generated code and the XSD runtime, 
// hereforto referred to as libxsd.  The generated code can be found under the oadrsd directory.
// The XSD headers and runtime can be found under the xsd directory. libxsd is released under
// the GPLv2 but is used and included in the source tree in compliance with a proprietary
// license, purchased from Code Synthesis, the copyright holder of libxsd.  This license
// allows EPRI to release liboadr under the BSD-3 Clause license and non-virally include
// libxsd
//
// YOU MAY USE liboadr UNDER THE TERMS OF THE BSD-3 CLAUSE LICENSE, BUT YOU MAY NOT SEPARATE
// THE libxsd COMPONENTS AND USE libxsd IN YOUR OWN PROJECT USING THE BSD-3 CLAUSE LICENSE.
//
// *  xsd generated code and runtime (version xsd-3.3.0-x86_64-linux-gnu) (http://www.codesynthesis.com/) Copyright (c) 2005-2010 Code Synthesis Tools CC
// 
// 1. Intent
// 
// We want specified Free/Libre and Open Source Software ("FLOSS") to be
// able to use the specified GPL-licensed XSD runtime library (libxsd) and
// XSD generated code (collectively called the "Program") despite the fact
// that not all FLOSS licenses are compatible with version 2 of the GNU
// General Public License (the "GPL").
// 
// It is our intent to allow distribution of the entire Derivative Work
// (including the Program) under one or more of the FLOSS licenses listed
// in section 3 (section 2.a). It is also our intent to disallow simple
// relicensing of the Program for the sole purpose of using it in
// proprietary applications (section 2.b and 2.c). As an example, consider
// two hypothetical scenarios:
// 
//  a) You created a program that uses the XSD generated code and the XSD
//     runtime library to access information in XML instance documents.
//     Your program performs useful computations based on this information
//     (sections 2.b and 2.c are satisfied). You distribute your program,
//     including the XSD generated code and the XSD runtime library under
//     the BSD license and make it available at no charge to all third
//     parties (section 2.a is satisfied). Later you (or someone else) may
//     choose to base their proprietary application on your code since the
//     BSD license does not prohibit it.
// 
//     This scenario falls under this FLOSS Exception.
// 
// 
//  b) You created a library that uses the XSD generated code and the XSD
//     runtime library to access information in XML instance documents. You
//     did not add to the library any other useful code that uses the XSD
//     generated code or the XSD runtime library (neither section 2.b nor
//     2.c is satisfied). You distribute your library, including the XSD
//     generated code and the XSD runtime library under the BSD license and
//     make it available at no charge to all third parties (section 2.a
//     is satisfied). Later you base your proprietary application on this
//     library since the BSD license does not prohibit it.
// 
//     This scenario does not fall under this FLOSS Exception (neither
//     section 2.b nor 2.c is satisfied). You created the library for the
//     sole purpose of making the XSD generated code and the XSD runtime
//     library available to your proprietary application.
// 
// 
// 2. Legal Terms and Conditions
// 
// As a special exception to the terms and conditions of version 2 of
// the GPL you are free to distribute a verbatim copy of the Program
// as part of the Derivative Work that is formed from the Program or
// any part thereof and one or more works (each, a "FLOSS Work") as
// long as you also meet all of these conditions:
// 
//   a) You must cause the Derivative Work that in whole or in part
//      contains or is derived from the Program or any part thereof,
//      to be licensed as a whole at no charge to all third parties
//      under the terms of one or more of the licenses listed in
//      section 3.
// 
//   b) The Derivative Work should contain one or more FLOSS Work that
//      can be reasonably considered as derived from the Program or some
//      part thereof.
// 
//   c) The Derivative Work should not contain any part of the Program
//      that cannot be reasonably considered as a base of one or more
//      FLOSS Work.
// 
// 
// 3. FLOSS License List
// 
//   a) Any license listed in the "GPL-Compatible Free Software Licenses"
//      and the "GPL-Incompatible Free Software Licenses" sections of the
//      License List as published by the Free Software Foundation (FSF):
// 
//      http://www.gnu.org/licenses/license-list.html
// 
// 
// 4. Definitions
// 
// Terms used, but not defined, herein shall have the meaning provided in
// the GPL.
// 
// Derivative Work means a derivative work under copyright law.
// 
// 
// 5. Applicability
// 
// You may choose to redistribute a copy of the Program exclusively under
// the terms of the GPL by removing the FLOSS Exception notice from that
// copy of the Program.
// 
// #########################################################################################
// MIT/X
// #########################################################################################
//
// *  libcurl (http://curl.haxx.se/) Copyright (c) 1996 - 2014, Daniel Stenberg, <daniel@haxx.se>.
//
// All rights reserved.
//
// Permission to use, copy, modify, and distribute this software for any purpose
// with or without fee is hereby granted, provided that the above copyright
// notice and this permission notice appear in all copies.
//  
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
// OR OTHER DEALINGS IN THE SOFTWARE.
//
// Except as contained in this notice, the name of a copyright holder shall not
// be used in advertising or otherwise to promote the sale, use or other dealings
// in this Software without prior written authorization of the copyright holder.
//
// #########################################################################################
// APACHE 2.0 Licensed Libraries
// #########################################################################################
//
// *  xerces Copyright (c) 1999-2010 The Apache Software Foundation. All Rights Reserved. 
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// #########################################################################################
// Dual OpenSSL and SSLeay
// #########################################################################################
//
// * OpenSSL (https://www.openssl.org/) Copyright (c) 1998-2011 The OpenSSL Project.  All rights reserved.
//
// /* ====================================================================
//  Copyright (c) 1998-2011 The OpenSSL Project.  All rights reserved.
// 
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
// 
//  1. Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
// 
//  2. Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in
//     the documentation and/or other materials provided with the
//     distribution.
// 
//  3. All advertising materials mentioning features or use of this
//     software must display the following acknowledgment:
//     "This product includes software developed by the OpenSSL Project
//     for use in the OpenSSL Toolkit. (http://www.openssl.org/)"
// 
//  4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to
//     endorse or promote products derived from this software without
//     prior written permission. For written permission, please contact
//     openssl-core@openssl.org.
// 
//  5. Products derived from this software may not be called "OpenSSL"
//     nor may "OpenSSL" appear in their names without prior written
//     permission of the OpenSSL Project.
// 
//  6. Redistributions of any form whatsoever must retain the following
//     acknowledgment:
//     "This product includes software developed by the OpenSSL Project
//     for use in the OpenSSL Toolkit (http://www.openssl.org/)"
// 
//  THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY
//  EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR
//  ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
//  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
//  OF THE POSSIBILITY OF SUCH DAMAGE.
//  ====================================================================
// 
//  This product includes cryptographic software written by Eric Young
//  (eay@cryptsoft.com).  This product includes software written by Tim
//  Hudson (tjh@cryptsoft.com).
// 
//
//
// Original SSLeay License
// -----------------------
//
// Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)
//  All rights reserved.
// 
//  This package is an SSL implementation written
//  by Eric Young (eay@cryptsoft.com).
//  The implementation was written so as to conform with Netscapes SSL.
// 
//  This library is free for commercial and non-commercial use as long as
//  the following conditions are aheared to.  The following conditions
//  apply to all code found in this distribution, be it the RC4, RSA,
//  lhash, DES, etc., code; not just the SSL code.  The SSL documentation
//  included with this distribution is covered by the same copyright terms
//  except that the holder is Tim Hudson (tjh@cryptsoft.com).
// 
//  Copyright remains Eric Young's, and as such any Copyright notices in
//  the code are not to be removed.
//  If this package is used in a product, Eric Young should be given attribution
//  as the author of the parts of the library used.
//  This can be in the form of a textual message at program startup or
//  in documentation (online or textual) provided with the package.
// 
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//  1. Redistributions of source code must retain the copyright
//     notice, this list of conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//  3. All advertising materials mentioning features or use of this software
//     must display the following acknowledgement:
//     "This product includes cryptographic software written by
//      Eric Young (eay@cryptsoft.com)"
//     The word 'cryptographic' can be left out if the rouines from the library
//     being used are not cryptographic related :-).
//  4. If you include any Windows specific code (or a derivative thereof) from
//     the apps directory (application code) you must include an acknowledgement:
//     "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"
// 
//  THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND
//  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
//  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
//  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//  SUCH DAMAGE.
// 
//  The licence and distribution terms for any publically available version or
//  derivative of this code cannot be changed.  i.e. this code cannot simply be
//  copied and put under another distribution licence
//  [including the GNU Public Licence.]
//
//
// #########################################################################################
// NEW BSD LICENSE (BSD-3-Clause)
// #########################################################################################
//
// * gtest (https://code.google.com/p/googletest/) Copyright 2005 Google Inc.  All rights reserved.
//

#include "HttpCurl.h"

bool HttpCurl::m_curlInitialized = false;
int HttpCurl::m_instanceCount = 0;

/********************************************************************************/

size_t writeFunction(char *ptr, size_t size, size_t nmemb, void *userdata);
size_t readFunction(void *ptr, size_t size, size_t nmemb, void *userdata);

/********************************************************************************/

HttpCurl::HttpCurl()
{
	CURLcode result;

	m_message[0] = 0;

	m_requestHeaders = NULL;
	m_clientCertificatePath = "";
	m_certificateAuthorityBundlePath = "";
	m_sslCipherList = "DEFAULT";
	m_sslVersion = CURL_SSLVERSION_DEFAULT;

	// TODO: this check is not threadsafe; use a lock
	if (!m_curlInitialized)
	{

		if ((result = curl_global_init(CURL_GLOBAL_ALL)) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}
	}

	m_curlInitialized = true;

	// init curl
	// how do we get the error code when initialiation failed?
	if ((m_curl = curl_easy_init()) == NULL)
	{
		CurlException ex((CURLcode)0, m_message);
		throw ex;
	}

	// set error buffer
	if ((result = curl_easy_setopt(m_curl, CURLOPT_ERRORBUFFER, m_message)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// enable header output
	if ((result = curl_easy_setopt(m_curl, CURLOPT_HEADER, 1)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

#ifdef _CURL_DEBUG
	// enable verbose output
	if ((result = curl_easy_setopt(m_curl, CURLOPT_VERBOSE, 1)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// redirect output to curl_output.txt
	FILE *fp = fopen("curl_output.txt", "a");

	if (fp != NULL)
	{
		if ((result = curl_easy_setopt(m_curl, CURLOPT_STDERR, fp)) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}
	}
	else
		cout << "failed to open file curl_output.txt: " << strerror(errno);

#endif

	// all requests will be posts
	if ((result = curl_easy_setopt(m_curl, CURLOPT_POST, 1L)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// set the write function
	if ((result = curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, &::writeFunction)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// set the write parameter
	if ((result = curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// set the read function
	if ((result = curl_easy_setopt(m_curl, CURLOPT_READFUNCTION, &::readFunction)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// set the read parameter
	if ((result = curl_easy_setopt(m_curl, CURLOPT_READDATA, this)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	m_requestHeaders = curl_slist_append(m_requestHeaders, "Content-Type: application/xml");

	// remove header: Expect: 100-continue
	m_requestHeaders = curl_slist_append(m_requestHeaders, "Expect:");

	m_instanceCount++;
}

/********************************************************************************/

HttpCurl::~HttpCurl()
{
	if (m_curl != NULL)
		curl_easy_cleanup(m_curl);

	m_instanceCount--;

	// TODO: not thread safe; use a lock
	if (m_instanceCount == 0)
	{
		curl_global_cleanup();
	}

	if (m_requestHeaders != NULL)
		curl_slist_free_all(m_requestHeaders);
}

/********************************************************************************/

size_t HttpCurl::readFunction(void *ptr, size_t size, size_t nmemb)
{
	return m_sendBuffer.send((char *)ptr, size * nmemb);
}

/********************************************************************************/

size_t readFunction(void *ptr, size_t size, size_t nmemb, void *userdata)
{
	HttpCurl *httpCurl = (HttpCurl *)userdata;

	return httpCurl->readFunction(ptr, size, nmemb);
}

/********************************************************************************/

size_t HttpCurl::writeFunction(char *ptr, size_t size, size_t nmemb)
{
	return m_receiveBuffer.receive(ptr, size * nmemb);
}

/********************************************************************************/

size_t writeFunction(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	HttpCurl *httpCurl = (HttpCurl *)userdata;

	return httpCurl->writeFunction(ptr, size, nmemb);
}

/********************************************************************************/

bool HttpCurl::post(string url, string content)
{
	CURLcode result;

	m_sendBuffer.initialize(content);
	m_receiveBuffer.clear();

	// set the URL
	if ((result = curl_easy_setopt(m_curl, CURLOPT_URL, url.c_str())) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	if ((result = curl_easy_setopt(m_curl, CURLOPT_POSTFIELDSIZE, content.length())) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// set the application type header
	if ((result = curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, m_requestHeaders)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// set additional parameters if an https
	if (strncmp(url.c_str(), "https", 5) == 0)
	{
		if (m_verifyCertificate)
		{
			// verify the server certificate host name matches
			if ((result = curl_easy_setopt(m_curl, CURLOPT_SSL_VERIFYHOST, 2)) != 0)
			{
				CurlException ex(result, m_message);
				throw ex;
			}

			// verify the certificate is authentic against the CA bundle
			if ((result = curl_easy_setopt(m_curl, CURLOPT_SSL_VERIFYPEER, 1)) != 0)
			{
				CurlException ex(result, m_message);
				throw ex;
			}
		}
		else
		{
			// don't verify the server certificate host name matches
			if ((result = curl_easy_setopt(m_curl, CURLOPT_SSL_VERIFYHOST, 0)) != 0)
			{
				CurlException ex(result, m_message);
				throw ex;
			}

			// verify the certificate is authentic against the CA bundle
			if ((result = curl_easy_setopt(m_curl, CURLOPT_SSL_VERIFYPEER, 0)) != 0)
			{
				CurlException ex(result, m_message);
				throw ex;
			}
		}

		// set SSL version. If SSL 1.2, then requires libcurl >= 7.34.0)
		if ((result = curl_easy_setopt(m_curl, CURLOPT_SSLVERSION, m_sslVersion)) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}

		// set SSL cipher list of allowed ciphers
		if ((result = curl_easy_setopt(m_curl, CURLOPT_SSL_CIPHER_LIST, m_sslCipherList.c_str())) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}

		// set the client certificate
		if ((result = curl_easy_setopt(m_curl, CURLOPT_SSLCERT, m_clientCertificatePath.c_str())) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}

		// set the SSL private key
		if ((result = curl_easy_setopt(m_curl, CURLOPT_SSLKEY, m_clientPrivateKeyPath.c_str())) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}

		// set certificate authority bundle
		if ((result = curl_easy_setopt(m_curl, CURLOPT_CAINFO, m_certificateAuthorityBundlePath.c_str())) != 0)
		{
			CurlException ex(result, m_message);
			throw ex;
		}
	}

	// initiate the request
	if ((result = curl_easy_perform(m_curl)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	// clear the HTTP parameters
	m_headers.clear();
	m_cookies.clear();
	m_responseBody.clear();
	m_httpVersion.clear();
	m_httpResponseCode.clear();
	m_httpResponseMessage.clear();

	m_receiveBuffer.parse(m_headers, m_cookies, m_responseBody, m_httpVersion, m_httpResponseCode, m_httpResponseMessage);

	return true;
}

/********************************************************************************/

void HttpCurl::setParameters(string clientCertificatePath, string clientPrivateKeyPath, string certificateAuthorityBundlePath, bool verifyCertificate, string sslCipherList, long sslVersion)
{
	m_clientCertificatePath = clientCertificatePath;
	m_clientPrivateKeyPath = clientPrivateKeyPath;
	m_certificateAuthorityBundlePath = certificateAuthorityBundlePath;
	m_verifyCertificate = verifyCertificate;
	m_sslCipherList = sslCipherList;
	m_sslVersion = sslVersion;
}

/********************************************************************************/

string &HttpCurl::getRequestBody()
{
	return m_sendBuffer.content();
}

/********************************************************************************/

string &HttpCurl::getResponseBody()
{
	return m_responseBody;
}

/********************************************************************************/

string &HttpCurl::getResponseCode()
{
	return m_httpResponseCode;
}

/********************************************************************************/

string &HttpCurl::getResponseMessage()
{
	return m_httpResponseMessage;
}

/********************************************************************************/

time_t HttpCurl::getResponseTime()
{
	return 0;
}

/********************************************************************************/

string &HttpCurl::getServerDate()
{
	return m_headers["Date"];
}

/********************************************************************************/

void HttpCurl::setTimeouts(long connectTimeout, long requestTimeout)
{
	CURLcode result;

	if ((result = curl_easy_setopt(m_curl, CURLOPT_CONNECTTIMEOUT, connectTimeout)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}

	if ((result = curl_easy_setopt(m_curl, CURLOPT_TIMEOUT, requestTimeout)) != 0)
	{
		CurlException ex(result, m_message);
		throw ex;
	}
}
