/**
 * \file    aio_file.c
 * \ingroup kernels
 * \author  akirby
 *
 * \brief   AIO file functions.
 */

/* header files */
#include "aio_file.h"

/* ================= */
/* Private Functions */
/* ================= */
char keep_directories(const unsigned char d_type){
    /* ignore all but directories */
    return (d_type != DT_DIR);
}

char keep_files(const unsigned char d_type){
     /* ignore all but files */
    return (d_type != DT_REG);
}

char keep_files_directories(const unsigned char d_type){
     /* ignore all but files and directories */
    return ((d_type != DT_REG) && (d_type != DT_DIR));
}

unsigned int file_directory_search_this(const char *path,
                                        const char type_mode,
                                        const char fill_mode,
                                        char *list_paths){
    DIR *dirp;
    unsigned int ndir;
    struct dirent *entry;
    ignore_file_type_func ignore_func;

    dirp = opendir(path);
    if(!dirp) return 0;

    switch(type_mode){
        case(ANYMODE):  ignore_func = keep_files_directories; break;
        case(DIRMODE):  ignore_func = keep_directories; break;
        case(FILEMODE): ignore_func = keep_files; break;
    }

    ndir = 0;
    if (fill_mode) {
        assert(list_paths);
        while ((entry = readdir(dirp))) {
            if(ignore_dot(entry->d_name) || ignore_func(entry->d_type)) continue;
            strcpy(&list_paths[BUFFSIZE*ndir],path);
            strcat(&list_paths[BUFFSIZE*ndir],"/");
            strcat(&list_paths[BUFFSIZE*ndir],entry->d_name);
            ++ndir;
        }
    } else {
        /* count entries only */
        while ((entry = readdir(dirp))) {
            if(ignore_dot(entry->d_name) || ignore_func(entry->d_type)) continue;
            ++ndir;
        }
    }
    closedir(dirp);
    return ndir;
}

unsigned int file_directory_search_this_pattern(const char *path,
                                                const char type_mode,
                                                const char fill_mode,
                                                char *list_paths,
                                                const char *str_pattern){
    DIR *dirp;
    unsigned int ndir;
    struct dirent *entry;
    ignore_file_type_func ignore_func;

    dirp = opendir(path);
    if(!dirp) return 0;

    switch(type_mode){
        case(ANYMODE):  ignore_func = keep_files_directories; break;
        case(DIRMODE):  ignore_func = keep_directories; break;
        case(FILEMODE): ignore_func = keep_files; break;
    }

    ndir = 0;
    if (fill_mode) {
        assert(list_paths);
        while ((entry = readdir(dirp))) {
            if(ignore_dot(entry->d_name) || ignore_func(entry->d_type) || !strstr(entry->d_name,str_pattern)) continue;

            strcpy(&list_paths[BUFFSIZE*ndir],path);
            strcat(&list_paths[BUFFSIZE*ndir],"/");
            strcat(&list_paths[BUFFSIZE*ndir],entry->d_name);
            strcat(&list_paths[BUFFSIZE*ndir],"                                                 ");
            ++ndir;
        }
    } else {
        /* count entries only */
        while ((entry = readdir(dirp))) {
            if(ignore_dot(entry->d_name) || ignore_func(entry->d_type) || !strstr(entry->d_name,str_pattern)) continue;
            ++ndir;
        }
    }
    closedir(dirp);
    return ndir;
}

/* ================ */
/* Public Functions */
/* ================ */
dirfile_into_t * file_directory_ls(const char *path,
                                   const char type_mode,
                                   const char *pattern,
                                   const char outfile){
    dirfile_into_t *entry_info = init_dirfile_info();
    unsigned int nentry;
    unsigned int i;
    char fillmode;

    /* -------------------------------- *
     * type_mode:                       *
     *   DIRMODE (0) = read directories *
     *   FILEMODE(1) = read files       *
     * -------------------------------- */

    fillmode = 0;
    if (!pattern) {
        nentry = file_directory_search_this(path,type_mode,fillmode,NULL);
    } else {
        nentry = file_directory_search_this_pattern(path,type_mode,fillmode,NULL,pattern);
    }

    /* allocate and fill directory paths */
    if (nentry) {
        fillmode = 1;

        entry_info->nentry = nentry;
        entry_info->path_len = BUFFSIZE;
        entry_info->entry_list = (char *) malloc(BUFFSIZE*nentry*sizeof(char));

        if (!pattern) {
            file_directory_search_this(path,type_mode,fillmode,entry_info->entry_list);
        } else {
            file_directory_search_this_pattern(path,type_mode,fillmode,entry_info->entry_list,pattern);
        }
    }

    /* write listing to file */
    if (outfile) {
        char output_path[80];
        strcpy(output_path,"search_results."); complete_file_path(type_mode,output_path);

        FILE *fp = fopen(output_path,"w");
        fprintf(fp,"Number of Entries: %d\n",nentry);
        for (i = 0; i < nentry; ++i) {
            fprintf(fp,"%s\n",&entry_info->entry_list[BUFFSIZE*i]);
        }
        fclose(fp);
    }
    return entry_info;
}

