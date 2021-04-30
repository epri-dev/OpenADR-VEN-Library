/*
 * Base64.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef BASE64_H_
#define BASE64_H_

#include <string>
#include <vector>

unsigned int base64EncodedStringSize(unsigned int inputStringSize);

std::string base64Encode(unsigned char *data, unsigned int size);

std::vector<unsigned char> base64Decode(const char *data, unsigned int size);

#endif /* BASE64_H_ */
