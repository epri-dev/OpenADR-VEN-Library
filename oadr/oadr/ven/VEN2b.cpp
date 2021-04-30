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

#include "VEN2b.h"

const string VEN2b::_EndpointEiEvent = "/OpenADR2/Simple/2.0b/EiEvent";
const string VEN2b::_EndpointEiReport = "/OpenADR2/Simple/2.0b/EiReport";
const string VEN2b::_EndpointEiRegisterParty = "/OpenADR2/Simple/2.0b/EiRegisterParty";
const string VEN2b::_EndpointEiOpt = "/OpenADR2/Simple/2.0b/EiOpt";
const string VEN2b::_EndpointEiPoll = "/OpenADR2/Simple/2.0b/OadrPoll";

/********************************************************************************/

VEN2b::VEN2b(unique_ptr<IHttp> http,
             string baseURL,
             string venName,
             string venID,
             string registrationID,
             std::unique_ptr<ISignatureContext> signatureContext) :
	m_http(std::move(http)),
	m_baseURL(baseURL),
	m_venName(venName),
	m_venID(venID),
	m_registrationID(registrationID),
	m_signatureContext(std::move(signatureContext)),
	m_defaultVenID(venID),
	m_defaultRegistrationID(registrationID),
	m_isRegistered(false)
{
	m_oadrMessage = &OadrMessageBlank::oadrMessageBlank;

	// initialize xerces; required for some of the code synthesis parsing routines
	// xerces does initialization counting so for each Initialize() call we must have the Terminate() counterpart.
	XMLPlatformUtils::Initialize();
}

/********************************************************************************/

VEN2b::~VEN2b()
{
	// cleanup xerces
	XMLPlatformUtils::Terminate();
}

/********************************************************************************/

string VEN2b::venID()
{
	return m_venID;
}

/********************************************************************************/

string VEN2b::registrationID()
{
	return m_registrationID;
}

/********************************************************************************/

string VEN2b::vtnID()
{
	return m_vtnID;
}

/********************************************************************************/

void VEN2b::setOadrMessage(IOadrMessage *oadrMessage)
{
	m_oadrMessage = oadrMessage;
}

/********************************************************************************/

string VEN2b::pollFrequency()
{
	return m_pollFrequency;
}

/********************************************************************************/

bool VEN2b::isRegistered()
{
	return m_isRegistered;

	return true;
}

/********************************************************************************/

void VEN2b::postRequest(Oadr2bRequest *request, string endPoint)
{
	std::unique_lock<std::mutex> lock(m_mutex);

	string requestBody = request->generateRequestXML(m_signatureContext.get());

	m_oadrMessage->OnOadrMessageSent(requestBody);

	m_http->post(m_baseURL + endPoint, requestBody);

	m_oadrMessage->OnOadrMessageReceived(m_http->getResponseBody());

	request->setHttpFields(requestBody, m_http->getResponseBody(), m_http->getResponseCode(), m_http->getResponseMessage(), m_signatureContext.get());
}

/********************************************************************************/

unique_ptr<RequestEvent> VEN2b::requestEvent(string requestID, unsigned int replyLimit)
{
	unique_ptr<RequestEvent> request(new RequestEvent(m_venID, requestID, replyLimit));

	postRequest(request.get(), _EndpointEiEvent);

	return request;
}

/********************************************************************************/

void VEN2b::setIDs(oadrCreatedPartyRegistrationType *cpr)
{
	m_venID = (cpr->venID().present() ? *cpr->venID() : "");
	m_registrationID = (cpr->registrationID().present() ? *cpr->registrationID() : "");

	m_vtnID = cpr->vtnID();

	m_pollFrequency = cpr->oadrRequestedOadrPollFreq()->duration();

	m_isRegistered = true;
}

/********************************************************************************/

unsigned int VEN2b::pollFrequencyInSeconds()
{
	return ISO8601Duration::TotalSeconds(m_pollFrequency);
}

/********************************************************************************/

unique_ptr<QueryRegistration> VEN2b::queryRegistration(string requestID)
{
	unique_ptr<QueryRegistration> request(new QueryRegistration(requestID));

	postRequest(request.get(), _EndpointEiRegisterParty);

	// the response should be a oadrCreatedPartyRegistration which contains the VEN ID and
	// registration ID which are needed for future communications
	if (request->response() != NULL && request->response()->oadrSignedObject().oadrCreatedPartyRegistration().present())
	{
		if (request->response()->oadrSignedObject().oadrCreatedPartyRegistration()->eiResponse().responseCode().compare("200") == 0)
		{
			oadrCreatedPartyRegistrationType *cpr = &request->response()->oadrSignedObject().oadrCreatedPartyRegistration().get();

			if (cpr->venID().present() && cpr->venID()->compare("") != 0)
				setIDs(cpr);
		}
	}

	return request;
}

/********************************************************************************/

