enable_testing()
include(CTest)

include_directories(${gtest_dir}/include)
find_library(gtest      NAMES gtest      gtestd      HINTS "${gtest_dir}/lib")
find_library(gtest_main NAMES gtest_main gtest_maind HINTS "${gtest_dir}/lib")

set(TEST_EXE AIO.Tests)
set(TEST_SRC_PATH src)

# include test headers
include_directories(src)

set(libs
    ${gtest} ${gtest_main}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_subdirectory(${TEST_SRC_PATH})
add_executable(${TEST_EXE} test_main.cpp)

target_link_libraries(${TEST_EXE} aio_test aio_kernels ${libs})
target_link_libraries(${TEST_EXE} pthread)

add_test(NAME ${TEST_EXE} COMMAND $<TARGET_FILE:${TEST_EXE}>)

add_custom_command(
   TARGET ${TEST_EXE}
   COMMENT "Run AIO Unit Tests"
   POST_BUILD
   COMMAND ${TEST_EXE}
)
