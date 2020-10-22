enable_testing()
include(CTest)

include_directories(${gtest_dir}/include)
link_directories(${gtest_dir}/lib/gtest)

file(GLOB TEST_H *.h *.hpp)

set(TEST_SRC
    test_app.cpp
)

add_library(AppTest SHARED ${TEST_SRC} ${TEST_H})
