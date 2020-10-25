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
template class AutoDiff<int>;
template class AutoDiff<float>;
template class AutoDiff<double>;

/* ======================== */
/* AutoDiff Class Operators */
/* ======================== */
template <class T>
void AutoDiff<T>::print_hello() const {
    printf("Hello\n");
}

template <class T>
const AutoDiff<T> AutoDiff<T>::operator+(const AutoDiff<T> &other) const {
    return AutoDiff<T>(v + other.val(), dv + other.dval());
}

template <class T>
AutoDiff<T>& AutoDiff<T>::operator+=(const AutoDiff<T> &other) {
    v += other.val();
    dv += other.dval();
    return *this;
}
