/**
 * \file    test_vars.h
 * \ingroup tests_group
 * \author  akirby
 */

#ifndef TEST_VARS_H
#define TEST_VARS_H

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
#  define TOL  3.6e-15
#  define VTOL 4.7e-14
#  define DTOL 2.1e-13
#  define STOL 5.9e-12
#endif


/** Display testing information */
void App_testcheck();


#ifdef __cplusplus
}
#endif
#endif /* TEST_VARS_H */
