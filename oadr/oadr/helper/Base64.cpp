/*
 * Base64.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#include "Base64.h"

#include <memory>

#include <xsec/utils/XSECPlatformUtils.hpp>

// consider bumping up the C++ version to 14 to make this function constexpr
unsigned int base64EncodedStringSize(unsigned int inputStringSize)
{
	const unsigned int numberOfTriplets = inputStringSize / 3 + (inputStringSize % 3 == 0 ? 0 : 1);
	const unsigned int base64DataCharacters = numberOfTriplets * 4;

	// some implementations may add new lines each 64 bytes, some each 76 bytes, so let's stay on the safe side
	const unsigned int base64Lines = base64DataCharacters / 64;

	// some implementations may represent new line as 2 bytes (CR LF)
	const unsigned int newLineEnding = 2;

	const unsigned int stringTerminator = 1;

	const unsigned int base64Length = base64DataCharacters + base64Lines * newLineEnding + stringTerminator;

	return base64Length;
}

std::string base64Encode(unsigned char *data, unsigned int size)
{
	if (!XSECPlatformUtils::g_cryptoProvider)
	{
		throw;
	}

	std::string result(base64EncodedStringSize(size), '\0');

	std::unique_ptr<XSECCryptoBase64> b64(XSECPlatformUtils::g_cryptoProvider->base64());
	b64->encodeInit();
	auto encodedSize = b64->encode(data, size,
	                               reinterpret_cast<unsigned char*>(&result[0]), result.size());
	b64->encodeFinish(reinterpret_cast<unsigned char*>(&result[encodedSize]), result.size() - encodedSize);

	return result;
}

std::vector<unsigned char> base64Decode(const char *data, unsigned int size)
{
	if (!XSECPlatformUtils::g_cryptoProvider)
	{
		throw;
	}

	std::vector<unsigned char> result(size, 0);

	std::unique_ptr<XSECCryptoBase64> b64(XSECPlatformUtils::g_cryptoProvider->base64());
	b64->decodeInit();
	auto decodedSize = b64->decode(reinterpret_cast<const unsigned char*>(data), size,
	                               &result[0], result.size());
	decodedSize += b64->decodeFinish(&result[decodedSize], result.size() - decodedSize);

	result.resize(decodedSize);

	return result;
}