dirfile_into_t * file_directory_ls2(const char *path,
                                    const char type_mode,
                                    const char *pattern,
                                    const char outfile){

    dirfile_into_t *entry_info = init_dirfile_info();
    unsigned int nentry = 0;
    unsigned int i,p;
    char fillmode;

    /* 1st layer directories */
    dirfile_into_t *dir_info = file_directory_ls(path,DIRMODE,NULL,0);

    /* 2nd layer entries */
    fillmode = 0;
    for (p = 0; p < dir_info->nentry; ++p) {
        if (!pattern) {
            nentry += file_directory_search_this(&dir_info->entry_list[BUFFSIZE*p],
                                                 type_mode,fillmode,NULL);
        } else {
            nentry += file_directory_search_this_pattern(&dir_info->entry_list[BUFFSIZE*p],
                                                         type_mode,fillmode,NULL,pattern);
        }
    }

    /* allocate and fill directory paths */
    if (nentry) {
        fillmode = 1;

        entry_info->nentry = nentry;
        entry_info->path_len = BUFFSIZE;
        entry_info->entry_list = (char *) malloc(BUFFSIZE*nentry*sizeof(char));

        /* reset entry counter */
        nentry = 0;
        if (!pattern) {
            for (p = 0; p < dir_info->nentry; ++p) {
                nentry += file_directory_search_this(&dir_info->entry_list[BUFFSIZE*p],type_mode,fillmode,
                                                     &entry_info->entry_list[BUFFSIZE*nentry]);
            }
        } else {
            for (p = 0; p < dir_info->nentry; ++p) {
                nentry += file_directory_search_this_pattern(&dir_info->entry_list[BUFFSIZE*p],type_mode,fillmode,
                                                             &entry_info->entry_list[BUFFSIZE*nentry],pattern);
            }
        }
    }

    /* write listing to file */
    if (outfile) {
        char output_path[20];
        strcpy(output_path,"search_results."); complete_file_path(type_mode,output_path);

        FILE *fp = fopen(output_path,"w");
        fprintf(fp,"Number of Entries: %d\n",nentry);
        for (i = 0; i < nentry; ++i) {
            fprintf(fp,"%s\n",&entry_info->entry_list[BUFFSIZE*i]);
        }
        fclose(fp);
    }

    /* free memory */
    shutdown_dirfile_info(&dir_info);
    return entry_info;
}

