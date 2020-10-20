/**
 * \file    test_vars.h
 * \ingroup tests_group
 * \author  akirby
 * Created on April 18, 2019, 6:26 PM
 */

#ifndef TEST_VARS_H
#define TEST_VARS_H

/* googletest header files */
#include "gtest/gtest.h"

/* header files */
#include "precision_types.h"
#include "memory_utilities.h"

/* system header files */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifdef SINGLE_PRECISION
#  define EXPECT_EQUAL_TEST EXPECT_FLOAT_EQ
#  define TOL  2.0e-6
#  define VTOL 3.9e-6
#  define DTOL 9.2e-5
#  define STOL 8.0e-4
#else
#  define EXPECT_EQUAL_TEST EXPECT_DOUBLE_EQ
#  define TOL  2.8e-15
#  define VTOL 4.7e-14
#  define DTOL 2.1e-13
#  define STOL 5.9e-12
#endif

#define TIMER(x,time_loc){        \
    Real t1_loc = (Real) clock(); \
    (x);                          \
    Real t2_loc = (Real) clock(); \
    (time_loc) = (t2_loc - t1_loc)/CLOCKS_PER_SEC; \
}

#ifdef __cplusplus
}
#endif
#endif /* TEST_VARS_H */