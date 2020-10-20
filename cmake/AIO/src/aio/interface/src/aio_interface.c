/**
 * \file    aio_interface.c
 * \author  akirby
 */

/* header files */
#include "aio_interface.h"

/* static data */
ctx_t ctx = {0,1,MPI_COMM_WORLD};

int init(int argc,char **argv){
    return mpi_init(argc,argv,&ctx);
}

int shutdown(){
    return mpi_finalize();
}

int size(){
    return ctx.nranks;
}

int rank(){
    return ctx.rank;
}

dirfile_into_t * directory_search(char *path,char *pattern,int mode,int depth){
    if (depth) {
        return file_directory_ls2_mpi(&ctx,path,(char) mode,pattern,0,0);
    } else {
        return file_directory_ls(path,mode,pattern,0);
    }
}

dirfile_into_t * partition_list(dirfile_into_t *info,
                                const unsigned int batch_size,
                                const unsigned int shuffle,
                                const unsigned int seed){
    return file_directory_partition_list_mpi(&ctx,info,shuffle,seed,batch_size,0);
}


void shutdown_dirfile(dirfile_into_t *info){
    shutdown_dirfile_info(&info);
    if(info) printf("Info deallocated Failed!\n");
}