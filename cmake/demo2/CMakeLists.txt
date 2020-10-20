CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# name project whatever you want
PROJECT(demo2)

# set output directories for "make"
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# use RPATH for "install" command -- enables the execuatable to find the shared library
set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

# location of header files
include_directories(./include)

# location of directory to search for next "CmakeLists.txt"
add_subdirectory(./src)
