/* header files */
#include "aio_utilities_shuffle_test.h"

int main(int argc,char **argv){
    /* Initialize Google Test */
    ::testing::InitGoogleTest(&argc,argv);

    /* display shuffle test */
    aio_utilities_testcheck();

    /* Run Tests */
    return RUN_ALL_TESTS();
}
