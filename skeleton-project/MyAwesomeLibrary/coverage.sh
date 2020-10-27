#!/bin/bash
set -euo pipefail

eC="\x1B[0m"
rC="\x1B[0;41m"

# =======================
# project directory paths
# =======================
# save path
CURRENT_PATH="$(pwd)"

# get project root
cd ..
MY_PATH="$( cd "$( dirname "$0" )" && pwd )"
PROJECT_ROOT=${MY_PATH}
cd ${CURRENT_PATH}

INSTALL_PATH=${PROJECT_ROOT}/install
INSTALL_GTEST=${INSTALL_PATH}/googletest/include/gtest

SRCPATH=${CURRENT_PATH}/build/core/src/CMakeFiles/MyAwesomeLibrary.dir
TESTPATH=${CURRENT_PATH}/build/core/tests/src/CMakeFiles/MALTest.dir
COVERAGE_DIRECTORY=${CURRENT_PATH}/coverage

TEST_SRC_PATH=${CURRENT_PATH}/core/tests

# ======================
# check builds directory 
# ======================
if [ ! -d "${COVERAGE_DIRECTORY}" ]; then
  echo  "${COVERAGE_DIRECTORY} does not exist. Making it..."
  mkdir "${COVERAGE_DIRECTORY}"
fi

# Recompile code with COVERAGE enabled
echo "Rebuilding library with coverage flags!"
cd build
cmake -DCOVERAGE=ON .
make install
cd ..

# ===================
# cuild code coverage
# ===================
cd ${COVERAGE_DIRECTORY}

# gather coverage info
if [ -d "${TESTPATH}" ]; then
    lcov --capture -d ${SRCPATH} -d ${TESTPATH} -o AWESOME_COV.info
else
    echo -e "${rC}ERROR:${eC} Need to compile GTEST to get code coverage!"
    exit 1
fi

# remove usr and gtest info
lcov --remove AWESOME_COV.info "/usr/*" "${INSTALL_PATH}/*" "${TEST_SRC_PATH}/*" -o AWESOME_COV.info

# generate html version of coverage
genhtml AWESOME_COV.info -o CODE_COVERAGE
cd ..

echo 
echo "==========================================================="
echo "Code Coverage generated in ./coverage/CODE_COVERAGE;"
echo " >>> Open ./coverage/CODE_COVERAGE/index.html with browser."
echo "==========================================================="
