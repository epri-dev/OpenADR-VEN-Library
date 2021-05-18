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
	std::string m_canonicalizationMethod;
	std::string m_signatureMethod;
	std::string m_digestMethod;

public:
	/**
	 * @param certPath The path to the certificate attached to a signed XML document. Must use
	 *                 the DER format. The contents are cached in course of running the VENManager,
	 *                 so whenever the certificate must be changed, the process must be restarted.
	 * @param signingKeyPath The path to the private key used for signing an XML document. Must use
	 *                       the DER format. The key type (RSA vs EC) must match
	 *                       the signatureMethod. The contents are cached in course of running
	 *                       the VENManager, so whenever the key must be changed, the process must
	 *                       be restarted.
	 * @param caPath The path to the X509 certification authority bundle that is used when
	 *               verifying signatures of incoming messages. Must be a concatenation of
	 *               the X509 certicate chain in the PEM format. The contents are NOT cached
	 *               in course of running the VENManager. If the CA bundle changes, it is reread
	 *               and applied for consecutive incoming messages.
	 * @param canonicalizationMethod The algorithm for transforming an XML document into
	 *                               canonical form. The OpenADR 2.0b standard allows for one of:
	 *                               - http://www.w3.org/TR/2001/REC-xml-c14n-20010315
	 *                               - http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments
	 * @param signatureMethod The algorithm for signing XML document elements. The type of
	 *                        signing key must match the signature method (RSA vs EC).
	 *                        The OpenADR 2.0b standard allows for one of:
	 *                        - http://www.w3.org/2000/09/xmldsig#rsa-sha1
	 *                        - http://www.w3.org/2001/04/xmldsig-more#rsa-sha256
	 *                        - http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1
	 *                        - http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256
	 * @param digestMethod The algorithm for computing digest of signed XML document elements.
	 *                     The OpenADR 2.0b standard allows for one of:
	 *                     - http://www.w3.org/2000/09/xmldsig#sha1
	 *                     - http://www.w3.org/2001/04/xmlenc#sha256
	 */
	SignatureContext(const std::string& certPath,
	                 const std::string& signingKeyPath,
	                 const std::string& caPath,
	                 const std::string& canonicalizationMethod,
	                 const std::string& signatureMethod,
	                 const std::string& digestMethod);
	~SignatureContext();

	std::string sign(oadr2b::oadr::oadrPayload &payload) override;
	bool verify(oadr2b::oadr::oadrPayload &payload) override;
};

#endif /* SIGNATURECONTEXT_H_ */
