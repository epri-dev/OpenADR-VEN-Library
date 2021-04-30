/*
 * SignatureContext.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#include "SignatureContext.h"

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

#include <xsec/dsig/DSIGKeyInfoX509.hpp>
#include <xsec/dsig/DSIGObject.hpp>
#include <xsec/dsig/DSIGReference.hpp>
#include <xsec/enc/XSECCryptoException.hpp>
#include <xsec/enc/XSECKeyInfoResolverDefault.hpp>
#include <xsec/framework/XSECException.hpp>
#include <xsec/framework/XSECProvider.hpp>
#include <xsec/transformers/TXFMDocObject.hpp>

#include "Base64.h"
#include "DateTimeConverter.h"
#include "OadrPayloadHelpers.h"
#include "OpenSSLHelpers.h"
#include "XercescHelpers.h"
#include "XmlSecurityHelpers.h"

#include "globaltime/GlobalTime.h"

namespace
{
	std::vector<unsigned char> readBinaryFile(const std::string& path)
	{
		std::ifstream input(path, std::ios::binary);

		std::vector<unsigned char> data(std::istreambuf_iterator<char>(input), {});

		return data;
	}

	double secondsSinceTimestamp(xercesc::DOMNode *timestamp)
	{
		if (nullptr == dynamic_cast<DOMElement*>(timestamp))
		{
			throw std::runtime_error("Timestamp is not DOMElement");
		}

		const DOMElement &timestampElement = static_cast<DOMElement&>(*timestamp);

		const icalendar_2_0::dtstart::date_time_type dateTime(timestampElement);

		const time_t timestampTime = DateTimeConverter::DateTimeToTime_t(dateTime);

		const double seconds = std::difftime(GlobalTime::Instance()->now(), timestampTime);

		return seconds;
	}

	std::string timestamp()
	{
		// TODO: Redesign GlobalTime to use std::chrono::time_point instead of time_t, so has a sub-second resolution like system_clock:
		// auto now = std::chrono::system_clock::now();

		auto now = std::chrono::system_clock::from_time_t(GlobalTime::Instance()->now());

		auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);

		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(now - seconds).count();

		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

		std::stringstream ss;
		ss << std::put_time(gmtime(&currentTime), "%Y-%m-%dT%H:%M:%S.")
		   << std::setfill('0') << std::setw(6) << microseconds << 'Z';

		return ss.str();
	}

	std::string base64Nonce()
	{
		constexpr unsigned int kNonceSize = 24;

		unsigned char nonce[kNonceSize];
		XSECPlatformUtils::g_cryptoProvider->getRandom(nonce, kNonceSize);

		return base64Encode(nonce, kNonceSize);
	}

	void fillSignatureProperties(xercesc::DOMDocument &d, DSIGObject *object)
	{
		std::unique_ptr<xercesc::DOMElement> signaturePropertiesNode(d.createElement(u"ds:SignatureProperties"));
		{
			std::unique_ptr<xercesc::DOMElement> signaturePropertyNode(d.createElement(u"ds:SignatureProperty"));
			signaturePropertyNode->setAttribute(u"Target", u"#oadrPayloadSignature");

			{
				std::unique_ptr<xercesc::DOMElement> replayProtectNode(d.createElement(u"dsp:ReplayProtect"));
				replayProtectNode->setAttribute(u"xmlns:dsp", u"http://openadr.org/oadr-2.0b/2012/07/xmldsig-properties");

				{
					std::unique_ptr<xercesc::DOMElement> timestampNode(d.createElement(u"dsp:timestamp"));
					timestampNode->appendChild(d.createTextNode(MAKE_UNICODE_STRING(timestamp().c_str())));
					replayProtectNode->appendChild(timestampNode.release());
				}

				{
					std::unique_ptr<xercesc::DOMElement> nonceNode(d.createElement(u"dsp:nonce"));
					nonceNode->appendChild(d.createTextNode(MAKE_UNICODE_STRING(base64Nonce().c_str())));

					replayProtectNode->appendChild(nonceNode.release());
				}

				signaturePropertyNode->appendChild(replayProtectNode.release());
			}

			signaturePropertiesNode->appendChild(signaturePropertyNode.release());
		}

		object->appendChild(signaturePropertiesNode.release());
	}

	void decorateDocumentWithSignatureSkeleton(xercesc::DOMDocument &document,
											   DSIGSignature &dsigSignature,
											   const char* x509Certificate,
											   const std::string& oadrSignedObjectId)
	{
		// We need to create a few extra nodes to the DOMDocument so the signature can be stored.
		// The structure is same for each message so we could consider creating a DOMDocumentFragment
		// which created once could be reused for all consecutive messages signed.
		// We haven't gone that path since that would require rewriting some part of XML-Security-C library.
		// Instead, we decided to suffer a bit of perfomance to make our code as simple as possible.
		// If the final performance is not acceptable, this decision could be reconsidered.

		using namespace xercesc;

		dsigSignature.setDSIGNSPrefix(u"ds");

		DOMElement *signatureNode = dsigSignature.createBlankSignature(&document,
				DSIGConstants::s_unicodeStrURIC14N_NOC,
				DSIGConstants::s_unicodeStrURIECDSA_SHA256);

		// TODO: when schema check is on, we should make sure that this ID is unique
		signatureNode->setAttribute(u"Id", u"oadrPayloadSignature");

		// DSIGSignature cares for cleaning up after DSIGKeyInfoX509
		dsigSignature.appendX509Data()->appendX509Certificate(MAKE_UNICODE_STRING(x509Certificate));

		// DSIGSignature cares for cleaning up after DSIGObject
		DSIGObject *object = dsigSignature.appendObject();

		// TODO: when schema check is present, we should make sure that this ID is unique
		object->setId(u"signatureProperties");

		fillSignatureProperties(document, object);

		const std::string oadrSignedObjectUri = "#" + oadrSignedObjectId;

		// DSIGSignature cares for cleaning up after DSIGReference
		dsigSignature.createReference(MAKE_UNICODE_STRING(oadrSignedObjectUri.c_str()), DSIGConstants::s_unicodeStrURISHA256)
					 ->appendCanonicalizationTransform(DSIGConstants::s_unicodeStrURIC14N_NOC);
		dsigSignature.createReference(u"#signatureProperties", DSIGConstants::s_unicodeStrURISHA256)
					 ->appendCanonicalizationTransform(DSIGConstants::s_unicodeStrURIC14N_NOC);

		DOMElement &payloadNode = *document.getDocumentElement();

		// According to the XML schema, the node Signature must be the first in the sequence.
		payloadNode.insertBefore(signatureNode, payloadNode.getFirstChild());

		// The XSD library fixes the document element namespace after parsing but we need that to be done before signing
		payloadNode.setAttributeNS(xercesc::XMLUni::fgXMLNSURIName, u"xmlns:p1", u"http://openadr.org/oadr-2.0b/2012/07");
	}

	xercesc::DOMNode *getUniqueDOMNodeByTagNameNS(xercesc::DOMDocument *document, const char* ns, const char* localName)
	{
		using namespace xercesc;

		DOMNodeList *list = document->getElementsByTagNameNS(MAKE_UNICODE_STRING(ns), MAKE_UNICODE_STRING(localName));
		if (nullptr != list && list->getLength() > 0)
		{
			if (list->getLength() > 1)
			{
				std::stringstream ss;
				ss << "No support for multiple " << ns << ":" << localName;
				throw std::runtime_error(ss.str());
			}

			DOMNode *node = list->item(0);
			if (nullptr != node)
			{
				return node;
			}
		}

		std::stringstream ss;
		ss << "No " << ns << ":" << localName << " found";
		throw std::runtime_error(ss.str());
	}

	/**
	 * Checks if the signed document is in line with the conformance rule 514 of the OpenADR 2.0b profile specification.
	 */
	bool verifySignatureComposition(DSIGSignature &sig)
	{
		using namespace xercesc;

		constexpr double kMaxTimeForResponse = 5.0;

		// owned by DSIGSignature
		DOMDocument *doc = sig.getParentDocument();
		if (nullptr == doc)
		{
			throw std::runtime_error("Cannot access the Document");
		}

		DOMNode *oadrSignedObject = getUniqueDOMNodeByTagNameNS(doc, "http://openadr.org/oadr-2.0b/2012/07", "oadrSignedObject");
		DOMNode *timestamp = getUniqueDOMNodeByTagNameNS(doc, "http://openadr.org/oadr-2.0b/2012/07/xmldsig-properties", "timestamp");
		DOMNode *nonce = getUniqueDOMNodeByTagNameNS(doc, "http://openadr.org/oadr-2.0b/2012/07/xmldsig-properties", "nonce");

		const double secondsSinceResponseSent = secondsSinceTimestamp(timestamp);
		if (kMaxTimeForResponse < secondsSinceResponseSent)
		{
			std::stringstream ss;
			ss << "Expected to receive a response within " << kMaxTimeForResponse << " but got it after " << secondsSinceResponseSent;
			throw std::runtime_error(ss.str());
		}

		std::u16string nonceValue(nonce->getTextContent());
		if (nonceValue.empty())
		{
			throw std::runtime_error("Nonce is empty");
		}

		// We teach XSEC which attributes should be considered as IDs
		// so it is able to follow references to oadrSignedObject and ReplayProcted
		XSECEnv xsecEnv(doc);
		xsecEnv.setIdByAttributeName(true);
		xsecEnv.registerIdAttributeNameNS(u"http://openadr.org/oadr-2.0b/2012/07", u"Id");
		xsecEnv.registerIdAttributeNameNS(u"http://www.w3.org/2000/09/xmldsig#", u"Id");

		bool oadrSignedObjectVerified = false;
		bool replayProtectTimestampVerified = false;
		bool replayProtectNonceVerified = false;

		// owned by DSIGSignature
		DSIGReferenceList *referenceList = sig.getReferenceList();
		if (nullptr == referenceList)
		{
			throw std::runtime_error("No Reference node found");
		}

		for (size_t i = 0; i < referenceList->getSize(); ++i)
		{
			DSIGReference *reference = referenceList->item(i);
			if (nullptr == reference)
			{
				continue;
			}

			std::unique_ptr<TXFMBase> transform(DSIGReference::getURIBaseTXFM(doc, reference->getURI(), &xsecEnv));
			if (nullptr == transform)
			{
				continue;
			}

			// owned by TXFMDocObject
			DOMNode *node = transform->getFragmentNode();

			if (oadrSignedObject->isSameNode(node))
			{
				oadrSignedObjectVerified = true;
			}
			else
			{
				// ReplayProtect is a parent node of timestamp and nonce.
				// It is fine with us if the Reference points to an ancestor node of ReplayProtect.
				if ((timestamp->compareDocumentPosition(node) & DOMNode::DocumentPosition::DOCUMENT_POSITION_CONTAINS) != 0)
				{
					replayProtectTimestampVerified = true;
				}
				if ((nonce->compareDocumentPosition(node) & DOMNode::DocumentPosition::DOCUMENT_POSITION_CONTAINS) != 0)
				{
					replayProtectNonceVerified = true;
				}
			}
		}

		if (!oadrSignedObjectVerified)
		{
			std::cerr << "Couldn't find reference to the oadrSignedObject node\n";
		}

		if (!replayProtectTimestampVerified)
		{
			std::cerr << "Couldn't find reference to an ancestor of the timestamp node\n";
		}

		if (!replayProtectNonceVerified)
		{
			std::cerr << "Couldn't find reference to an ancestor of the nonce node\n";
		}

		return oadrSignedObjectVerified && replayProtectTimestampVerified && replayProtectNonceVerified;
	}

	void releaseSignature(XSECProvider &xsecProvider, DSIGSignature *dsigSignature)
	{
		if (nullptr != dsigSignature)
		{
			xsecProvider.releaseSignature(dsigSignature);
		}
	}
}

