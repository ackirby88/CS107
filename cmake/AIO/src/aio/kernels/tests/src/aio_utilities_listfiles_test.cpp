/* header files */
#include "aio_utilities_listfiles_test.h"

/* ========================================================================== */
/* HELPER FUNCTIONS                                                           */
/* ========================================================================== */
char read_dirfiles(char level,const char path[],const char type_mode,
                   const char pattern[],const char outfile,
                   const char display){
    dirfile_into_t *info;
    char test_str[BUFFSIZE];
    char test_name[BUFFSIZE];

    Real wall_time;
    unsigned int i;

    switch(type_mode){
        case(DIRMODE):
            strcpy(test_str,"Directories");
            strcpy(test_name,"[Directory]");
            break;
        case(FILEMODE):
            strcpy(test_str,"Files");
            strcpy(test_name,"     [File]");
            break;
        case(ANYMODE):
            strcpy(test_str,"Directories & Files");
            strcpy(test_name," [Dir&File]");
            break;
    }

    /* Input path from user */
    printf(" %s %s Path checking: %s\n",test_name,test_str,path);
    printf(" %s Begin Read %s ...",test_name,test_str); fflush(stdout);

    /* read files/directories function */
    if(level == 1){
        TIMER(
            info = file_directory_ls(path,type_mode,pattern,outfile), // function
            wall_time                                                 // wall-clock time
        );
    } else if(level == 2) {
        TIMER(
            info = file_directory_ls2(path,type_mode,pattern,outfile), // function
            wall_time                                                  // wall-clock time
        );
    }

    printf(" Done\n");
    printf(" %s Time: %.6f sec\n",test_name,wall_time);
    printf(" %s Number of %s:  %d\n",test_name,test_str,info->nentry);

    EXPECT_EQUAL_TEST(info->path_len,BUFFSIZE);
    if (display) {
        for (i = 0; i < info->nentry; ++i) {
            printf("[%d] %s\n",i,info->entry_list[i]);
        }
    }

    /* free memory */
    shutdown_dirfile_info(&info);
    return EXIT_SUCCESS;
}
/* -------------------------------------------------------------------------- */

/* ========================================================================== */
/* TESTS                                                                      */
/* ========================================================================== */
TEST(AIO_UTILITIES,read_directories_layer1){
    char path[] = ".";
    char *pattern = NULL;
    char outfile = 1;
    char display = 0;
    char level = 1;

    read_dirfiles(level,path,DIRMODE,pattern,outfile,display);
}

TEST(AIO_UTILITIES,read_files_layer1){
    char path[] = ".";
    char *pattern = NULL;
    char outfile = 1;
    char display = 0;
    char level = 1;

    read_dirfiles(level,path,FILEMODE,pattern,outfile,display);
}

TEST(AIO_UTILITIES,read_all_layer1){
    char path[] = ".";
    char *pattern = NULL;
    char outfile = 1;
    char display = 0;
    char level = 1;

    read_dirfiles(level,path,ANYMODE,pattern,outfile,display);
}
/* -------------------------------------------------------------------------- */
