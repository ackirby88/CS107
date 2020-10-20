/**
 * \file    aio_utilities.c
 * \ingroup kernels
 * \author  akirby
 *
 * \brief   AIO utility functions.
 */

/* header files */
#include "aio_utilities.h"

unsigned int * aio_utilities_shuffle(unsigned int nsamples,
                                     unsigned int shuffle,
                                     unsigned int seed){
    unsigned int *vec;
    unsigned int i, j;

    /* initialize random number generator with seed */
    srand(seed);

    /* allocate shuffle vector */
    vec = (unsigned int *) malloc(nsamples * sizeof(unsigned int));

    /* initialize vec to have index as value */
    for (i = 0; i < nsamples; ++i) vec[i] = i;

    /* shuffle random index from 0 to i */
    if (shuffle) {
        for (i = nsamples - 1; i > 0; --i) {
            j = (unsigned) rand() % (i + 1);
            aio_utilities_swap(&vec[i],&vec[j]);
        }
    }

    /* return shuffled vector list */
    return vec;
}

void aio_utilites_local_file_index(const int rank,
                                   const int nranks,
                                   const unsigned int nfiles,
                                   unsigned int *start_file_ind,
                                   unsigned int *end_file_ind){
    unsigned int ave_nfiles      = nfiles / nranks;
    unsigned int nfiles_loc      = ave_nfiles;
    unsigned int remaining_files = nfiles - ave_nfiles*nranks;
    unsigned int first_batch     = remaining_files*(ave_nfiles + 1);

    /* local rank calculation */
    if (rank < remaining_files) ++nfiles_loc;

    /* local rank calculation */
    if (rank < remaining_files) {
        *start_file_ind = (rank  )*nfiles_loc;
        *end_file_ind   = (rank+1)*nfiles_loc - 1;
    } else {
        *start_file_ind = first_batch + (rank   - remaining_files)*nfiles_loc;
        *end_file_ind   = first_batch + (rank+1 - remaining_files)*nfiles_loc - 1;
    }
}

unsigned int aio_utilites_local_packfile_index(const int rank,
                                               const int nranks,
                                               const unsigned int nfiles,
                                               const unsigned int pack_size,
                                               unsigned int *start_file_ind,
                                               unsigned int *end_file_ind){
    unsigned int npacks_whole = nfiles / pack_size;
    unsigned int npacks_ave = npacks_whole / nranks;
    unsigned int npacks_loc = npacks_ave;
    unsigned int remaining_packs = npacks_whole - npacks_ave*nranks;

    unsigned int first_batch = remaining_packs*(npacks_ave + 1)*pack_size;
    unsigned int nfiles_loc;
    int nsample;

    /* local rank calculation */
    if (rank < remaining_packs) ++npacks_loc;

    nfiles_loc = npacks_loc * pack_size;

    /* local rank calculation */
    if (rank < remaining_packs) {
        *start_file_ind = (rank  )*nfiles_loc;
        *end_file_ind   = (rank+1)*nfiles_loc - 1;
    } else {
        *start_file_ind = first_batch + (rank   - remaining_packs)*nfiles_loc;
        *end_file_ind   = first_batch + (rank+1 - remaining_packs)*nfiles_loc - 1;
    }

    /* last rank will pack remainder files */
    if(rank == (nranks-1)) *end_file_ind = nfiles - 1;
    nsample = *end_file_ind - *start_file_ind + 1;

    return (nsample > 0) ? nsample:0;
}