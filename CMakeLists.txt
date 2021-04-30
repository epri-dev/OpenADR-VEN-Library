cmake_minimum_required (VERSION 3.13)
project (OADR)
set(LIBOADR_MAJOR_VERSION 1)
set(LIBOADR_MINOR_VERSION 0)
set(LIBOADR_MICRO_VERSION 0)
set(LIBOADR_VERSION ${LIBOADR_MAJOR_VERSION}.${LIBOADR_MINOR_VERSION}.${LIBOADR_MICRO_VERSION})

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CMAKE_C_COMPILER_LAUNCHER   ${CCACHE_PROGRAM})
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

# Library notes:
# apt-get install libxerces-c-dev
# apt-get install libcurl4-gnutls-dev

# options off-by-default that you can enable
option(WERROR "Set all warnings to errors" OFF)
option(STATICLIBS "Builds static versions of all installed libraries" OFF)
option(TEST "Build the test suite" OFF)
option(SAMPLE "Build sample ven manager" ON)
option(COVERAGE "Build with coverage support" OFF)

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

if(COVERAGE)
  set(COVERAGE_COMPILE_OPTIONS --coverage -g -O0)
  set(COVERAGE_LINK_OPTIONS --coverage)
endif()

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
target_compile_options(oadr PRIVATE ${COVERAGE_COMPILE_OPTIONS})
target_link_options(oadr PRIVATE ${COVERAGE_LINK_OPTIONS})

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
  target_link_libraries (samplevenmgr LINK_PUBLIC oadr oadrsd curl xerces-c xml-security-c pthread)
  target_compile_options(samplevenmgr PRIVATE ${COVERAGE_COMPILE_OPTIONS})
  target_link_options(samplevenmgr PRIVATE ${COVERAGE_LINK_OPTIONS})
endif()

if (TEST)
  add_subdirectory(googletest-release-1.7.0)

  include_directories(googletest-release-1.7.0/include)
  link_directories(googletest-release-1.7.0/lib)
  set (CMAKE_REQUIRED_INCLUDES googletest-release-1.7.0/include)

  # file(COPY )
  file(REMOVE_RECURSE ./xml)
  file(COPY ./oadrtest/oadrtest DESTINATION ./xml FILES_MATCHING PATTERN "*.xml" PATTERN "*.txt" PATTERN "*.der" PATTERN "*.pem")

  # ---- tests ----
  file(GLOB_RECURSE oadrtest_SRC ./oadrtest/oadrtest/*.cpp)
  add_executable(testoadr ${oadrtest_SRC})
  target_link_libraries (testoadr LINK_PUBLIC oadr oadrsd curl xerces-c xml-security-c gtest pthread)
  target_compile_options(testoadr PRIVATE ${COVERAGE_COMPILE_OPTIONS})
  target_link_options(testoadr PRIVATE ${COVERAGE_LINK_OPTIONS})
endif()
