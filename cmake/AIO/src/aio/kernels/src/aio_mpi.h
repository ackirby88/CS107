/*
 * File:   aio_mpi.h
 * Author: akirby
 *
 * Created on December 6, 2019, 9:58 AM
 */

#ifndef AIO_MPI_H
#define AIO_MPI_H

/* header files */
#include "aio_data.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MPITIMER(x,time_loc){     \
    Real t1 = (Real) MPI_Wtime(); \
    (x);                          \
    Real t2 = (Real) MPI_Wtime(); \
    (time_loc) = (t2-t1); \
}

#define MPIROOTONLY(x,rank){if((rank) == MPIROOT) (x);}

/** MPI and p4est initialization function wrapper
 *
 * @param [in]    argc      number of command line arguments
 * @param [in]    argv      command line arguments
 * @param [inout] ctx       context data
 */
int mpi_init(int argc,char **argv,ctx_t *ctx);

/** MPI and p4est initialization function wrapper given a mpi communicator
 *
 * @param [in]    comm              mpi communicator
 * @param [inout] ctx               context data
 * @param [in]    log_threshold     logging threshold flag
 */
void mpi_init_from_comm(MPI_Comm *comm,ctx_t *ctx);

/** Build derived data type for shipping custom data
 *
 */
void mpi_build_derived_custom_data_type();

/** MPI finalization function wrapper
 *
 * @return mpi finalize success
 */
int mpi_finalize();


#ifdef __cplusplus
}
#endif
#endif /* AIO_MPI_H */