SignatureContext::SignatureContext(const std::string& certPath, const std::string& signingKeyPath, const std::string& caPath)
{
	// init must be before any use of the XSEC library.
	xercesc::XMLPlatformUtils::Initialize();
	XSECPlatformUtils::Initialise();

	{
		std::vector<unsigned char> data = readBinaryFile(certPath);
		m_certificate = base64Encode(data.data(), data.size());
	}

	{
		std::vector<unsigned char> data = readBinaryFile(signingKeyPath);
		m_signingKey = makeKeyFromDerBuffer(data.data(), data.size());
	}

	m_caPath = caPath;
}

SignatureContext::~SignatureContext()
{
	XSECPlatformUtils::Terminate();
	xercesc::XMLPlatformUtils::Terminate();
}

std::string SignatureContext::sign(oadr2b::oadr::oadrPayload &payload)
{
	XSECProvider xsecProvider;
	DSIGSignature* dsigSignature = nullptr;

	try
	{
		if (!payload.oadrSignedObject().Id() || *payload.oadrSignedObject().Id() == std::string(""))
		{
			payload.oadrSignedObject().Id() = "oadrSignedObject";
		}
		const std::string oadrSignedObjectId = *payload.oadrSignedObject().Id();

		xml_schema::dom::unique_ptr<xercesc::DOMDocument> document = to_document(payload);

		dsigSignature = xsecProvider.newSignature();

		// The function to_document does not enrich the DOMDocument with the schema information.
		// Because of that, DOMDocument::getElementById is not able to find elements
		// (in XML naming the attribute `Id` is not enough, it must be specified in the schema).
		// Due to that fact, we need to add that information manually. Note that this might be considered as a potential security risk.
		// Consult https://santuario.apache.org/cfaq.html (How does the library identify Id attributes?) for more details.
		// For signing the document we should not be worried about that since the XML comes from the trusted source (our code).
		dsigSignature->setIdByAttributeName(true);
		dsigSignature->registerIdAttributeNameNS(u"http://openadr.org/oadr-2.0b/2012/07", u"Id");
		dsigSignature->registerIdAttributeNameNS(u"http://www.w3.org/2000/09/xmldsig#", u"Id");

		decorateDocumentWithSignatureSkeleton(*document, *dsigSignature, m_certificate.c_str(), oadrSignedObjectId);

		dsigSignature->setSigningKey(m_signingKey->clone());

		dsigSignature->sign();

		xsecProvider.releaseSignature(dsigSignature);

		return to_string(*document);
	}
	catch (const xercesc::DOMException &e)
	{
		releaseSignature(xsecProvider, dsigSignature);
		std::cerr << "Got DOMException when signing the oadrPayload: " << MAKE_ASCII_STRING(e.getMessage()) << "\n";
		throw;
	}
	catch (const XSECException &e)
	{
		releaseSignature(xsecProvider, dsigSignature);
		std::cerr << "Got XSECException when signing the oadrPayload: " << MAKE_ASCII_STRING(e.getMsg()) << "\n";
		throw;
	}
	catch (const XSECCryptoException &e)
	{
		releaseSignature(xsecProvider, dsigSignature);
		std::cerr << "Got XSECCryptoException when signing the oadrPayload: " << e.getMsg() << "\n";
		throw;
	}
	catch (const std::runtime_error &e)
	{
		releaseSignature(xsecProvider, dsigSignature);
		std::cerr << "Got std::runtime_error when signing the oadrPayload: " << e.what() << "\n";
		throw;
	}
	catch (const std::exception &e)
	{
		releaseSignature(xsecProvider, dsigSignature);
		std::cerr << "Got std::exception when signing the oadrPayload: " << e.what() << "\n";
		throw;
	}
	catch (...)
	{
		releaseSignature(xsecProvider, dsigSignature);
		std::cerr << "Got unexpected exception when signing the oadrPayload" << "\n";
		throw;
	}
}

