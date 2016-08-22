import glob
import os
import shutil

from SCons.Script import *

#
# binaryType: shared, static, program
#
def build(artifact, includes, cflags, libpath, libs, buildmode, binaryType):
	
	env = Environment(CPPPATH = includes, CCFLAGS = cflags, LIBPATH = libpath, LIBS = libs)
	
	print("Preparing artifact {0}".format(artifact))

	list = []

	for root, dirnames, filenames in os.walk(artifact):

		print("  adding dir {0}".format(buildmode + "/" + root))

		# print root, dirnames, filenames
		env.VariantDir(buildmode + "/" + root, root, duplicate=0)

		list = list + Glob(buildmode + "/" + root + "/*.cpp")
		list = list + Glob(buildmode + "/" + root + "/*.cxx")

	if binaryType == "shared":
		env.SharedLibrary(buildmode + "/" + artifact, list)

	elif binaryType == "program":
		env.Program(buildmode + "/" + artifact + ".out", list)

