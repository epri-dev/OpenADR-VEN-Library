cmake_minimum_required (VERSION 2.8)
project (OADR)
set(LIBOADR_MAJOR_VERSION 1)
set(LIBOADR_MINOR_VERSION 0)
set(LIBOADR_MICRO_VERSION 0)
set(LIBOADR_VERSION ${LIBOADR_MAJOR_VERSION}.${LIBOADR_MINOR_VERSION}.${LIBOADR_MICRO_VERSION})

# Library notes:
# apt-get install libxerces-c-dev
# apt-get install libcurl4-gnutls-dev

# options off-by-default that you can enable
option(WERROR "Set all warnings to errors" OFF)
option(STATICLIBS "Builds static versions of all installed libraries" OFF)
option(TEST "Build the test suite" OFF)
option(SAMPLE "Build sample ven manager" ON)

if(STATICLIBS)
  set(LIB_TYPE STATIC)
else()
  set(LIB_TYPE SHARED)
endif()

# assume gcc/clang otherwise
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

# different release and debug flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")

if (WERROR)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif()

set(CMAKE_REQUIRED_FLAGS ${CMAKE_CXX_FLAGS})

# include paths for all the local libraries
include_directories(oadr)
include_directories(oadrsd)
include_directories(xsd-4.0.0)

# ---- liboadr ----
file(GLOB_RECURSE oadr_SRC ./oadr/oadr/*.cpp)
add_library(oadr ${LIB_TYPE} ${oadr_SRC})
install(TARGETS oadr DESTINATION lib)
set(INSTALL_ARGS FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ./oadr/oadr DESTINATION include ${INSTALL_ARGS})

# ---- liboadrsd ----
file(GLOB_RECURSE oadrsd_SRC ./oadrsd/oadrsd/*.cxx)
add_library(oadrsd ${LIB_TYPE} ${oadrsd_SRC})
install(TARGETS oadrsd DESTINATION lib)
set(INSTALL_ARGS FILES_MATCHING PATTERN "*.hxx" PATTERN "*.txx" PATTERN "*.ixx")
install(DIRECTORY ./oadrsd/oadrsd DESTINATION include ${INSTALL_ARGS})
install(DIRECTORY ./xsd-4.0.0/xsd DESTINATION include ${INSTALL_ARGS})

if (SAMPLE)
  # ---- samplevenmanager ----
  add_definitions(-DELPP_THREAD_SAFE -DELPP_NO_DEFAULT_LOG_FILE)
  file(GLOB_RECURSE samplevenmanager_SRC ./samplevenmanager/samplevenmanager/*.cpp)
  add_executable(samplevenmgr ${samplevenmanager_SRC})
  target_link_libraries (samplevenmgr LINK_PUBLIC oadr oadrsd curl xerces-c pthread)
endif()

if (TEST)
  
  add_subdirectory(googletest-release-1.7.0)

  include_directories(googletest-release-1.7.0/include)
  link_directories(googletest-release-1.7.0/lib)
  set (CMAKE_REQUIRED_INCLUDES googletest-release-1.7.0/include)

  # file(COPY )
  file(REMOVE_RECURSE ./xml)
  file(COPY ./oadrtest/oadrtest DESTINATION ./xml FILES_MATCHING PATTERN "*.xml" PATTERN "*.txt")
  
  # ---- tests ----
  file(GLOB_RECURSE oadrtest_SRC ./oadrtest/oadrtest/*.cpp)
  add_executable(testoadr ${oadrtest_SRC})
  target_link_libraries (testoadr LINK_PUBLIC oadr oadrsd curl xerces-c gtest pthread)

endif()

