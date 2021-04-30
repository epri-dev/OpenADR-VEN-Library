/*
 * XmlSecurityHelpers.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef XMLSECURITYHELPERS_H_
#define XMLSECURITYHELPERS_H_

#include <memory>
#include <vector>

#include <xsec/enc/XSECCryptoKey.hpp>

class DSIGSignature;

std::unique_ptr<XSECCryptoKey> makeKeyFromDerBuffer(const unsigned char* buffer, long length);

std::vector<unsigned char> getX509CertificateBytes(const DSIGSignature &dsigSignature);

#endif /* XMLSECURITYHELPERS_H_ */