unique_ptr<CreatePartyRegistration> VEN2b::createPartyRegistration(oadrProfileType profileType, oadrTransportType transportType,
		string transportAddress,
		bool reportOnly, bool xmlSignature, bool httpPullModel, string requestID)
{
	unique_ptr<CreatePartyRegistration> request(new CreatePartyRegistration(m_venID, requestID, m_registrationID,
			profileType, transportType, transportAddress, reportOnly, xmlSignature, m_venName, httpPullModel));

	postRequest(request.get(), _EndpointEiRegisterParty);

	// the response should be a oadrCreatedPartyRegistration which contains the VEN ID and
	// registration ID which are needed for future communications
	if (request->response() != NULL && request->response()->oadrSignedObject().oadrCreatedPartyRegistration().present())
	{
		if (request->response()->oadrSignedObject().oadrCreatedPartyRegistration()->eiResponse().responseCode().compare("200") == 0)
		{
			oadrCreatedPartyRegistrationType *cpr = &request->response()->oadrSignedObject().oadrCreatedPartyRegistration().get();

			setIDs(cpr);
		}
	}

	return request;
}

/********************************************************************************/

unique_ptr<CancelPartyRegistration> VEN2b::cancelPartyRegistration(string requestID)
{
	unique_ptr<CancelPartyRegistration> request(new CancelPartyRegistration(m_venID, m_registrationID, requestID));

	postRequest(request.get(), _EndpointEiRegisterParty);

	if (request->response() != NULL && request->response()->oadrSignedObject().oadrCreatedPartyRegistration().present())
	{
		string responseCode = request->response()->oadrSignedObject().oadrCreatedPartyRegistration()->eiResponse().responseCode();

		// if the response indicates OK, the request was successful
		// 453 indicates the registrationID was invalid
		// any other return should indicate the cancel was not successful
		if (responseCode.compare("200") == 0 || responseCode.compare("453") == 0)
			clearRegistration();
	}

	return request;
}

/********************************************************************************/

void VEN2b::clearRegistration()
{
	m_venID = m_defaultVenID;
	m_registrationID = m_defaultRegistrationID;

	m_isRegistered = false;
}

/********************************************************************************/

unique_ptr<CreatedEvent> VEN2b::createdEvent(string responseCode, string responseDescription, eventResponses::eventResponse_sequence &ers, string requestID)
{
	unique_ptr<CreatedEvent> request(new CreatedEvent(m_venID, responseCode, responseDescription, ers, requestID));

	postRequest(request.get(), _EndpointEiEvent);

	return request;
}

/********************************************************************************/

unique_ptr<RegisterReport> VEN2b::registerReport(oadrRegisterReportType::oadrReport_sequence sequence, string requestID)
{
	unique_ptr<RegisterReport> request(new RegisterReport(m_venID, requestID, sequence));

	postRequest(request.get(), _EndpointEiReport);

	return request;
}

/********************************************************************************/

unique_ptr<RegisteredReport> VEN2b::registeredReport(string requestID, string responseCode, string responseDescription)
{
	unique_ptr<RegisteredReport> request(new RegisteredReport(venID(), requestID, responseCode, responseDescription));

	postRequest(request.get(), _EndpointEiReport);

	return request;
}

/********************************************************************************/

unique_ptr<CreatedReport> VEN2b::createdReport(string requestID, string responseCode, string responseDescription, const set<string> &pendingReports)
{
	unique_ptr<CreatedReport> request(new CreatedReport(venID(), pendingReports, responseCode, responseDescription, requestID));

	postRequest(request.get(), _EndpointEiReport);

	return request;
}

/********************************************************************************/

unique_ptr<CanceledReport> VEN2b::canceledReport(string requestID, string responseCode, string responseDescription, const set<string> &pendingReports)
{
	unique_ptr<CanceledReport> request(new CanceledReport(venID(), responseCode, responseDescription, pendingReports, requestID));

	postRequest(request.get(), _EndpointEiReport);

	return request;
}

/********************************************************************************/

unique_ptr<UpdateReport> VEN2b::updateReport(oadrUpdateReportType::oadrReport_sequence &sequence, time_t dtstart, string reportRequestID, time_t createdDateTime, string requestID)
{
	unique_ptr<UpdateReport> request(new UpdateReport(m_venID, requestID, sequence, dtstart, reportRequestID, createdDateTime));

	postRequest(request.get(), _EndpointEiReport);

	return request;
}

/********************************************************************************/

unique_ptr<CreateOptSchedule> VEN2b::createOptSchedule(OptSchedule &optSchedule, string requestID)
{
	unique_ptr<CreateOptSchedule> request(new CreateOptSchedule(m_venID, optSchedule, requestID));

	postRequest(request.get(), _EndpointEiOpt);

	return request;
}

/********************************************************************************/

unique_ptr<CancelOptSchedule> VEN2b::cancelOptSchedule(string optID, string requestID)
{
	unique_ptr<CancelOptSchedule> request(new CancelOptSchedule(m_venID, optID, requestID));

	postRequest(request.get(), _EndpointEiOpt);

	return request;
}

/********************************************************************************/

unique_ptr<Poll> VEN2b::poll()
{
	unique_ptr<Poll> request(new Poll(m_venID));

	postRequest(request.get(), _EndpointEiPoll);

	return request;
}
