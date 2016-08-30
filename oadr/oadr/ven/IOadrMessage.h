/*
 * IOadrMessage.h
 *
 *  Created on: Jul 9, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_VEN_IOADRMESSAGE_H_
#define OADR_OADR_VEN_IOADRMESSAGE_H_

#include <string>

class IOadrMessage
{
public:
	IOadrMessage();
	virtual ~IOadrMessage();

	virtual void OnOadrMessageReceived(std::string &message) = 0;
	virtual void OnOadrMessageSent(std::string &message) = 0;
};

class OadrMessageBlank : public IOadrMessage
{
public:
	virtual void OnOadrMessageReceived(std::string &message){};
	virtual void OnOadrMessageSent(std::string &message){};

	static OadrMessageBlank oadrMessageBlank;
};

#endif /* OADR_OADR_VEN_IOADRMESSAGE_H_ */
