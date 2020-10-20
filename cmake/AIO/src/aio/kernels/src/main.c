/** Main function for testing the AIO framework.
 * \file    main.c
 * \author  akirby
 *
 * \brief   Main function for the AIO code module.
 */

/* header files */
#include "aio_data.h"
#include "aio_mpi.h"
#include "aio_file.h"

int main(int argc, char **argv){
    char *pattern = NULL;
    dirfile_into_t *info_local = NULL;
    dirfile_into_t *info_parallel = NULL;
    int ret = EXIT_SUCCESS;

    unsigned int sample_pack_size = 64;
    unsigned int shuffle = 1;
    unsigned int seed = 2; //(unsigned int) time(NULL);

    Real partition_timer;
    Real parallel_timer;

    char path[BUFFSIZE] = "/home/akirby/Mass3/Data/ML-test/ImageNet-Sample/train";
    char inform_all = 0;
    char outfile = 0;

    /* ====================================================================== */
    /* initialize mpi & ctx data                                              */
    /* ====================================================================== */
    ctx_t ctx = {0,1,MPI_COMM_WORLD};
    ret |= mpi_init(argc,argv,&ctx);

    MPIROOTONLY(printf("MPI Initialized:\n\tTotal Ranks %d\n",ctx.nranks),ctx.rank);

    /* ====================================================================== */
    /* TEST: subdirectory path searching                                      */
    /* ====================================================================== */
    /* parallel version: info only valid on MPIROOT */
    MPITIMER(
        info_parallel = file_directory_ls2_mpi(&ctx,path,ANYMODE,pattern,outfile,inform_all),
        parallel_timer
    );

    MPIROOTONLY(printf("Parallel elapsed time is %f\n",parallel_timer),ctx.rank);
    if (ctx.rank == MPIROOT) {
        if (info_parallel) {
            printf("\tNumber of files found: %d\n",info_parallel->nentry);
        }
    }

    MPITIMER(
        info_local = file_directory_partition_list_mpi(&ctx,info_parallel,
                                                       shuffle,seed,
                                                       sample_pack_size,
                                                       inform_all),
        partition_timer
    );
    MPIROOTONLY(printf("Partition elapsed time is %f\n",partition_timer),ctx.rank);

    printf("Rank[%d]: # files %d\n",ctx.rank,info_local->nentry);
    /* ====================================================================== */
    /* free memory and shutdown mpi                                           */
    /* ====================================================================== */
    shutdown_dirfile_info(&info_local);
    shutdown_dirfile_info(&info_parallel);
    ret |= mpi_finalize();

    return ret;
}