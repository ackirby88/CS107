CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(Skeleton-App)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

# ======================================== #
# Include all shared libraries for GNU
if(NOT APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-as-needed")
else()
  set(CMAKE_MACOSX_RPATH ON)
endif()
# ======================================= #

# ======================================= #
# Library paths
set(gtest_dir   "" CACHE PATH "GTest install directory location")
set(awesome_dir "" CACHE PATH "MyAwesomeLibrary path e.g. <awesome_dir>/<awesome_so>")
set(awesome_so MyAwesomeLibrary CACHE STRING "Awesome shared object name")
# ======================================= #

# ======================================= #
# Library header files to be included
include_directories(${awesome_dir}/include
                    ./include)

# Libraries to be linked
find_library(awesome_lb NAMES ${awesome_so} PATHS ${awesome_dir}/lib)
# ======================================= #

# ======================================= #
# Source directories for this project
set(src_path src)
add_subdirectory(${src_path})
# ======================================= #

# ======================================= #
# Unit Testing Option - uses Google Test
OPTION(UNIT_TEST "Enable unit testing" OFF)
if(UNIT_TEST)
  include_directories(${src_path})
  add_subdirectory(tests)
endif()
# ======================================= #
