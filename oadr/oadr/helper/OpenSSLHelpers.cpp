/*
 * OpenSSLHelpers.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#include "OpenSSLHelpers.h"

#include <sstream>

#include <openssl/x509_vfy.h>

namespace
{
	// Just for sake of completeness.
	// uint8_t openSSLVersionStatus()
	// {
	// 	// MNNFFPPS: major minor fix patch status
	// 	return (OPENSSL_VERSION_NUMBER & 0x0000000FL);
	// }

	uint8_t openSSLVersionPatch()
	{
		// MNNFFPPS: major minor fix patch status
		return (OPENSSL_VERSION_NUMBER & 0x00000FF0L) >> (4);
	}

	uint8_t openSSLVersionFix()
	{
		// MNNFFPPS: major minor fix patch status
		return (OPENSSL_VERSION_NUMBER & 0x000FF000L) >> (4 + 8);
	}

	uint8_t openSSLVersionMinor()
	{
		// MNNFFPPS: major minor fix patch status
		return (OPENSSL_VERSION_NUMBER & 0x0FF00000L) >> (4 + 8 + 8);
	}

	uint8_t openSSLVersionMajor()
	{
		// MNNFFPPS: major minor fix patch status
		return (OPENSSL_VERSION_NUMBER & 0xF0000000L) >> (4 + 8 + 8 + 8);
	}
}

// CAfile could be cached so it doesn't need to be read each time the message signature is verified.
// We decided to not cache it so that changing the CAfile is as simple as changing that file contents.
void verifyCertificate(const char* CAfile, const unsigned char* certData, int certDataLength)
{
	X509_STORE *store = nullptr;
	X509 *x509 = nullptr;
	X509_STORE_CTX *context = nullptr;
	try
	{
		store = X509_STORE_new();
		if (store == NULL)
		{
			throw std::runtime_error("Couldn't create a new X509 store");
		}

		if (!X509_STORE_load_locations(store, CAfile, NULL))
		{
			std::stringstream ss;
			ss << "Couldn't load '" << CAfile << "' to the X509 store";
			throw std::runtime_error(ss.str());
		}

		{
			// Due to recently discovered vulnerability https://nvd.nist.gov/vuln/detail/CVE-2021-3450
			// throw if OpenSSL version is affected (1.1.1h-1.1.1j)

			constexpr uint8_t kMinAffectedPatch = 8; // 'h' is the 8th letter in alphabet
			constexpr uint8_t kMaxAffectedPatch = 10; // 'j' is the 10th letter in alphabet
			if (1 == openSSLVersionMajor() &&
			    1 == openSSLVersionMinor() &&
			    1 == openSSLVersionFix() &&
			    kMinAffectedPatch <= openSSLVersionPatch() &&
			    kMaxAffectedPatch >= openSSLVersionPatch())
			{
				std::stringstream ss;
				ss << "Use of vulnerable " << OPENSSL_VERSION_TEXT
				   << ". Please update it to the version 1.1.1k or newer. Consult CVE-2021-3450 for more details.";
				throw std::runtime_error(ss.str());
			}

			X509_STORE_set_flags(store, X509_V_FLAG_X509_STRICT);
		}

		x509 = d2i_X509(NULL, &certData, certDataLength);
		if (x509 == NULL)
		{
			throw std::runtime_error("Couldn't create a new X509 certificate from the given data");
		}

		// In our implementation each time a new X509_STORE_CTX is needed, it is recreated.
		// A more performant implementation would keep the same X509_STORE_CTX instance and simply
		// call X509_STORE_CTX_init and X509_STORE_CTX_cleanup.
		context = X509_STORE_CTX_new();
		if (context == NULL)
		{
			throw std::runtime_error("Couldn't create a new X509 store context");
		}

		if (!X509_STORE_CTX_init(context, store, x509, NULL))
		{
			throw std::runtime_error("Couldn't initialize the X509 store context");
		}

		const int verificationResult = X509_verify_cert(context);
		if (verificationResult < 0)
		{
			throw std::runtime_error("An error occurred while verifying the certificate");
		}

		if (verificationResult == 0)
		{
			const int error = X509_STORE_CTX_get_error(context);

			std::stringstream ss;
			ss << "Certificate verification failed with an error: " << X509_verify_cert_error_string(error)
			   << " (error code: " << error << ")";
			throw std::runtime_error(ss.str());
		}

		X509_STORE_CTX_free(context);
		X509_free(x509);
		X509_STORE_free(store);
	}
	catch(const std::runtime_error& e)
	{
		X509_STORE_CTX_free(context);
		X509_free(x509);
		X509_STORE_free(store);

		throw e;
	}
}
