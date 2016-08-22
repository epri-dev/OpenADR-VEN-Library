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

#include "ReportWrapper.h"

/********************************************************************************/

ReportWrapper::ReportWrapper(ReportName *reportName, int duration, DurationModifier *durationModifier, string reportSpecifierID, time_t createDateTime) :
	m_reportName(reportName),
	m_duration(duration),
	m_durationModifier(durationModifier),
	m_createDateTime(createDateTime)
{

	m_reportSpecifierID = (reportSpecifierID != "" ? reportSpecifierID : RandomHex::instance()->generateRandomHex());
}

/********************************************************************************/

ReportWrapper::~ReportWrapper()
{
	while (m_reportDescriptions.size() > 0)
	{
		oadrReportDescriptionType *reportDescription = m_reportDescriptions.begin()->second;
		m_reportDescriptions.erase(reportDescription->rID());

		delete (reportDescription);
	}
}

/********************************************************************************/

string ReportWrapper::reportSpecifierID()
{
	return m_reportSpecifierID;
}

/********************************************************************************/

void ReportWrapper::addDescription(string rID, string resourceID, ReportEnumeratedType::value reportType,
		ReadingTypeEnumeratedType::value readingType, string marketContext,
		int minSamplingPeriod, int maxSamplingPeriod, bool onChange, DurationModifier *durationModifier,
		auto_ptr<oadrReportDescriptionType::itemBase_type> measuredValue)
{
	string reportTypeString = ReportEnumeratedTypeValue(reportType).toString();
	string readingTypeString = ReadingTypeEnumeratedTypeValue(readingType).toString();

	oadrReportDescriptionType *reportDescription = new oadrReportDescriptionType(rID, reportTypeString, readingTypeString);

	oadrReportDescriptionType::marketContext_type mc(marketContext);
	reportDescription->marketContext(mc);

	if (resourceID != "")
	{
		EiTargetType eitt;

		EiTargetType::resourceID_sequence rid_seq;

		rid_seq.push_back(resourceID);

		eitt.resourceID(rid_seq);

		reportDescription->reportDataSource(eitt);
	}

	oadrSamplingRateType samplingRate(Oadr2bHelper::generateDurationValueType(minSamplingPeriod, durationModifier),
			Oadr2bHelper::generateDurationValueType(maxSamplingPeriod, durationModifier),
			onChange);

	reportDescription->oadrSamplingRate(samplingRate);

	reportDescription->itemBase(measuredValue);

	m_reportDescriptions[rID] = reportDescription;
}

/********************************************************************************/

void ReportWrapper::addDescriptionResourceStatus(string rID, string resourceID, string marketContext,
		int minSamplingPeriod, int maxSamplingPeriod, bool onChange, DurationModifier *durationModifier)
{
	auto_ptr<oadrReportDescriptionType::itemBase_type> i;

	addDescription(rID, resourceID, ReportEnumeratedType::x_resourceStatus, ReadingTypeEnumeratedType::x_notApplicable,
			marketContext, minSamplingPeriod, maxSamplingPeriod, onChange, durationModifier, i);
}

/********************************************************************************/

void ReportWrapper::addDescriptionEnergyItem(string rID, string resourceID, ReportEnumeratedType::value reportType,
		ReadingTypeEnumeratedType::value readingType, string marketContext, int minSamplingPeriod,
		int maxSamplingPeriod, bool onChange, DurationModifier *durationModifier, eEnergyItemType energyItemType,
		string units, SiScaleCodeType::value siScaleCodeType, string description)
{
	auto_ptr<oadrReportDescriptionType::itemBase_type> base;

	EnergyItemType *measuredValue;

	switch (energyItemType)
	{
	case eEnergyApparent:
		measuredValue = new EnergyApparentType(description, units, siScaleCodeType);
		break;

	case eEnergyReactive:
		measuredValue = new EnergyReactiveType(description, units, siScaleCodeType);
		break;

	case eEnergyReal:
		measuredValue = new EnergyRealType(description, units, siScaleCodeType);
		break;

	default:
		measuredValue = new EnergyApparentType(description, units, siScaleCodeType);
		break;
	}

	base = auto_ptr<oadrReportDescriptionType::itemBase_type>(measuredValue);

	addDescription(rID, resourceID, reportType, readingType, marketContext, minSamplingPeriod, maxSamplingPeriod, onChange,
			durationModifier, base);
}

