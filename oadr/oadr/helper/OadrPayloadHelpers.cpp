/*
 * OadrPayloadHelpers.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#include "OadrPayloadHelpers.h"

#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

std::unique_ptr<oadr2b::oadr::oadrPayload> to_oadrPayload(const std::string& xml)
{
	using f = xsd::cxx::tree::flags;

	std::istringstream iss(xml);

	// TODO: not currently validating the XML; need to figure out
	// how to specify the location
	return oadr2b::oadr::oadrPayload_(iss, f::keep_dom | f::own_dom | f::dont_validate | f::dont_initialize);
}

xml_schema::dom::unique_ptr<xercesc::DOMDocument> to_document(oadr2b::oadr::oadrPayload &payload)
{
	// The XSD library is able to use a schema to enrich produced DOMDocument.
	// That could be useful for allowing to use DOMDocument::getElementById(),
	// since be default DOMDocument doesn't know which XML attributes are IDs.
	// The library isn't told where the schema files schema files can be found.
	// TODO: copy the schema to the build folder or add a path to it in config.
	xml_schema::namespace_infomap map;
	map[""].name = "";
	map[""].schema = "";

	return oadr2b::oadr::oadrPayload_(payload, map, xml_schema::flags::dont_initialize);
}

std::string to_string(oadr2b::oadr::oadrPayload &payload)
{
	xml_schema::namespace_infomap map;
	std::stringstream ss;

	map[""].name = "";
	map[""].schema = "";

	oadrPayload_(ss, payload, map, "", xml_schema::flags::dont_initialize);

	return ss.str();
}

// Similar to to_string(oadrPayload) but without pretty printing. If the structure
// of the signed parts of XML tree are changed, the digests and signature are invalidated.
// In order to prever that, we keep the same XML structure after it is canonicalized.
std::string to_string(xercesc::DOMDocument &document)
{
	std::stringstream ss;

	xsd::cxx::xml::dom::ostream_format_target formatTarget(ss);

	const std::string encoding = "";

	xsd::cxx::tree::error_handler<char> errorHandler;

	xml_schema::flags flags = xml_schema::flags::dont_initialize | xml_schema::flags::dont_pretty_print;

	if (!xsd::cxx::xml::dom::serialize(formatTarget, document, encoding, errorHandler, flags))
	{
		errorHandler.throw_if_failed<xsd::cxx::tree::serialization<char>>();
	}

	return ss.str();
}
