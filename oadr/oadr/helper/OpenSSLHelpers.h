/*
 * OpenSSLHelpers.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Michal Kowalczyk
 */

#ifndef OPENSSLHELPERS_H_
#define OPENSSLHELPERS_H_

void verifyCertificate(const char* CAfile, const unsigned char* certData, int certDataLength);

#endif /* OPENSSLHELPERS_H_ */
