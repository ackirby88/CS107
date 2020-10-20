/** Main for parallel ls function in AIO Tools.
 * \File    ls-parallel.c
 * \Author  akirby
 *
 * \brief   Main function for parallel ls function in AIO tools module.
 */

/* header files */
#include "ls-parallel.h"

int main(int argc, char **argv){
    dirfile_into_t *info = NULL;
    int ret = EXIT_SUCCESS;

    Real parallel_timer;
    cmd_args_t cmd_args;
    char Mode_str[BUFFSIZE];
    char mode_str[BUFFSIZE];

    /* process command-line arguments */
    command_line_default(&cmd_args);
    command_line_initialize(argc,argv,&cmd_args);

    switch (cmd_args.search_mode){
        case(ANYMODE):
            strcpy(Mode_str,"Directories & Files\n");
            strcpy(mode_str,"Directories/Files");
            break;
        case(DIRMODE):
            strcpy(Mode_str,"Directories Only\n");
            strcpy(mode_str,"Directories");
            break;
        case(FILEMODE):
            strcpy(Mode_str,"Files Only\n");
            strcpy(mode_str,"Files");
            break;
    }

    /* initialize mpi & ctx data */
    ctx_t ctx = {0,1,MPI_COMM_WORLD};
    ret |= mpi_init(argc,argv,&ctx);

    if(cmd_args.depth == 0) {
        /* ==================================== */
        /* search only this directory in serial */
        /* ==================================== */
        if (ctx.rank == MPIROOT) {
            MPITIMER(
                info = file_directory_ls(cmd_args.search_path,
                                         cmd_args.search_mode,
                                         cmd_args.pattern,
                                         cmd_args.output_flag),
                parallel_timer
            );
        }
    } else {
        /* ================================================ */
        /* search first layer of subdirectories in parallel */
        /* ================================================ */
        MPITIMER(
            info = file_directory_ls2_mpi(&ctx,
                                          cmd_args.search_path,
                                          cmd_args.search_mode,
                                          cmd_args.pattern,
                                          cmd_args.output_flag,
                                          cmd_args.inform_all),
            parallel_timer
        );
    }

    /* display results */
    if (ctx.rank == MPIROOT) {
        printf("==================================================\n");
        printf("   LL Parallel Directory & File Search Listing    \n"
               "                Search Depth [ %d ]                \n",cmd_args.depth);
        printf("--------------------------------------------------\n");
        printf("Query Info:\n");
        printf("    Searching Directory:\n");
        printf("        %s",cmd_args.search_path);
        printf("%s\n",(cmd_args.depth)? "/*/*": "/*");
        if(cmd_args.pattern)
            printf("    Substring pattern:\n"
                   "        %s\n",cmd_args.pattern);
        printf("    Search Mode:\n        %s",Mode_str);
        printf("--------------------------------------------------\n");
        printf("Results:\n");
        if (info) {
            printf("    %s Found: %d\n",mode_str,info->nentry);
        } else {
            printf("    %s Found: %d\n",mode_str,0);
        }
        printf("    Search Time (sec): %f\n",parallel_timer);
        printf("==================================================\n");
    }

    /* ============================ */
    /* free memory and shutdown mpi */
    /* ============================ */
    shutdown_dirfile_info(&info);
    ret |= mpi_finalize();

    return ret;
}