/********************************************************************************/

void ReportWrapper::addDescriptionPowerItem(string rID, string resourceID, ReportEnumeratedType::value reportType,
		ReadingTypeEnumeratedType::value readingType, string marketContext,
		int minSamplingPeriod, int maxSamplingPeriod, bool onChange, DurationModifier *durationModifier,
		ePowerItemType powerItemType, string units, SiScaleCodeType::value siScaleCodeType, double hertz,
		double voltage, bool ac, string description)
{
	auto_ptr<oadrReportDescriptionType::itemBase_type> base;

	PowerItemType *measuredValue;

	PowerApparentType::powerAttributes_type attributes(hertz, voltage, ac);

	switch (powerItemType)
	{
	case ePowerApparent:
		measuredValue = new PowerApparentType(description, units, siScaleCodeType, attributes);
		break;

	case ePowerReactive:
		measuredValue = new PowerReactiveType(description, units, siScaleCodeType, attributes);
		break;

	case ePowerReal:
		measuredValue = new PowerRealType(description, units, siScaleCodeType, attributes);
		break;

	default:
		measuredValue = new PowerApparentType(description, units, siScaleCodeType, attributes);
		break;
	}

	base = auto_ptr<oadrReportDescriptionType::itemBase_type>(measuredValue);

	addDescription(rID, resourceID, reportType, readingType, marketContext, minSamplingPeriod, maxSamplingPeriod, onChange,
			durationModifier, base);
}

/********************************************************************************/

auto_ptr<oadrReportType> ReportWrapper::generateReportDescription()
{
	if (m_createDateTime == 0)
		m_createDateTime = time(NULL);

	auto_ptr<oadrReportType> reportType(new oadrReportType("0", m_reportSpecifierID, Oadr2bHelper::timetToiCalDateTime(m_createDateTime)));

	reportType->duration(Oadr2bHelper::generateDurationPropType(m_duration, m_durationModifier));

	reportType->reportName(m_reportName->metaDataName());

	oadrReportType::oadrReportDescription_sequence sequence;

	map<string, oadrReportDescriptionType*>::iterator itr;

	for (itr = m_reportDescriptions.begin(); itr != m_reportDescriptions.end(); itr++)
	{
		sequence.push_back(*(itr->second));
	}

	reportType->oadrReportDescription(sequence);

	return reportType;
}

/********************************************************************************/

void ReportWrapper::addInterval(string rID, time_t dtstart, int duration, DurationModifier *durationModifier)
{
	if (m_rIDtoUID.find(rID) != m_rIDtoUID.end())
	{
		OadrException exception(OadrException::RID_EXISTS);
		throw exception;
	}

	int uid = m_rIDtoUID.size();
	m_rIDtoUID[rID] = uid;

	auto_ptr<IntervalType> intervalType(new IntervalType());

	stringstream s;

	s << uid;

	intervalType->uid(icalendar_2_0::uid(s.str()));
	intervalType->dtstart(Oadr2bHelper::timetTo_dtstart(dtstart));
	intervalType->duration(Oadr2bHelper::generateDurationPropType(duration, durationModifier));

	m_intervals.push_back(intervalType);
}

/********************************************************************************/

void ReportWrapper::addReportPayload(string rID, oadrReportPayloadType &reportPayload)
{
	if (m_rIDtoUID.find(rID) == m_rIDtoUID.end())
	{
		OadrException exception(OadrException::NO_INTERVAL);
		throw exception;
	}

	int uid = m_rIDtoUID[rID];

	if (m_uIDtoReportPayload.find(uid) == m_uIDtoReportPayload.end())
	{
		m_uIDtoReportPayload[uid] = vector<oadrReportPayloadType>();
	}

	m_uIDtoReportPayload[uid].push_back(reportPayload);
}