bool SignatureContext::verify(oadr2b::oadr::oadrPayload &payload)
{
	XSECProvider xsecProvider;
	DSIGSignature *dsigSignature = nullptr;

	try
	{
		xercesc::DOMDocument& document = *payload._node()->getOwnerDocument();

		dsigSignature = xsecProvider.newSignatureFromDOM(&document);

		// The function to_document does not enrich the DOMDocument with the schema information.
		// Because of that, DOMDocument::getElementById is not able to find elements
		// (in XML naming the attribute `Id` is not enough, it must be specified in the schema).
		// Due to that fact, we need to add that information manually. Note that this might be considered as a potential security risk.
		// Consult https://santuario.apache.org/cfaq.html (How does the library identify Id attributes?) for more details.
		// The function verifySignatureComposition provides countermeasures:
		// - there can be one and only one oadrSignedObject node (which stands for the first registered Id attribute)
		// - there can be one and only one timestamp node
		// - there can be one and only one nonce node
		// - oadrSignedObject must be pointed by URI of a Signature' Reference node
		// - timestamp and node must be a descendant of a node pointed by URI of a Signature' Reference node
		// Thanks to all above, the attacker cannot create alternative oadrSignedObject or timestamp/nonce or skip signing any of them.
		dsigSignature->setIdByAttributeName(true);
		dsigSignature->registerIdAttributeNameNS(u"http://openadr.org/oadr-2.0b/2012/07", u"Id");
		dsigSignature->registerIdAttributeNameNS(u"http://www.w3.org/2000/09/xmldsig#", u"Id");

		// Get the key attached to the message (the X509 certificate)
		XSECKeyInfoResolverDefault keyInfoResolver;
		dsigSignature->setKeyInfoResolver(&keyInfoResolver);

		// Populate the signature object with data from the XML message
		dsigSignature->load();

		// Verify if the signature is in line with the conformance rule 514 of the OpenADR 2.0b profile specification.
		if (!verifySignatureComposition(*dsigSignature))
		{
			return false;
		}

		{
			// If we already verified that certificate, we could skip the verification
			// under the condition that the CA file content has not changed.
			std::vector<unsigned char> bytes = getX509CertificateBytes(*dsigSignature);
			verifyCertificate(m_caPath.c_str(), &bytes[0], bytes.size());
		}

		const bool result = dsigSignature->verify();

		const std::string errorString(MAKE_ASCII_STRING(dsigSignature->getErrMsgs()));
		if (!errorString.empty())
		{
			std::cerr << "Couldn't verify the signature due to: "<< errorString << "\n";
		}

		return result;
	}
	catch (const xercesc::DOMException &e)
	{
		std::cerr << "Got DOMException when verifying the signature: " << MAKE_ASCII_STRING(e.getMessage()) << "\n";
	}
	catch (const XSECException &e)
	{
		std::cerr << "Got XSECException when verifying the signature: " << MAKE_ASCII_STRING(e.getMsg()) << "\n";
	}
	catch (const XSECCryptoException &e)
	{
		std::cerr << "Got XSECCryptoException when verifying the signature: " << e.getMsg() << "\n";
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Got std::runtime_error when verifying the signature: " << e.what() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Got std::exception when verifying the signature: " << e.what() << "\n";
	}
	catch (...)
	{
		std::cerr << "Got unexpected exception when verifying the signature" << "\n";
	}

	releaseSignature(xsecProvider, dsigSignature);

	return false;
}
