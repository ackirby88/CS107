CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# name project whatever you want
PROJECT(demo1)

# location of header files
include_directories(./include)

# location of directory to search for next "CMakeLists.txt"
add_subdirectory(./src)
