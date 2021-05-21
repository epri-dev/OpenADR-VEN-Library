
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

#include <gtest/gtest.h>

#include <oadr/ven/VEN2b.h>
#include <oadr/helper/OadrPayloadHelpers.h>
#include <oadr/helper/SignatureContext.h>

#include <oadrtest/helper/HttpDelegate.h>
#include <oadrtest/helper/LoadFile.h>
#include <oadrtest/helper/MockGlobalTime.h>

#include "MockHttp.h"

namespace
{
	/**
	 * This delegate allows to release ownership to the client and keep ownership
	 * over actual instantiation. For usage, check examples below.
	 */
	class SignatureContextDelegate : public ISignatureContext
	{
	private:
		ISignatureContext &m_signatureContext;

	public:
		SignatureContextDelegate(ISignatureContext &signatureContext)
		: m_signatureContext(signatureContext)
		{
		}

		std::string sign(oadr2b::oadr::oadrPayload &payload)
		{
			return m_signatureContext.sign(payload);
		}

		bool verify(oadr2b::oadr::oadrPayload &payload)
		{
			return m_signatureContext.verify(payload);
		}
	};

	std::unique_ptr<SignatureContext> createSignatureContext()
	{
		return std::unique_ptr<SignatureContext>(new SignatureContext(
				"xml/oadrtest/test_input/signatures/certificate-attached-to-signature.der",
				"xml/oadrtest/test_input/signatures/private-key-for-signing.der",
				"xml/oadrtest/test_input/signatures/certificate-authority-bundle-for-verifying-signatures.pem",
				"http://www.w3.org/TR/2001/REC-xml-c14n-20010315",
				"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256",
				"http://www.w3.org/2001/04/xmlenc#sha256"));
	}

	const string url = "url";
	const string venName = "venName_unique";
	const string venId = "venId_unique";
	const string registrationId = "registrationId_unique";
}

class VEN2bTest : public testing::Test
{
protected:
	MockHttp http;
};

/********************************************************************************/

TEST_F(VEN2bTest, Registration)
{
	VEN2b ven(unique_ptr<IHttp>(new HttpDelegate(http)), url, venName, venId, registrationId);

	EXPECT_FALSE(ven.isRegistered()) << " should start in an unregistered state";

	http.setResponseBody(LoadFile::loadTestInputFile("created_party_registration.xml"));

	ven.createPartyRegistration(oadrProfileType::cxx_2_0b,
			oadrTransportType::simpleHttp,
			"", false, false, true);

	EXPECT_TRUE(ven.isRegistered()) << " should be a registered state after successful registration";

	EXPECT_EQ("752e4cc6c5413baa1a80", ven.registrationID()) << " registration ID should be set from response message";
	EXPECT_EQ("edac8fec7527cb960967", ven.venID()) << " ven ID should be set from response message";

	ven.clearRegistration();

	EXPECT_FALSE(ven.isRegistered()) << " should unregistered after calling clearRegistration";

	EXPECT_EQ(venId, ven.venID()) << " ven ID should match the default ven id";
	EXPECT_EQ(registrationId, ven.registrationID()) << "ven ID should match the default ven id";

	EXPECT_TRUE(http.getRequestBody().find(venId) !=  string::npos) << " should use original ven ID";
	EXPECT_TRUE(http.getRequestBody().find(registrationId) !=  string::npos) << " should use original registration ID";
}

/********************************************************************************/

TEST_F(VEN2bTest, RegistrationFail)
{
	VEN2b ven(unique_ptr<IHttp>(new HttpDelegate(http)), url, venName, venId, registrationId);

	http.setResponseBody(LoadFile::loadTestInputFile("created_party_registration-invalid-ven-name.xml"));

	ven.createPartyRegistration(oadrProfileType::cxx_2_0b,
			oadrTransportType::simpleHttp,
			"", false, false, true);

	EXPECT_FALSE(ven.isRegistered()) << " should not be registered after unsuccessful registration";
}

/********************************************************************************/

