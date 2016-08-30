
#include <oadr/manager/VENManager.h>

#include "VENImpl.h"

#include "easylogging++.h"

#include <ostream>
#include <csignal>

shared_ptr<IVENManager> venManager;

string vtnURL;
string venName;

VENManagerConfig config;

bool logToStdout = true;

using namespace samplevenmanager;
using namespace std;

INITIALIZE_EASYLOGGINGPP

/********************************************************************************/

void signalHandler (int signum)
{
	venManager->stop();
}

/********************************************************************************/
void printUsage()
{
	cout << "Usage: " << endl;
	cout << "  ./samplevenmgr <vtn url> <ven name> true" << endl;
}

/********************************************************************************/

bool parseParams(int argc, char **argv)
{
	if (argc < 3)
		return false;

	config.vtnURL = argv[1];
	config.venName = argv[2];

	if (argc == 4 && strcmp(argv[3], "false") == 0)
		logToStdout = false;

	return true;
}

/********************************************************************************/

int main(int argc, char **argv)
{
	if (!parseParams(argc, argv))
	{
		printUsage();
		return 0;
	}

	shared_ptr<VENImpl> venImpl(new VENImpl(config.venName, logToStdout));

	config.services.eventService = venImpl.get();
	config.services.oadrMessage = venImpl.get();
	config.services.reportService = venImpl.get();
	config.services.exceptionService = venImpl.get();

	venManager = shared_ptr<IVENManager>(VENManager::init(config));

	signal(SIGINT, signalHandler);

	venManager->run();

	return 0;
}
