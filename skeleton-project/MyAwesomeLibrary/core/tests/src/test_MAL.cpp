/* system header files */
#include <stdlib.h>
#include <stdio.h>

/* googletest header files */
#include "gtest/gtest.h"

/* header files */
#include "MyAwesomeLibrary.hpp"
#include "test_vars.h"

void MyAwesomeLibrary_testcheck(){
    printf("Starting Awesome Library tests...\n");
}

TEST(AwesomeLib,getter_int){
    int value = 3;
    int seed = 7;
    AutoDiff<int> x1(value,seed);

    /* test getters */
    EXPECT_EQ(x1.val(),value);  // note: EXECT_EQ used only for integers
    EXPECT_EQ(x1.dval(),seed);
}

TEST(AwesomeLib,getter_double){
    double value = 9.8;
    double seed = 1.0;
    AutoDiff<double> x(value,seed);

    /* test getters */
    EXPECT_NEAR(x.val(), value, DTOL);
    EXPECT_NEAR(x.dval(), seed, DTOL);
}
