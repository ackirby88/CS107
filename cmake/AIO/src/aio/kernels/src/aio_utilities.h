/*
 * File:   aio_utilities.h
 * Author: akirby
 *
 * Created on November 25, 2019, 11:14 AM
 */

#ifndef AIO_UTILITIES_H
#define AIO_UTILITIES_H

/* header files */
#include "aio_data.h"

#ifdef __cplusplus
extern "C" {
#endif

/* =============== */
/* utility defines */
/* =============== */
#define B2GB(x) ((Real) x)/1024.0/1024.0/1024.0

/* ================= */
/* utility functions */
/* ================= */
/** Swap function for unsigned integer pointers
 *
 * @param [inout] a  unsigned int pointer a
 * @param [inout] b  unsigned int pointer b
 */
static inline
void aio_utilities_swap(unsigned int *a, unsigned int *b){
    unsigned int temp = *a; *a = *b; *b = temp;
}

void aio_utilites_local_file_index(const int rank,
                                   const int nranks,
                                   const unsigned int nfiles,
                                   unsigned int *start_file_ind,
                                   unsigned int *end_file_ind);

unsigned int aio_utilites_local_packfile_index(const int rank,
                                               const int nranks,
                                               const unsigned int nfiles,
                                               const unsigned int pack_size,
                                               unsigned int *start_file_ind,
                                               unsigned int *end_file_ind);

/** Shuffle function which allocates and returns a shuffled 1D unsigned vector
 *
 * @param [in] nsamples  size of unsigned vector
 * @param [in] seed      random seed for generating shuffled vector
 * @return               shuffled 1D vector of unsigned integers
 */
unsigned int * aio_utilities_shuffle(unsigned int nsamples,
                                     unsigned int shuffle,
                                     unsigned int seed);

/** Display function for array of unsigned integers
 *
 * @param [in] arr  1D vector of unsigned integers
 * @param [in] n    size of vector
 */
static inline
void printArray1D_UnsigedInt(unsigned int *arr, unsigned int n) {
    unsigned int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#ifdef __cplusplus
}
#endif
#endif /* AIO_UTILITIES_H */