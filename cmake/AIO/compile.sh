#!/bin/bash -e

# ================== #
# compiling defaults
# ================== #
BUILD_3PL=0
BUILD_AIO=0
BUILD_TYPE=0
CLEAN_DIST=0

# ============== #
# print strings
# ============== #
opt_str="[OPTION] "

eC="\e[0m"
GC="\e[1;32m"
yC="\e[0;33m"
aC="\e[0;36m"
rC="\e[0;41m"
gC="\e[0;42m"
oC="\e[3;93m"
mC="\e[0;43m"

help() {
    echo "Usage: $0 [OPTION]...[COMPILER OPTIONS]...[3PL OPTIONS]"
    echo " "
    echo "  [OPTION]:"
    echo "    --3pl       -3pl    build the 3rd party libraries: gtest"
    echo "    --kernel    -kernel build the c-kernels"
    echo " "
    echo "    --help      -h      displays this help message"
    echo "    --clean     -c      removes local build directories"
    echo "    --distclean -dc     removes builds and install directories"
    echo "    --release   -opt    compile the project in optimized mode"
    echo "    --debug     -deb    compile the project in debug mode"
    echo "    --testsOFF  -toff   turn off unit tests (google tests)"
    echo " "
    echo "  [COMPILER OPTIONS]:"
    echo "     CC=<arg>   cc=<arg>    sets the C compiler"
    echo "    CXX=<arg>  cxx=<arg>    sets the C++ compiler"
    echo "     FC=<arg>   fc=<arg>    sets the Fortran compiler"
    echo " "
    echo "      C_FLAGS=<arg>    c_flags=<arg>    sets the C compiler flags"
    echo "    CXX_FLAGS=<arg>  cxx_flags=<arg>    sets the C++ compiler flags"
    echo "     FC_FLAGS=<arg>   fc_flags=<arg>    sets the Fortran compiler flags"
    echo " "
    echo "  [Intel Flags]:"
    echo "     --avx     -avx         sets Intel AVX Instructions"
    echo "     --avx2    -avx2        sets Intel AVX-2 Instructions"
    echo "     --avx512  -avx512      sets Intel AVX-512 Instructions"
    echo "     --mkl     -mkl         sets Intel MKL Library"
    echo " "
    echo "  [3PL OPTIONS]:"
    echo "    --ALL3P   -all3p  compile all 3rd party libraries"
    echo "    --GTEST   -gtest  compile google test"
    echo " "
    echo -e "  ${aC}Recommended Options:${eC}"
    echo "    Default (-go):"
    echo "      $0 CC=mpicc CXX=mpicxx FC=mpif90"
    echo " "
    echo "    Intel MPI (-impi): "
    echo "      $0 CC=mpiicc CXX=mpiicpc FC=mpiifort"
}

# ============ #
# parse inputs
# ============ #

if [[ $# -lt 1 ]]; then
  help
  exit 1
fi

for var in "$@"
do
  if [ "$var" == "--help" -o "$var" == "-help" -o "$var" == "-h" ]; then
    help
    exit 0

  elif [ "$var" == "--distclean" -o "$var" == "-distclean" -o "$var" == "-dc" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"
    echo ${opt_str} "Cleaning the distribution..."
    CLEAN_DIST=1

  elif [ "$var" == "--3pl" -o "$var" == "-3pl" -o "$var" == "-3pl" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"
    BUILD_3PL=1

  elif [ "$var" == "--GTEST" -o "$var" == "-gtest" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"
    BUILD_3PL=1

  elif [ "$var" == "--aio" -o "$var" == "-aio" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"
    BUILD_AIO=1

  elif [ "$var" == "--release" -o "$var" == "-release" -o "$var" == "-opt" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"
    BUILD_TYPE=0

  elif [ "$var" == "--debug" -o "$var" == "-debug" -o "$var" == "-deb" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"
    BUILD_TYPE=1

  elif [ "${var}" == "--clean" -o "$var" == "-clean" -o "$var" == "-c" -o \
         "${var}" == "--testsOFF" -o "$var" == "-testsOff" -o "$var" == "-toff" -o \
         "${var:0:3}" == "CC=" -o "${var:0:3}" == "cc=" -o \
         "${var:0:4}" == "CXX=" -o "${var:0:4}" == "cxx=" -o \
         "${var:0:3}" == "FC=" -o "${var:0:3}" == "fc=" -o \
         "${var:0:8}" == "C_FLAGS=" -o "${var:0:8}" == "c_flags=" -o \
         "${var:0:10}" == "CXX_FLAGS=" -o "${var:0:10}" == "cxx_flags=" -o \
         "${var:0:9}" == "FC_FLAGS=" -o "${var:0:9}" == "fc_falgs=" -o \
         "${var}" == "--avx" -o  "${var}" == "-avx" -o \
         "${var}" == "--avx2" -o  "${var}" == "-avx2" -o \
         "${var}" == "--avx512" -o  "${var}" == "-avx512" -o \
         "${var}" == "--ALL3PL" -o "$var" == "--all3pl" -o "$var" == "-all3pl" -o \
         "${var}" == "--GTEST" -o "$var" == "-gtest" -o \
         "${var}" == "--mkl" -o  "${var}" == "-mkl" -o \
         "${var}" == "-go" -o \
         "${var}" == "-impi" ]; then
    echo -e "Found known argument: ${gC}$var${eC}"

  else
    echo -e "${oC}Unknown option:${eC}  ${rC}$var${eC}"
    echo "See available options: ./build.sh -help"
    echo "Using Default Options..."

  fi
done

# ========================= #
# display command line args
# ========================= #
echo "$0 $@"
cmd_args="${@:1}"

# =================================================================== #
if [ $CLEAN_DIST == 1 ]; then
  rm -rf install
  rm -rf builds
  exit 0
fi
# =================================================================== #

# =================================================================== #
if [ $BUILD_AIO == 0 -a $BUILD_3PL == 0 ]; then
  echo "==========================================="
  echo "Building the 3rd Party Libraries and AIO..."
  echo "==========================================="
  echo " "

  cd scripts

  # build 3PL libraries
  ./build_3PL.sh $cmd_args

  # build kernels library
  ./build_aio.sh $cmd_args

  cd ..

  # make symbolic link to executable directory
  if [ ! -d "bin" ]; then
    ln -s ./builds/aio_release/bin
  fi

  echo
  echo "================================================"
  echo -e "${gC} Finished Successfully...${eC}"
  echo -e " Executable: ${GC}builds/aio_release/bin${eC}"
  echo "================================================"
  exit 0
fi

if [ $BUILD_3PL == 1 ]; then
  echo "========================================================"
  echo "Building the 3rd Party Libraries..."
  echo "========================================================"

  cd scripts
  ./build_3PL.sh $cmd_args
  cd ..
fi

if [ $BUILD_AIO == 1 ]; then
  echo "==============="
  echo "Building AIO..."
  echo "==============="

  cd scripts
  ./build_aio.sh $cmd_args
  cd ..

  # make symbolic link to executable directory
  if [ ! -d "bin" ]; then
    ln -s ./builds/aio_release/bin
  fi

  echo
  echo "================================================"
  echo -e "${GC} Finished Successfully...${eC}"
  echo "================================================"
  exit 0
fi
# =================================================================== #