TEST_F(VEN2bTest, venHasSignatureContext_whenRequestIsSent_signatureCanBeVerified)
{
	http.setResponseBody(LoadFile::loadTestInputFile("created_party_registration-with-signature.xml"));

	MockGlobalTime globalTime;
	globalTime.setNow(2019, 9, 11, 20, 42, 0);

	auto signatureContext = createSignatureContext();

	VEN2b ven(unique_ptr<IHttp>(new HttpDelegate(http)), url, venName, venId, registrationId,
	          std::unique_ptr<ISignatureContext>(new SignatureContextDelegate(*signatureContext)));

	EXPECT_FALSE(ven.isRegistered()) << " should start in an unregistered state";

	EXPECT_NO_THROW(ven.createPartyRegistration(oadrProfileType::cxx_2_0b,
			oadrTransportType::simpleHttp,
			"", false, false, true));

	EXPECT_TRUE(ven.isRegistered()) << " should be a registered state after successful registration";

	EXPECT_TRUE(signatureContext->verify(*to_oadrPayload(http.getRequestBody())));
}

/********************************************************************************/

TEST_F(VEN2bTest, venSendsSignedRequest_whenResponseComesTooLate_responseIsIgnored)
{
	// The response should be sent at 20:42:06
	http.setResponseBody(LoadFile::loadTestInputFile("created_party_registration-with-signature.xml"));

	MockGlobalTime globalTime;

	auto signatureContext = createSignatureContext();

	VEN2b ven(unique_ptr<IHttp>(new HttpDelegate(http)), url, venName, venId, registrationId,
	          std::unique_ptr<ISignatureContext>(new SignatureContextDelegate(*signatureContext)));

	EXPECT_FALSE(ven.isRegistered()) << " should start in an unregistered state";

	// after 5 seconds messages got rejected
	globalTime.setNow(2019, 9, 11, 20, 42, 6);
	EXPECT_NO_THROW(ven.createPartyRegistration(oadrProfileType::cxx_2_0b,
			oadrTransportType::simpleHttp,
			"", false, false, true));

	EXPECT_FALSE(ven.isRegistered()) << " should stay in an unregistered state since the response was rejected";
}

/********************************************************************************/

class Ven2bInvalidSignatureTest : public VEN2bTest, public testing::WithParamInterface<const char*>
{
};

/********************************************************************************/

TEST_P(Ven2bInvalidSignatureTest, rejectResponse)
{
	const char *responsePath = GetParam();

	http.setResponseBody(LoadFile::loadTestInputFile(responsePath));

	MockGlobalTime globalTime;
	globalTime.setNow(2019, 9, 11, 20, 42, 0);

	auto signatureContext = createSignatureContext();

	VEN2b ven(unique_ptr<IHttp>(new HttpDelegate(http)), url, venName, venId, registrationId,
	          std::unique_ptr<ISignatureContext>(new SignatureContextDelegate(*signatureContext)));

	EXPECT_FALSE(ven.isRegistered()) << " should start in an unregistered state";

	EXPECT_NO_THROW(ven.createPartyRegistration(oadrProfileType::cxx_2_0b,
			oadrTransportType::simpleHttp,
			"", false, false, true));

	EXPECT_FALSE(ven.isRegistered()) << " should stay in an unregistered state since the response was rejected";
}

/********************************************************************************/

INSTANTIATE_TEST_CASE_P(
		Ven2bInvalidSignatureTest,
		Ven2bInvalidSignatureTest,
		testing::Values(
				"created_party_registration-with-signature-tampered.xml",
				"created_party_registration-with-signature-empty-nonce.xml",
				"created_party_registration-with-signature-two-oadrSignedObject.xml",
				"created_party_registration-with-signature-no-reference-to-oadrSignedObject.xml",
				"created_party_registration-with-signature-no-reference-to-ReplayProtect.xml",
				"created_party_registration-with-signature-wrong-certificate.xml",
				"created_party_registration-with-signature-timestamp-missing.xml"
		));
