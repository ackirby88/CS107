/**
 * \file   command_line.c
 * \author akirby
 *
 * \brief  Parses command line arguments.
 */

/* header files */
#include "command_line.h"

void command_line_default(cmd_args_t *cmdargs){
    cmdargs->pattern = NULL;
    cmdargs->search_path = NULL;
    cmdargs->search_mode = ANYMODE;
    cmdargs->output_flag = 0;
    cmdargs->inform_all = 0;
    cmdargs->depth = 0;
}

void command_line_usage(char *argv) {
    printf("Usage: %s -i <PATH> [OPTION]...\n",argv);
    printf("Mandatory:\n");
    printf("  -i <PATH>     file path to search\n");
    printf("\n");
    printf("Options:\n");
    printf("  -o            flag to output found entries to file\n");
    printf("  -p <PATTERN>  substring search pattern (no wildcards)\n");
    printf("  -d <#>        search directory depth\n");
    printf("                    0: current directory only\n"
           "                    1: first level sub-directories only\n");
    printf("  -m <MODE>     search mode\n");
    printf("                    0: directories only\n"
           "                    1: files only\n"
           "                    2: files and directories\n");
}

void command_line_initialize(int argc,char **argv,cmd_args_t *cmdargs){
    char input_path_provided;
    int option;
    /* option list:
     *  -h  help function
     *  -i  input search path (required)
     *  -d  directory depth to search
     *  -p  substring search pattern
     *  -o  flag to output results to file
     *  -m  search mode (0=Directories only, 1=Files only, 2=Both)
     *
     */

    input_path_provided = 0;
    while ((option = getopt(argc, argv,"hoi:d:p:m:")) != -1) {
        switch (option) {
            case 'h': /* help function */
                command_line_usage(argv[0]);
                exit(0);
                break;
            case 'i':
                cmdargs->search_path = optarg;
                input_path_provided = 1;
                break;
            case 'd':
                cmdargs->depth = atoi(optarg);
                if(cmdargs->depth < 0 || cmdargs->depth > 1) cmdargs->depth = 1;
                break;
            case 'o':
                cmdargs->output_flag = 1;
                break;
            case 'p':
                cmdargs->pattern = optarg;
                break;
            case 'm':
                cmdargs->search_mode = atoi(optarg);
                if (cmdargs->search_mode != ANYMODE &&
                    cmdargs->search_mode != DIRMODE &&
                    cmdargs->search_mode != FILEMODE) {
                    printf("Search mode %d not found. Defaulting to all.\n",
                            cmdargs->search_mode);
                    cmdargs->search_mode = ANYMODE;
                }
                break;
            default:
                command_line_usage(argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if(!input_path_provided) {
        command_line_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

}