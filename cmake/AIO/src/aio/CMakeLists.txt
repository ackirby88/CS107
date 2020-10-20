CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(AIO)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# force GNU linker to include all shared libraries
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-as-needed")

set(gtest_dir "" CACHE PATH "gtest install directory location")

# ======================================= #
# Library header files to be included
include_directories(./include)
# ======================================= #

# ====================== #
# Compiler warning flags #
# ====================== #
# Intel
set(C_INTEL_WARNINGS
  "-Wall -Wunused-variable -Wunused-function -Wuninitialized"
)
set(F90_INTEL_WARNINGS
  "-warn all -check all"
)

# GNU
set(C_GNU_WARNINGS
  "-Wall -Wextra -Wconversion"
)
set(F90_GNU_WARNINGS
  "-Wall -Wextra" #-Wconversion"
)

# ================== #
# Set compiler flags #
# ================== #
if(CMAKE_C_COMPILER_ID MATCHES "Intel")
  # Intel optimization flag
  add_definitions( -march=core-avx2 )

  # Compiler warnings
  set(CMAKE_C_FLAGS ${C_INTEL_WARNINGS})
  set(CMAKE_FORTRAN_FLAGS ${F90_INTEL_WARNINGS})
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
  # Compiler warnings
  set(CMAKE_C_FLAGS ${C_GNU_WARNINGS})
  set(CMAKE_FORTRAN_FLAGS ${F90_GNU_WARNINGS})
endif ()

# ======================================= #
# LAPACK/MKL library
# ======================================= #
OPTION(MKL_LIB "Use Intel MKL Library" OFF)
if(MKL_LIB)
  set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../../cmake/")
endif ()

# ======================================= #
# Compile in single precision
# add_definitions(-DSINGLE_PRECISION)
# ======================================= #

# ======================================= #
# Source directories for this project
add_subdirectory(kernels/src)
add_subdirectory(tools/src)
add_subdirectory(interface/src)
# ======================================= #

# ======================================= #
# Unit Testing Option - uses Google Test
OPTION(UNIT_TEST "Build Unit Tests" ON)
if(UNIT_TEST)
  include_directories(kernels/src)
  add_subdirectory(kernels/tests)
endif ()
# ======================================= #
