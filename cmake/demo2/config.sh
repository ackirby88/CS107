#!/bin/bash

# ======================= #
# project directory paths 
# ======================= #
MY_PATH="$( cd "$( dirname "$0" )" && pwd )"
PROJECT_ROOT=${MY_PATH}/.

echo "My Path: ${PROJECT_ROOT}"

# ================================= #
# set Build and Install directories 
# ================================= #
BUILD_DIRECTORY=${PROJECT_ROOT}/build
INSTALL_DIRECTORY=${PROJECT_ROOT}/install


# ====================== #
# check builds directory
# ====================== #
if [ ! -d "${BUILD_DIRECTORY}" ]; then
  echo  "${BUILD_DIRECTORY} does not exist. Making it..."
  mkdir "${BUILD_DIRECTORY}"
fi

# =============== #
# move to ./build
# =============== #
cd ${BUILD_DIRECTORY}

# =========================== #
# configure CMake environment 
# =========================== #
cmake .. -DCMAKE_INSTALL_PREFIX=${INSTALL_DIRECTORY}