dirfile_into_t * file_directory_ls2_mpi(ctx_t *ctx,
                                        const char *path,
                                        const char type_mode,
                                        const char *pattern,
                                        const char outfile,
                                        const char inform_all){

    dirfile_into_t *entry_info = init_dirfile_info();
    dirfile_into_t *entry_info_global = init_dirfile_info();

    int *displs = NULL;
    int *recvcounts = NULL;

    unsigned int nentry = 0;
    unsigned int nentry_global = 0;
    unsigned int ndirectories_global = 0;

    unsigned int start_file_ind;
    unsigned int end_file_ind;
    unsigned int i,p;
    char fillmode;

    /* mpi_gatherv buffer setup */
    if (inform_all || ctx->rank == MPIROOT) {
        displs     = (int *) malloc(ctx->nranks*sizeof(int));
        recvcounts = (int *) malloc(ctx->nranks*sizeof(int));
    }

    /* all ranks read first level list */
    dirfile_into_t *dir_info = file_directory_ls(path,DIRMODE,NULL,0);
    MPI_Allreduce(&dir_info->nentry,&ndirectories_global,1,MPI_UNSIGNED,MPI_MAX,ctx->comm);

    if(!ndirectories_global) {
        shutdown_dirfile_info(&dir_info);
        if(ctx->rank == MPIROOT) printf("[ls] No Files Found! Returning...\n");
        return NULL;
    }

    /* ================= *
     * 2nd layer entries *
     * ================= */
    /* all ranks partition the first level list of directories */
    aio_utilites_local_file_index(ctx->rank,ctx->nranks,
                                  dir_info->nentry,
                                 &start_file_ind,
                                 &end_file_ind);

    /* count number of entries on this rank */
    fillmode = 0;
    if (!pattern) {
        for (p = start_file_ind; p <= end_file_ind; ++p) {
            nentry += file_directory_search_this(&dir_info->entry_list[BUFFSIZE*p],
                                                 type_mode,fillmode,NULL);
        }
    } else {
        for (p = start_file_ind; p <= end_file_ind; ++p) {
            nentry += file_directory_search_this_pattern(&dir_info->entry_list[BUFFSIZE*p],
                                                         type_mode,fillmode,NULL,pattern);
        }
    }

    /* get global count of entries */
    MPI_Allreduce(&nentry,&nentry_global,1,MPI_UNSIGNED,MPI_SUM,ctx->comm);
    if (inform_all) {
        MPI_Allgather(&nentry,1,MPI_UNSIGNED,recvcounts,1,MPI_UNSIGNED,ctx->comm);
    } else {
        MPI_Gather(&nentry,1,MPI_UNSIGNED,recvcounts,1,MPI_UNSIGNED,MPIROOT,ctx->comm);
    }

    /* convert recv counts to total buffer byte size */
    if (inform_all || ctx->rank == MPIROOT) {
        for (i = 0; i < ctx->nranks; ++i) {
            recvcounts[i] *= BUFFSIZE;
        }
    }

    /* set displacements */
    if (inform_all || ctx->rank == MPIROOT) {
        displs[0] = 0;
        for (i = 1; i < ctx->nranks; ++i) {
            displs[i] = displs[i-1] + recvcounts[i-1];
        }
    }

    /* allocate and fill directory paths on this rank */
    if (nentry) {
        fillmode = 1;

        entry_info->nentry = nentry;
        entry_info->path_len = BUFFSIZE;
        entry_info->entry_list = (char *) malloc(BUFFSIZE*nentry*sizeof(char));

        /* reset entry counter */
        nentry = 0;
        if (!pattern) {
            for (p = start_file_ind; p <= end_file_ind; ++p) {
                nentry += file_directory_search_this(&dir_info->entry_list[BUFFSIZE*p],type_mode,fillmode,
                                                     &entry_info->entry_list[BUFFSIZE*nentry]);
            }
        } else {
            for (p = start_file_ind; p <= end_file_ind; ++p) {
                nentry += file_directory_search_this_pattern(&dir_info->entry_list[BUFFSIZE*p],type_mode,fillmode,
                                                             &entry_info->entry_list[BUFFSIZE*nentry],pattern);
            }
        }
    }

    /* =========================== */
    /* form global list on MPIROOT */
    /* =========================== */
    if (nentry_global) {
        entry_info_global->nentry = nentry_global;
        entry_info_global->path_len = BUFFSIZE;
        if (inform_all || ctx->rank == MPIROOT) {
            entry_info_global->entry_list = (char *) malloc(BUFFSIZE*nentry_global*sizeof(char));
        }

        if (inform_all) {
            MPI_Allgatherv(entry_info->entry_list,entry_info->nentry*BUFFSIZE,MPI_CHAR,
                           entry_info_global->entry_list,recvcounts,displs,MPI_CHAR,
                           ctx->comm);
        } else {
            MPI_Gatherv(entry_info->entry_list,entry_info->nentry*BUFFSIZE,MPI_CHAR,
                        entry_info_global->entry_list,recvcounts,displs,MPI_CHAR,
                        MPIROOT,ctx->comm);
        }
    }

    /* write listing to file */
    if (outfile) {
        if (ctx->rank == MPIROOT) {
            char output_path[20];
            strcpy(output_path,"search_results."); complete_file_path(type_mode,output_path);

            FILE *fp = fopen(output_path,"w");
            fprintf(fp,"Number of Entries: %d\n",entry_info_global->nentry);
            for (i = 0; i < entry_info_global->nentry; ++i) {
                fprintf(fp,"%s\n",&entry_info_global->entry_list[BUFFSIZE*i]);
            }
            fclose(fp);
        }
    }

    /* free memory */
    if(displs) free(displs); displs = NULL;
    if(recvcounts) free(recvcounts); recvcounts = NULL;

    shutdown_dirfile_info(&dir_info);
    shutdown_dirfile_info(&entry_info);

    return entry_info_global;
}

