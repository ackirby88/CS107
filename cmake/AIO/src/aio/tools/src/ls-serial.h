/**
 * \File:   ls-serial.h
 * \Author: akirby
 *
 * Created on December 12, 2019, 11:18 AM
 */

#ifndef LS_SERIAL_H
#define LS_SERIAL_H

/* util header files */
#include "command_line.h"

/* AIO header files */
#include "aio_data.h"
#include "aio_file.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TIMER(x,time_loc){     \
    Real t1 = (Real) clock(); \
    (x);                          \
    Real t2 = (Real) clock(); \
    (time_loc) = (t2-t1)/CLOCKS_PER_SEC; \
}

#ifdef __cplusplus
}
#endif
#endif /* LS_SERIAL_H */