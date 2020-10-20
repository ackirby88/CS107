/**
 * File:   memory_utilities.h
 * Author: akirby
 *
 * Created on November 25, 2019, 12:54 PM
 */

#ifndef MEMORY_UTILITIES_H
#define MEMORY_UTILITIES_H

/* data header files */
#include "precision_types.h"

/* system header files */
#ifndef DOXYGEN_IGNORE
#  include <math.h>
#  include <stdio.h>
#  include <stdlib.h>
#  include <malloc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/** Utility function to get current memory usage
 *
 * @param [in] mpi_rank     this mpi rank
 * @param [in] display      flag indicator to display usage to console
 * @return                  current memory usage
 */
static inline
size_t memory_usage(int mpi_rank,int display){

    /* get malloc info structure */
    struct mallinfo my_mallinfo = mallinfo();

    /*total memory reserved by the system for malloc currently */
    size_t reserved_mem = my_mallinfo.arena;

    /* get all the memory currently allocated to user by malloc, etc. */
    size_t used_mem = my_mallinfo.hblkhd
                    + my_mallinfo.usmblks
                    + my_mallinfo.uordblks;

    /* get memory not currently allocated to user but malloc controls */
    size_t free_mem = my_mallinfo.fsmblks
                    + my_mallinfo.fordblks;

    /* get number of items currently allocated */
    /* double number_allocated = my_mallinfo.ordblks + my_mallinfo.smblks; */

    /* Print out concise malloc info line */
    if(display){
        printf("Rank[%d]: %f MB(%lu) malloc: %.0f MB reserved (%lu unused)\n",
            mpi_rank,
            used_mem / (1024.0 * 1024.0),
            used_mem,
            reserved_mem / (1024.0 * 1024.0),
            free_mem);
    }
    return used_mem;
}

static inline
size_t memory_state(size_t mem1,size_t mem2,int mpi_rank,int display){
    size_t mem_diff = mem2 - mem1;

    if(display){
        printf("\033[1;32m[Memory] Rank[%d]: %f MB(%lu) difference \033[0m\n",
            mpi_rank,
            mem_diff / (1024.0 * 1024.0),
            mem_diff);
    }
    return mem_diff;
}

#ifdef __cplusplus
}
#endif
#endif /* MEMORY_UTILITIES_H */