dirfile_into_t * file_directory_partition_list_mpi(ctx_t *ctx,
                                                   dirfile_into_t *info,
                                                   const unsigned int shuffle,
                                                   const unsigned int seed,
                                                   const unsigned int sample_pack_size,
                                                   const char inform_all){
    dirfile_into_t *info_local = init_dirfile_info();

    unsigned int *file_index_local = NULL;
    unsigned int *file_index = NULL;

    unsigned int start_ind,end_ind;
    unsigned int nsample_max;
    unsigned int nsample;
    unsigned int r,i;

    int nsent;
    int mpi_tag;
    int nrequest;

    int *displs = NULL;
    int *sendcounts = NULL;
    char *send_buffer = NULL;
    MPI_Request *requests = NULL;

    /* check if info is valid */
    if (!info) {
        shutdown_dirfile_info(&info_local);
        return NULL;
    }

    /* generate shuffled file index vector on root */
    if (ctx->rank == MPIROOT) {
        file_index = aio_utilities_shuffle(info->nentry,shuffle,seed);
    }

    /* each rank determine number of files will host */
    nsample = aio_utilites_local_packfile_index(ctx->rank,ctx->nranks,
                                                info->nentry,sample_pack_size,
                                                &start_ind,&end_ind);

    /* setup out variable */
    info_local->nentry = nsample;
    info_local->path_len = BUFFSIZE;
    info_local->entry_list = (char *) malloc(nsample*BUFFSIZE*sizeof(char));

    if (inform_all) {
        /* ================================================================== *
         * every rank has a copy of the global file list: distribute indices  *
         * ================================================================== */
        file_index_local = (unsigned int *) malloc(nsample*sizeof(unsigned int));

        if (ctx->rank == MPIROOT) {
            displs     = (int *) malloc(ctx->nranks*sizeof(int));
            sendcounts = (int *) malloc(ctx->nranks*sizeof(int));
        }

        /* set send counts on root */
        if (ctx->rank == MPIROOT) {
            for (i = 0; i < ctx->nranks; ++i) {
                sendcounts[i] =
                    aio_utilites_local_packfile_index(i,ctx->nranks,
                                                      info->nentry,sample_pack_size,
                                                      &start_ind,&end_ind);
            }

            /* set displacements */
            displs[0] = 0;
            for (i = 1; i < ctx->nranks; ++i) {
                displs[i] = displs[i-1] + sendcounts[i-1];
            }
        }
        /* distribute shuffled file indices */
        MPI_Scatterv(file_index,sendcounts,displs,MPI_UNSIGNED,
                     file_index_local,nsample,MPI_UNSIGNED,
                     MPIROOT,ctx->comm);

        /* each rank has a copy of the global file list: copy to local list */
        for (i = 0; i < nsample; ++i) {
            strncpy(&info_local->entry_list[BUFFSIZE*i],
                    &info->entry_list[BUFFSIZE*file_index_local[i]],
                    BUFFSIZE);
        }

        /* free memory */
        if(displs) free(displs); displs = NULL;
        if(sendcounts) free(sendcounts); sendcounts = NULL;
        if(file_index_local) free(file_index_local); file_index_local = NULL;

    } else {
        /* ================================================================== *
         * paths only on root: distribute paths to ranks via nonblocking call *
         * ================================================================== */
        requests = (MPI_Request *) malloc(2*ctx->nranks*sizeof(MPI_Request));
        nrequest = 0;
        mpi_tag = 44;

        /* all ranks: post receive for file paths from root */
        MPI_Irecv(info_local->entry_list,info_local->nentry*BUFFSIZE,MPI_CHAR,
                  MPIROOT,mpi_tag,ctx->comm,&requests[nrequest++]);

        /* root: send file paths to each rank */
        MPI_Reduce(&nsample,&nsample_max,1,MPI_UNSIGNED,MPI_MAX,MPIROOT,ctx->comm);
        if (ctx->rank == MPIROOT) {
            send_buffer = (char *) malloc(nsample_max*BUFFSIZE*sizeof(char));

            /* loop all ranks to send paths */
            for (r = 0; r < ctx->nranks; ++r) {
                nsample =
                    aio_utilites_local_packfile_index(r,ctx->nranks,info->nentry,
                                                      sample_pack_size,
                                                      &start_ind,&end_ind);

                /* pack send buffer */
                nsent = 0;
                for (i = start_ind; i <= end_ind; ++i) {
                    strncpy(&send_buffer[BUFFSIZE*nsent],
                            &info->entry_list[BUFFSIZE*file_index[i]],
                            BUFFSIZE);
                    ++nsent;
                }
                MPI_Isend(send_buffer,nsample*BUFFSIZE,MPI_CHAR,r,mpi_tag,ctx->comm,&requests[nrequest++]);
            }
        }
        MPI_Waitall(nrequest,requests,MPI_STATUSES_IGNORE);

        /* free memory */
        if(requests) free(requests); requests = NULL;
        if(send_buffer); free(send_buffer); send_buffer = NULL;
    }

    /* free memory */
    if(file_index) free(file_index); file_index = NULL;

    return info_local;
}