/*
 * File:   aio_data.h
 * Author: akirby
 *
 * Created on December 6, 2019, 10:01 AM
 */

#ifndef AIO_DATA_H
#define AIO_DATA_H

/* header files */
#include "precision_types.h"

/* system header files */
#ifndef DOXYGEN_IGNORE
#  include <mpi.h>
#  include <time.h>
#  include <stdio.h>
#  include <stddef.h>
#  include <stdlib.h>
#  include <string.h>
#  include <dirent.h>
#  include <unistd.h>
#  include <sys/types.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int nrequest;
    MPI_Request *request;
}
ghost_exchange_t;

/** @brief Context data structure of AIO. */
typedef struct {
    int rank;       /**< MPI rank */
    int nranks;     /**< Number of ranks in this communicator */
    MPI_Comm comm;  /**< MPI communicator */
}
ctx_t;

/** @brief Generic directory or file listing structure. */
typedef struct {
    unsigned int nentry;
    unsigned int path_len;
    char *entry_list;
}
dirfile_into_t;

/** Allocates and default initializes a directory_info_t data structure.
 * @return pointer to newly allocated directory_info
 */
static inline
dirfile_into_t * init_dirfile_info(void){
    dirfile_into_t *entry_info = (dirfile_into_t *) malloc(sizeof(dirfile_into_t));

    entry_info->nentry = 0;
    entry_info->path_len = BUFFSIZE;
    entry_info->entry_list = NULL;
    return entry_info;
}

/** Deallocates a dirfile_info_stacked_t data structure.
 * @param [in/out] dirfile_info_stacked  data structure to be deallocated
 * @return success flags
 */
static inline
char shutdown_dirfile_info(dirfile_into_t **entry_info){

    /* check not NULL */
    if(!(*entry_info)) return EXIT_SUCCESS;

    /* clean memory */
    free((*entry_info)->entry_list); (*entry_info)->entry_list = NULL;
    free(*entry_info); *entry_info = NULL;
    return EXIT_SUCCESS;
}
/* ========================================================================== */

#ifdef __cplusplus
}
#endif
#endif /* AIO_DATA_H */