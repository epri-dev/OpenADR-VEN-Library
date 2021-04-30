/*
 * SignatureContext.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef SIGNATURECONTEXT_H_
#define SIGNATURECONTEXT_H_

#include "ISignatureContext.h"

#include <memory>

#include <xsec/enc/XSECCryptoKey.hpp>

class SignatureContext : public ISignatureContext
{
private:
	std::string m_certificate;
	std::unique_ptr<XSECCryptoKey> m_signingKey;
	std::string m_caPath;

public:
	/**
	 * @param certPath path to the certificate in DER format; the contents are cached during construction of this object.
	 * @param signingKeyPath path to the private key in DER format; the contents are cached during construction of this object.
	 * @param caPath path to the certification authority bundle in PEM format; the contents are read each time verify is called (so invalid certificate can be revoked)
	 */
	SignatureContext(const std::string& certPath, const std::string& signingKeyPath, const std::string& caPath);
	~SignatureContext();

	std::string sign(oadr2b::oadr::oadrPayload &payload) override;
	bool verify(oadr2b::oadr::oadrPayload &payload) override;
};

#endif /* SIGNATURECONTEXT_H_ */
