/**
 * File:   precision_types.h
 * Author: akirby
 *
 * Created on November 25, 2019, 12:36 PM
 */

#ifndef PRECISION_TYPES_H
#define PRECISION_TYPES_H

/* system header files */
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/** double/float data type overload */
#ifndef SINGLE_PRECISION
#  define Real double
#  define MPI_AIOREAL MPI_DOUBLE
#  define MPI_AIOREAL_INT MPI_DOUBLE_INT
#  define RealFormat "%le"
#  define RealString "double"
#  define IntFormat  "%d"
#else
#  define Real float
#  define MPI_AIOREAL MPI_FLOAT
#  define MPI_AIOREAL_INT MPI_FLOAT_INT
#  define RealFormat "%f"
#  define RealString "float"
#  define IntFormat  "%d"
#endif

#define MPIROOT 0
#define BUFFSIZE 128

#define DIRMODE 0
#define FILEMODE 1
#define ANYMODE 2

#ifdef __cplusplus
}
#endif
#endif /* PRECISION_TYPES_H */