/********************************************************************************/

void ReportWrapper::addOadrReportPayloadFloat(string rID, float value, oadrDataQualityType::value dataQuality, unsigned int confidence, unsigned int accuracy)
{
	auto_ptr<PayloadBaseType> payload(new PayloadFloatType(value));

	auto_ptr<ReportPayloadType::rID_type> rID_ptr(new ReportPayloadType::rID_type(rID));

	oadrReportPayloadType reportPayload(rID_ptr, payload);

	reportPayload.confidence(confidence);
	reportPayload.accuracy(accuracy);

	// TODO: does this need to be changed to oadrDataQualityTypeType
	// if it doesn't, there's on need for the "Value" classes I've been creating
	reportPayload.oadrDataQuality(oadrDataQualityType(dataQuality));

	addReportPayload(rID, reportPayload);
}

/********************************************************************************/

void ReportWrapper::addOadrReportPayloadResourceStatus(string rID, bool online, bool manualOverride, oadrDataQualityType::value dataQuality, unsigned int confidence, unsigned int accuracy)
{
	// TODO: refactor: move common code between this func and the previous to addReportPayload()
	// add auto_ptr<PayloadBaseType> to func
	auto_ptr<oadrPayloadResourceStatusType> payload(new oadrPayloadResourceStatusType(online, manualOverride));

	// add blank load control values for now; these values will need to be exposed at some point
	// or pass the loadControl object to this function
	payload->oadrLoadControlState(Oadr2bHelper::generateEmptyLoadControlState());

	// everything below should be moved to addReportPayload
	auto_ptr<PayloadBaseType> payloadBase(payload);

	auto_ptr<ReportPayloadType::rID_type> rID_ptr(new ReportPayloadType::rID_type(rID));

	oadrReportPayloadType reportPayload(rID_ptr, payloadBase);

	reportPayload.confidence(confidence);
	reportPayload.accuracy(accuracy);

	// TODO: does this need to be changed to oadrDataQualityTypeType
	// if it doesn't, there's on need for the "Value" classes I've been creating
	reportPayload.oadrDataQuality(oadrDataQualityType(dataQuality));

	addReportPayload(rID, reportPayload);
}

/********************************************************************************/

auto_ptr<oadrReportType> ReportWrapper::generateReport(time_t dtstart, string reportRequestID, time_t createdDateTime)
{
	auto_ptr<oadrReportType> reportType(new oadrReportType(reportRequestID, m_reportSpecifierID, Oadr2bHelper::timetToiCalDateTime(dtstart)));

	if (createdDateTime == 0)
		createdDateTime = time(NULL);

	reportType->createdDateTime(Oadr2bHelper::timetToiCalDateTime(createdDateTime));

	reportType->reportName(m_reportName->name());

	intervals::interval_sequence::iterator interval_itr;

	int uid = 0;
	for (interval_itr = m_intervals.begin(); interval_itr != m_intervals.end(); interval_itr++)
	{
		IntervalType::streamPayloadBase_sequence sequence;

		// TODO: convert UID to int and look associated ReportPayload in the map
		// below.  consider converting m_intervals to a vector to ensure the
		// intervals are iterated in the order they're added
		//string uid = (*interval_itr).uid()->text();

		vector<oadrReportPayloadType> *payloads = &m_uIDtoReportPayload[uid];

		vector<oadrReportPayloadType>::iterator payload_itr;

		for (payload_itr = payloads->begin(); payload_itr != payloads->end(); payload_itr++)
		{
			sequence.push_back(*payload_itr);
		}

		(*interval_itr).streamPayloadBase(sequence);

		uid++;
	}

	stream::intervals i;

	i.interval(m_intervals);

	reportType->intervals(i);

	m_intervals.clear();
	m_uIDtoReportPayload.clear();

	return reportType;
}
