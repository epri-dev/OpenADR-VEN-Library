/*
 * ITransport.h
 *
 *  Created on: Jul 8, 2015
 *      Author: dupes
 */

#ifndef OADR_OADR_MANAGER_TRANSPORT_ITRANSPORT_H_
#define OADR_OADR_MANAGER_TRANSPORT_ITRANSPORT_H_

#include <string>
#include <memory>
#include <functional>
#include <chrono>

enum class OadrEndpoint
{
	EiEvent,
	EiReport,
	EiRegisterParty,
	EiOpt,
	EiPoll
};

class ITransport
{
public:
	virtual ~ITransport() = default;

	virtual void sendMessage(OadrEndpoint, std::unique_ptr<std::string> xml) = 0;

	// Two options for getting messages from the transport to VenManager
	//   option 1: messages are sent to the VenManager as soon as they're received
	//   option 2: the VenManager polls for messages
	// Option 2 gives the VenManager more control and is a more standard approach
	// Option 1 push messages to the VenManager as soon as they're received, freeing
	// the VenManager from the need to periodically poll for received messages
	virtual void setOnMessageCallback(const std::function<std::unique_ptr<std::string> ()> &function) = 0;
	virtual std::unique_ptr<std::string> getNextMessage(std::chrono::steady_clock::duration d) = 0;
};

#endif /* OADR_OADR_MANAGER_TRANSPORT_ITRANSPORT_H_ */
