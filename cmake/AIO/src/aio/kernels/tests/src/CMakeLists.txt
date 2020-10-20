enable_testing()
include(CTest)

include_directories(${gtest_dir}/include)
link_directories(${gtest_dir}/lib/gtest)

file(GLOB AIO_TEST_H *.h)
set(AIO_TEST_SRC
    aio_utilities_shuffle_test.cpp
    aio_utilities_listfiles_test.cpp
)

add_library(aio_test SHARED ${AIO_TEST_SRC} ${AIO_TEST_H})