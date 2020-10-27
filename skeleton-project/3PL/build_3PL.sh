#!/bin/bash -e
# Folder structure:
# ================
# project_root
#   install         #install directory
#     3PL           #install to this folder
#   builds          #build directory
#   sources         #source codes
#     3PL           #location of 3rd party library source code
#   scripts         #location of this script

set -euo pipefail

# ======================= #
# project directory paths
# ======================= #
CURRENT_PATH="$(pwd)"

cd ..
PROJECT_ROOT="$(pwd)"
cd ${CURRENT_PATH}

# ====================== #
# folder directory paths
# ====================== #
INSTALL_DIRECTORY=${PROJECT_ROOT}/install
INSTALL_3PL_DIRECTORY=${INSTALL_DIRECTORY}/3PL

# ============== #
# 3PL sources
# ============== #
SOURCES_DIRECTORY=${PROJECT_ROOT}/src
SOURCES_3PL_DIRECTORY=${PROJECT_ROOT}/3PL

# ================== #
# compiling defaults
# ================== #
BUILD_GTEST=0
BUILD_CLEAN=0

# ================= #
# compiler defaults
# ================= #
CC=gcc
CXX=g++
FC=gfortran

CFLAGS="-fPIC -O2"

# ======================== #
# compiler option defaults
# ======================== #
BUILD_SUFFIX="_release"
BUILD_TYPE="Release"

# ======================== #
# make and install command
# ======================== #
MAKE_CMD="make install"

# ============== #
# print strings
# ============== #
opt_str="[OPTION] "

eC="\x1B[0m"
rC="\x1B[0;41m"
gC="\x1B[0;42m"
yC="\x1B[0;33m"
mC="\x1B[0;43m"

help() {
    echo "Usage: $0 [OPTION]...[COMPILER OPTIONS]...[3PL OPTIONS]"
    echo " "
    echo "  This script builds the 3rd party libraries: "
    echo "       google test (gtest)"
    echo " "
    echo "  [OPTION]:"
    echo "    --help    -h      displays this help message"
    echo "    --clean   -c      removes build directory: dg4est/builds/dg4est_{}"
    echo "    --release -opt    compile the project in optimized mode"
    echo "    --debug   -deb    compile the project in debug mode"
    echo " "
    echo "  [COMPILER OPTIONS]:"
    echo "     CC=<arg>     cc=<arg>    sets the C compiler"
    echo "    CXX=<arg>    cxx=<arg>    sets the C++ compiler"
    echo "     FC=<arg>     fc=<arg>    sets the Fortran compiler"
    echo " "
    echo "      C_FLAGS=<arg>    c_flags=<arg>    sets the C compiler flags"
    echo "    CXX_FLAGS=<arg>  cxx_flags=<arg>    sets the C++ compiler flags"
    echo "     FC_FLAGS=<arg>   fc_flags=<arg>    sets the Fortran compiler flags"
    echo " "
    echo "  [3PL OPTIONS]:"
    echo "    --ALL3P  -all3p      comile all 3rd party libraries"
    echo "    --GTEST  -gtest    compile google test"
    echo " "
    echo -e "  ${aC}Easy Build:${eC}"
    echo -e "  Default: ${yC}./build_3PL.sh -go${eC}"
}

# ----------------------------- #
# Start the compilation process #
# ----------------------------- #
cd $PROJECT_ROOT

# ============ #
# parse inputs
# ============ #
for var in "$@"
do
  if [ "$var" == "--help" -o "$var" == "-help" -o "$var" == "-h" ]; then
    help
    exit 0
  elif [ "$var" == "--clean" -o "$var" == "-clean" -o "$var" == "-c" ]; then
    echo ${opt_str} "Clean and rebuild"
    BUILD_CLEAN=1

  elif [ "$var" == "--release" -o "$var" == "-release" -o "$var" == "-opt" ]; then
    echo ${opt_str} "Compiling in optimized mode"
    BUILD_SUFFIX="_release"
    BUILD_TYPE="Release"

  elif [ "$var" == "--debug" -o "$var" == "-debug" -o "$var" == "-deb" ]; then
    echo ${opt_str} "Compiling in debug mode"
    BUILD_SUFFIX="_debug"
    BUILD_TYPE="Debug"

  elif [ "${var:0:3}" == "CC=" -o "${var:0:3}" == "cc=" ]; then
    CC=${var:3}
    echo -e "[OPTION]       C Compiler: $yC$CC$eC"

  elif [ "${var:0:4}" == "CXX=" -o "${var:0:4}" == "cxx=" ]; then
    CXX=${var:4}
    echo -e "[OPTION]     CXX Compiler: $yC$CXX$eC"

  elif [ "${var:0:3}" == "FC=" -o "${var:0:3}" == "fc=" ]; then
    FC=${var:3}
    echo -e "[OPTION] Fortran Compiler: $yC$FC$eC"

  elif [ "$var" == "--GTEST" -o "$var" == "-gtest" ]; then
    BUILD_GTEST=1
  elif [ "$var" == "--ALL3P" -o "$var" == "--all3p" -o "$var" == "-all3p" ]; then
    BUILD_GTEST=1
  fi
