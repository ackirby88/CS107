/* header files */
#include "gtest/gtest.h"
#include "test_vars.h"

int main(int argc,char **argv){
    /* Initialize Google Test */
    ::testing::InitGoogleTest(&argc,argv);

    /* this forces the testing library to link */
    App_testcheck();

    /* Run Tests */
    return RUN_ALL_TESTS();
}
