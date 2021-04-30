/*
 * XmlSecurityHelpers.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#include "XmlSecurityHelpers.h"

#include <sstream>

#include <openssl/evp.h>

#include <xsec/dsig/DSIGKeyInfoX509.hpp>
#include <xsec/dsig/DSIGSignature.hpp>
#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyDSA.hpp>
#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyEC.hpp>
#include <xsec/enc/OpenSSL/OpenSSLCryptoKeyRSA.hpp>
#include <xsec/enc/XSECCryptoException.hpp>

#include "Base64.h"

namespace
{
	std::unique_ptr<XSECCryptoKey> makeKey(EVP_PKEY* opensslKey)
	{
		const int keyId = EVP_PKEY_id(opensslKey);

		try
		{
			switch (keyId)
			{
				case EVP_PKEY_RSA:
					return std::unique_ptr<XSECCryptoKey>(new OpenSSLCryptoKeyRSA(opensslKey));
				case EVP_PKEY_DSA:
					return std::unique_ptr<XSECCryptoKey>(new OpenSSLCryptoKeyDSA(opensslKey));
				case EVP_PKEY_EC:
					return std::unique_ptr<XSECCryptoKey>(new OpenSSLCryptoKeyEC(opensslKey));
			}
		}
		catch (const XSECCryptoException &error)
		{
			std::stringstream ss;
			ss << "Couldn't create a private key due to an error: " << error.getMsg();
			throw std::runtime_error(ss.str());
		}

		std::stringstream ss;
		ss << "Unsupported key id: " << static_cast<int>(keyId);
		throw std::runtime_error(ss.str());
	}
}

std::unique_ptr<XSECCryptoKey> makeKeyFromDerBuffer(const unsigned char* buffer, long length)
{
	EVP_PKEY* pkey = d2i_AutoPrivateKey(NULL, &buffer, length);

	if (nullptr == pkey)
	{
		throw std::runtime_error("Couldn't create an EVP_PKEY from the buffer");
	}

	try
	{
		std::unique_ptr<XSECCryptoKey> key = makeKey(pkey);
		EVP_PKEY_free(pkey);
		return key;
	}
	catch (const std::runtime_error& error)
	{
		EVP_PKEY_free(pkey);
		throw error;
	}
}

std::vector<unsigned char> getX509CertificateBytes(const DSIGSignature &dsigSignature)
{
	// We assume that the VTN sends the X509 certificate along with the signed message.
	// The certificate must be verified against the certification authority bundle to check its validity.
	// We support no way to verify the signature but with use of a public key from the certificate.
	// If there were 2 (or more) certificates present in the message, we would pick the key from the valid ones.
	// The XSECKeyInfoResolverDefault gives us no control over which key is used for verification of the signature.
	// Even if we get the key from the resolver, the library doesn't provide a cheap option to match it with one of the certificates.
	// Due to above limitations, we decide to not support multiple certificates.

	// The limitations might be overcome with providing our own XSECKeyInfoResolverDefault which would filter out the certificates
	// depending on their validity against the CA bundle.

	const DSIGKeyInfoList *keyInfoList = dsigSignature.getKeyInfoList();
	if (nullptr == keyInfoList)
	{
		throw std::runtime_error("Couldn't get the X509 certificate since the KeyInfo is not present");
	}

	const size_t keyInfoSize = keyInfoList->getSize();
	if (1 > keyInfoSize)
	{
		throw std::runtime_error("Couldn't get the X509 certificate since the KeyInfo is not present");
	}

	if (1 < keyInfoSize)
	{
		throw std::runtime_error("Multiple KeyInfo are not supported");
	}

	const DSIGKeyInfo *keyInfo = keyInfoList->item(0);
	if (nullptr == keyInfo)
	{
		throw std::runtime_error("Key info is NULL");
	}

	if (DSIGKeyInfo::keyInfoType::KEYINFO_X509 != keyInfo->getKeyInfoType())
	{
		std::stringstream ss;
		ss << "Unsupported key info type: " << static_cast<int>(keyInfo->getKeyInfoType());
		throw std::runtime_error(ss.str());
	}

	const DSIGKeyInfoX509 *keyInfoX509 = dynamic_cast<const DSIGKeyInfoX509*>(keyInfo);
	if (nullptr == keyInfoX509)
	{
		throw std::runtime_error("The key info is not an instance of DSIGKeyInfoX509");
	}

	const int certificateListSize = keyInfoX509->getCertificateListSize();
	if (1 > certificateListSize)
	{
		throw std::runtime_error("No X509 certificate present");
	}

	if (1 < certificateListSize)
	{
		throw std::runtime_error("Multiple X509 certificates are not supported");
	}

	const XSECCryptoX509 *x509 = keyInfoX509->getCertificateCryptoItem(0);
	if (nullptr == x509)
	{
		throw std::runtime_error("The certificate is NULL");
	}

	const safeBuffer &derBase64 = x509->getDEREncodingSB();

	const std::vector<unsigned char> der = base64Decode(derBase64.rawCharBuffer(), derBase64.sbStrlen());

	return der;
}
