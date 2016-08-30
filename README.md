# Intro
Copyright (c) 2016, Electric Power Research Institute (EPRI)

This project (OADRLIB) provides a basis for implementing an OpenADR2.0b VEN.  Http pull is the only supported transport.

# Dependencies
The library has the following dependencies:
  * GTest (unit testing, source is inlcuded)  
  * code synthesis XSD 4.0.0 (included in the project)
  * curl (http/s communication) + any curl supported SSL library

Follow the instructions for your operating system to install `curl` and a curl
supported SSL library.

The library is built and tested on Ubuntu Linux 16.04.

# Build Instructions
OADRLIB uses cmake.  Here are general instructions for starting the build:
```
mkdir -p build/debug
cmake ../../
make
```

By default, these build steps will build the `oadr` and `oadrsd` libraries, and the
`samplevenmanager` executable.  To build the unit test program `testoadr`, change the cmake
command to the following:
```
cmake -DTEST=1 ../../
```

Running `testoadr` will execute the unit tests.

# Sample VEN Manager
The `samplevenmanager` directory demonstrates how to use the library.  The basic
steps are:
  1. Create a class which implements the folloiwng interfaces: IEventService,
     IReportService, IOadrMessage, and IOADRExceptionService.  In the sample, the
     class `VENImpl` implements these interfaces.  The OpenADR library will call
     these functions at the appropriate time.

  1. Create a `VENManagerConfig` object and populate the interfaces pointers and
     timeouts.  The interface pointers should point to your object (or objects)
     created in the previous step.

  1. Create a `VENManager` object by calling `VENManager::init()`, passing in the
     VENManagerConfig object created in the previous step.

  1. Call the run() function on the object created in the previous step to start
     the VEN.  This function call will block.  Start the VEN manager in its own
     thread if you don't want to block on the run function.
