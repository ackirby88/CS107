# AIO
AIO is a distributed preprocessor and front-end data load interface to many common Machine Learning frameworks.

## Cloning AIO
  git clone git@github.mit.edu:ackirby/AIO.git
  
## Compilation
    To compile AIO and the 3rd party libraries (googletest):  
    ./compile.sh <options>

**Usage**: ./compile.sh `{OPTIONS}`...`{COMPILER OPTIONS}`...`{3PL OPTIONS}`  

| OPTIONS:             | Shortcut    | Description                                        |
|:---------------------|-------------|:---------------------------------------------------|
| --3pl                | -3pl        | build the 3rd party libraries: gtest               |
| --kernel             | -kernel     | build the AIO c library kernels                    |
|                      |             |                                                    |
| --help               | -h          | displays this help message                         |
| --clean              | -c          | removes local build directories                    |
| --distclean          | -dc         | removes builds and install directories             |
| --release            | -opt        | compile the project in optimized mode              |
| --debug              | -deb        | compile the project in debug mode                  |
| --testsOFF           | -toff       | turn off unit tests (Google tests)                 |
|                      |             |                                                    |
| **COMPILER OPTIONS**:|             |                                                    |
| CC=`<arg>`           | cc=`<arg>`  | set the C compiler                                 |
| CXX=`<arg>`          | cxx=`<arg>` | set the C++ compiler                               |
| FC=`<arg>`           | fc=`<arg>`  | set the Fortran compiler                           |
|                      |             |                                                    |
| **Intel Flags**      |             |                                                    |
| --avx                | -avx        | set Intel AVX Instructions                         |
| --avx2               | -avx2       | set Intel AVX-2 Instructions                       |
| --avx512             | -avx512     | set Intel AVX-512 Instructions                     |
| --mkl                | -mkl        | use Intel MKL Library                              |
|                      |             |                                                    |
| **3PL OPTIONS**:     |             |                                                    |
| --ALL3P              | -all3p      | compile all 3rd party libraries                    |
| --GTEST              | -gtest      | compile google test                                |

## Recommended Build Options:
**Default (-go)**: Sets CC=mpicc CXX=mpicxx FC=mpif90 and builds third party libraries and kernels.  
    ./compile.sh -go

**Intel MPI (-impi)**: Sets CC=mpiicc CXX=mpiicpc FC=mpiifort  
    ./compile.sh -impi
    
**C Kernels Only (-kernel)**: Builds only the c library kernels only.  
    ./compile.sh -kernel
    
---
## Dependencies
    Software:
        CMake (Version 2.8 or newer): We also recommend ccmake or cmake-gui.
        MPI: optional MPI-3 one-sided functions available
        libtool: apt install libtool
        automake: apt install automake
        zlib: apt install zlib1g zlibc
        
    Documentation:
        doxygen: apt install doxygen
        graphviz: apt install graphviz
        latex: apt install texlive-full texmaker
