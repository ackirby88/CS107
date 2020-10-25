#!/bin/bash

SRCPATH=build/core/src/CMakeFiles/MyAwesomeLibrary.dir
TESTPATH=build/core/tests/src/CMakeFiles/MALTest.dir
BUILD_COV_DIRECTORY=coverage


# ====================== #
# check builds directory
# ====================== #
if [ ! -d "${BUILD_COV_DIRECTORY}" ]; then
  echo  "${BUILD_COV_DIRECTORY} does not exist. Making it..."
  mkdir "${BUILD_COV_DIRECTORY}"
fi

# Recompile code with COVERAGE enabled
echo "Rebuilding library with coverage flags!"
cd build
cmake -DCOVERAGE=ON .
make install
cd ..

# Build code coverage
cd ${BUILD_COV_DIRECTORY}

gcov ../${SRCPATH}/MyAwesomeLibrary.cpp.gcno
lcov --capture --directory ../${SRCPATH} -output-file AWESOME_COV.info
# gcov ../${TESTPATH}/test_MAL.gcno
# lcov --capture --directory ../${SRCPATH} -d ../${TESTPATH} --output-file AWESOME_COV.info
genhtml AWESOME_COV.info --output-directory CODE_COVERAGE

cd ..
echo 
echo "==================================================================================="
echo "Code Coverage generated in ./coverage/CODE_COVERAGE; Open index.html with browser."
echo "==================================================================================="

