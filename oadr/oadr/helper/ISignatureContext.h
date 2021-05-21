/*
 * ISignatureContext.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef ISIGNATURECONTEXT_H_
#define ISIGNATURECONTEXT_H_

#include <string>

namespace oadr2b
{
	namespace oadr
	{
		class oadrPayload;
	}
}

class ISignatureContext
{
public:
	virtual ~ISignatureContext() = default;

	virtual std::string sign(oadr2b::oadr::oadrPayload &payload) = 0;
	virtual bool verify(oadr2b::oadr::oadrPayload &payload) = 0;
};

#endif /* SIGNATURECONTEXT_H_ */
