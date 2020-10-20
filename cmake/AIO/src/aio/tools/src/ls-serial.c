/** Main for serial ls function in AIO Tools.
 * \File    ls-serial.c
 * \Author  akirby
 *
 * \brief   Main function for serial ls function in AIO tools module.
 */

/* header files */
#include "ls-serial.h"

int main(int argc, char **argv){
    dirfile_into_t *info = NULL;
    int ret = EXIT_SUCCESS;

    Real serial_timer;
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

    if(cmd_args.depth == 0) {
        /* ========================== */
        /* search only this directory */
        /* ========================== */
        TIMER(
            info = file_directory_ls(cmd_args.search_path,
                                     cmd_args.search_mode,
                                     cmd_args.pattern,
                                     cmd_args.output_flag),
            serial_timer
        );
    } else {
        /* ==================================== */
        /* search first layer of subdirectories */
        /* ==================================== */
        TIMER(
            info = file_directory_ls2(cmd_args.search_path,
                                      cmd_args.search_mode,
                                      cmd_args.pattern,
                                      cmd_args.output_flag),
            serial_timer
        );
    }

    /* display results */
    printf("==================================================\n");
    printf("   LL Serial Directory & File Search Listing    \n"
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
    printf("    Search Time (sec): %f\n",serial_timer);
    printf("==================================================\n");

    /* =========== */
    /* free memory */
    /* =========== */
    shutdown_dirfile_info(&info);
    return ret;
}