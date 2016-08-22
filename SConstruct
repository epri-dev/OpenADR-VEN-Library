import glob
import os
import shutil
import sconsHelper

# save running directory
PWD = os.getcwd()

# get and parse arguments
buildmode = ARGUMENTS.get('mode', 'debug')   #holds current mode

if not (buildmode in ['debug', 'release']):
    print ("Error: Invalid build mode: {0}.  Please specify debug or release - aborting build.".format(buildmode))

print("BUILDING IN {0} mode.".format(buildmode))

if buildmode == 'debug':
    cflags = ['-pthread', '-Wall', '-O0', '-g3', '-c', '-Wl,--verbose', '-fmessage-length=0', '-D_CURL_DEBUG']
    
else:
    cflags = ['-pthread', '-O2', '-DNDEBUG', '-c', '-Wl,--verbose', '-fmessage-length=0']

# Make the environment variables available to child sconscripts.
Export('cflags buildmode')

# build oadrsd shared object (serialize/deserialize library)
SConscript('oadrsd/SConscript')

# build oadr shared object (VEN implementation)
SConscript('oadr/SConscript')

# unit tests
SConscript('oadrtest/SConscript')

# sample VEN
SConscript('sample/SConscript')
