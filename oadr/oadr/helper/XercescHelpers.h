/*
 * XercescHelpers.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef XERCESCHELPERS_H_
#define XERCESCHELPERS_H_

#include <xercesc/util/XMLString.hpp>

// taken from xsec/utils/XSECDOMUtils.hpp which is not present in the ubuntu package
class AsciiToUnicodeConverter
{
public:
	AsciiToUnicodeConverter(const char *str)
	: m_unicodeStr(XMLString::transcode(str))
	{
	}

	~AsciiToUnicodeConverter()
	{
		XMLString::release(&m_unicodeStr);
	}

	XMLCh *getUnicodeStr()
	{
		return m_unicodeStr;
	}

private:
	XMLCh *m_unicodeStr;
};

class UnicodeToAsciiConverter
{
public:
	UnicodeToAsciiConverter(const XMLCh *str)
	: m_asciiStr(XMLString::transcode(str))
	{
	}

	~UnicodeToAsciiConverter()
	{
		XMLString::release(&m_asciiStr);
	}

	const char *getAsciiStr()
	{
		return m_asciiStr;
	}

private:
	char *m_asciiStr;
};

#define MAKE_UNICODE_STRING(str) AsciiToUnicodeConverter(str).getUnicodeStr()
#define MAKE_ASCII_STRING(str) UnicodeToAsciiConverter(str).getAsciiStr()

#endif /* XERCESCHELPERS_H_ */
