/**
 * @file    MyAwesomeLibrary.cpp
 * @author  Andrew Kirby
 * @brief   MyAwesomeLibrary implementations.
 *
 * Created on October 21, 2020, 1:50 PM
 */

/* header files */
#include "MyAwesomeLibrary.hpp"

/* explicitly tell compiler to build these templates */
//template class AutoDiff<int>;
//template class AutoDiff<float>;
//template class AutoDiff<double>;

/* ======================== */
/* AutoDiff Class Operators */
/* ======================== */
template <class T>
void AutoDiff<T>::print_hello() const {
    printf("Hello\n");
}
