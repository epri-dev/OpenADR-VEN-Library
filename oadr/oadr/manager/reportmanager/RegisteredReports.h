/*
 * RegisteredReports.h
 *
 *  Created on: Sep 10, 2014
 *      Author: dupes
 */

#ifndef REGISTEREDREPORTS_H_
#define REGISTEREDREPORTS_H_

#include <iostream>
#include <set>
#include <map>

#include <oadrsd/2b/oadrRegisterReportType.hxx>
#include <oadrsd/2b/oadrReportType.hxx>
#include <oadrsd/2b/oadrReportDescriptionType.hxx>

using namespace oadr2b::oadr;
using namespace std;

class RegisteredReports
{
private:
	map<string, set<string>> m_reports;

public:
	RegisteredReports();
	virtual ~RegisteredReports();

	void loadRegisteredReports(
			oadrRegisterReportType::oadrReport_sequence &sequence);

	bool reportExists(string reportID);
	bool reportDescriptionExists(string reportID, string reportDescriptionID);
};

#endif /* REGISTEREDREPORTS_H_ */