done

# if no 3PL are selected, compile all of them
if [ $BUILD_GTEST == 0 ]; then
  BUILD_GTEST=1
fi

# ========================= #
# display command line args
# ========================= #
echo " "
echo "$0 $@"

# ----------------------------------------------------- #
# After reading in cmd arg options, set remaining paths #
# ----------------------------------------------------- #

# ====================================== #
# install/build location compiled source
# ====================================== #
COMPILE_INSTALL_3PL_DIRECTORY="${INSTALL_3PL_DIRECTORY}${BUILD_SUFFIX}"

# ============== #
# compiler paths
# ============== #
CC_PATH="`which $CC`"
CXX_PATH="`which $CXX`"

# ====================== #
# check source directory
# ====================== #
if [ ! -d "${SOURCES_3PL_DIRECTORY}" ]; then
  echo "${rC}ERROR: {SOURCES_3PL_DIRECTORY} does not exist.${eC}"
  exit 1
fi

# ======================= #
# check install directory
# ======================= #
if [ ! -d "${INSTALL_DIRECTORY}" ]; then
  echo  "${INSTALL_DIRECTORY} does not exist. Making it..."
  mkdir "${INSTALL_DIRECTORY}"
fi

# =================================================================== #
COMPILE_FAIL=0
INSTALL_GTEST_DIRECTORY=${INSTALL_3PL_DIRECTORY}/googletest
if [ ${BUILD_GTEST} -eq 1 ]; then
  echo " "
  echo -e "${mC} ==== Building Google Test ==== ${eC}"
  echo " Compiling Options:"
  echo "        Build Type: ${BUILD_TYPE}"
  echo "  Install Location: ${INSTALL_GTEST_DIRECTORY}"
  echo " "
  echo "                CC: ${CC}"
  echo "               CXX: ${CXX}"
  echo -e "${mC} ========================= ${eC}"
  echo " "

  cd ${SOURCES_3PL_DIRECTORY}/googletest-release-1.8.1
  rm -rf buildW
  rm -rf ${INSTALL_GTEST_DIRECTORY}
  mkdir buildW

  cd buildW
  cmake -D CMAKE_INSTALL_PREFIX:PATH=${INSTALL_GTEST_DIRECTORY} \
        -D CMAKE_BUILD_TYPE:STRING=${BUILD_TYPE}                \
        -D SHARED:BOOL=TRUE                                     \
        -D CMAKE_C_COMPILER=${CC_PATH}                          \
        -D CMAKE_CXX_COMPILER=${CXX_PATH}                       \
        -G "Unix Makefiles" ../

  ${MAKE_CMD}
  cd ..
  rm -rf buildW
  cd ${CURRENT_PATH}

  if [ ! -d "${INSTALL_GTEST_DIRECTORY}" ]; then
    echo "Warning:"
    echo "${INSTALL_GTEST_DIRECTORY} does not exist."
    COMPILE_FAIL=1
  fi

  if [ ${COMPILE_FAIL} == 0 ]; then
    echo " "
    echo         "==============================="
    echo -e "${gC} Google Test build successful! ${eC}"
    echo         "==============================="
    echo " "
  else
    echo " "
    echo         "==========================="
    echo -e "${rC} Google Test build FAILED! ${eC}"
    echo         "==========================="
    echo " "
    exit 1
  fi
fi
# =================================================================== #

echo -e "${gC}Build Script Completed Successfully!${eC}"
exit 0
