/*
 * OadrPayloadHelpers.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef OADRPAYLOADHELPERS_H_
#define OADRPAYLOADHELPERS_H_

#include <string>

#include <oadrsd/2b/oadr_20b.hxx>

std::unique_ptr<oadr2b::oadr::oadrPayload> to_oadrPayload(const std::string& xml);

xml_schema::dom::unique_ptr<xercesc::DOMDocument> to_document(oadr2b::oadr::oadrPayload &payload);

std::string to_string(oadr2b::oadr::oadrPayload &payload);

std::string to_string(xercesc::DOMDocument &document);

#endif /* OADRPAYLOADHELPERS_H_ */
