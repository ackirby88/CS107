/**
 * File:   aio_file.h
 * Author: akirby
 *
 * Created on December 6, 2019, 11:47 AM
 */

#ifndef AIO_FILE_H
#define AIO_FILE_H

/* header files */
#include "aio_data.h"
#include "aio_utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ================= */
/* utility functions */
/* ================= */
typedef char (*ignore_file_type_func)(const unsigned char d_type);

/** Checks file/directory name and returns true if name starts with '.'
 *
 * @param [in] d_name  file/directory name
 * @return             true if name starts with '.'
 */
static inline
char ignore_dot(const char d_name[]){
    return (d_name[0] == '.');
}

static inline
void complete_file_path(char type_mode,char *output_path){
    switch(type_mode){
        case(DIRMODE): strcat(output_path,"directories."); break;
        case(FILEMODE): strcat(output_path,"files."); break;
        case(ANYMODE): strcat(output_path,""); break;
    }
    strcat(output_path,"txt");
}

/* ================ */
/* Public Functions */
/* ================ */
/** List directories, files, or both with optional file pattern
 *
 * @param [in] path       file path to search for directories/files
 * @param [in] type_mode  search mode directories(DIRMODE=0), files(FILEMODE=1), both(ANYMORE=2)
 * @param [in] pattern    file path pattern (can be NULL)
 * @param [in] outfile    bool to output listing to file (ls_info.txt)
 * @return                directories/files path information (only on MPIROOT)
 */
dirfile_into_t * file_directory_ls(const char *path,
                                   const char type_mode,
                                   const char *pattern,
                                   const char outfile);

dirfile_into_t * file_directory_ls2(const char *path,
                                    const char type_mode,
                                    const char *pattern,
                                    const char outfile);

dirfile_into_t * file_directory_ls2_mpi(ctx_t *ctx,
                                        const char *path,
                                        const char type_mode,
                                        const char *pattern,
                                        const char outfile,
                                        const char inform_all);

dirfile_into_t * file_directory_partition_list_mpi(ctx_t *ctx,
                                                   dirfile_into_t *info,
                                                   const unsigned int shuffle,
                                                   const unsigned int seed,
                                                   const unsigned int sample_pack_size,
                                                   const char inform_all);

#ifdef __cplusplus
}
#endif
#endif /* AIO_FILE_H */