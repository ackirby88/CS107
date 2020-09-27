cmake_minimum_required(VERSION 3.7)

project(matplotlib_ex)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -DWITHOUT_NUMPY")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# for matplotlibcpp
set(PYTHON_INCLUDE_DIR "/usr/local/include/python3.7m")
set(PYTHON_LIBRARY "/usr/local/lib/libpython3.7m.so")

find_package(PythonLibs 3.7 REQUIRED)
add_definitions(-DWITHOUT_NUMPY)

include(ExternalProject)
ExternalProject_Add(matplotlibcpp_repo
                    GIT_REPOSITORY "https://github.com/lava/matplotlib-cpp.git"
		    CONFIGURE_COMMAND ""
	            BUILD_COMMAND ""
                    INSTALL_COMMAND "")
	   
set(MATPLOTLIB_INCLUDE_DIR ${CMAKE_BINARY_DIR}/matplotlibcpp_repo-prefix/src/matplotlibcpp_repo)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRC_H src/*.h src/*.hpp)
set(SRC_FILES
    src/plot0.cpp
    src/plot1.cpp
    # add new source files here
)

# build shared library
add_library(ex_lib SHARED ${SRC_FILES} ${SRC_H})
target_include_directories(ex_lib PRIVATE ${PYTHON_INCLUDE_DIRS} ${MATPLOTLIB_INCLUDE_DIR})

add_executable(example src/main.cpp)
add_dependencies(example matplotlibcpp_repo)
target_include_directories(example PRIVATE ${PYTHON_INCLUDE_DIRS} ${MATPLOTLIB_INCLUDE_DIR})
target_link_libraries(example ex_lib ${PYTHON_LIBRARIES})

install(TARGETS example ex_lib
	RUNTIME DESTINATION bin/
	LIBRARY DESTINATION lib/
	ARCHIVE DESTINATION lib/
)
