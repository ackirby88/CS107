enable_testing()
include(CTest)

include_directories(${gtest_dir}/include)
link_directories(${gtest_dir}/lib/gtest)

file(GLOB TEST_H *.h *.hpp)

set(TEST_SRC
    test_MAL.cpp
)

add_library(MALTest SHARED ${TEST_SRC} ${TEST_H})
