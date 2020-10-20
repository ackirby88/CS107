/** MPI wrapper functions for AIO code module.
 *
 * \file    aio_mpi.c
 * \ingroup kernels
 * \author  akirby
 *
 * \brief   Wrapper functions around MPI.
 */

/* header files */
#include "aio_mpi.h"

int mpi_init(int argc,char **argv,ctx_t *ctx){
    /* initialize MPI */
    int mpi_return = MPI_Init(&argc,&argv);
    ctx->comm = MPI_COMM_WORLD;

    /* assign MPI rank and size */
    MPI_Comm_rank(ctx->comm,&ctx->rank);
    MPI_Comm_size(ctx->comm,&ctx->nranks);
    return mpi_return;
}

void mpi_init_from_comm(MPI_Comm *comm,ctx_t *ctx){
    /* initialize MPI information from communicator */
    ctx->comm = *comm;

    /* assign MPI rank and size */
    MPI_Comm_rank(ctx->comm,&ctx->rank);
    MPI_Comm_size(ctx->comm,&ctx->nranks);
}

int mpi_finalize(){
    return MPI_Finalize();
}
