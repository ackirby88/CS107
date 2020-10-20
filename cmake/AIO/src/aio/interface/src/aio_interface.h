/**
 * File:   aio_interface.h
 * Author: akirby
 *
 * Created on December 16, 2019, 12:05 PM
 */

#ifndef AIO_INTERFACE_H
#define AIO_INTERFACE_H

/* system header files */

/* header files */
#include "aio_data.h"
#include "aio_mpi.h"
#include "aio_file.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ============= */
/* API FUNCTIONS */
/* ============= */
int init(int argc, char **argv);

int shutdown();
int size();
int rank();

void shutdown_dirfile(dirfile_into_t *info);

dirfile_into_t * directory_search(char *path,char *pattern,int mode,int depth);

dirfile_into_t * partition_list(dirfile_into_t *info,
                                const unsigned int batch_size,
                                const unsigned int shuffle,
                                const unsigned int seed);

#ifdef __cplusplus
}
#endif
#endif /* AIO_INTERFACE_H */
