CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(MyAwesomeLibrary)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

# force GNU linker to include all shared libraries
if(NOT APPLE)
  set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-as-needed")
else()
  set(CMAKE_MACOSX_RPATH ON)
endif()


# ======================== #
# location of header files
# ======================== #
include_directories(include)

# ========================================================= #
# location of directory to search for next "CmakeLists.txt"
# ========================================================= #
add_subdirectory(core)
