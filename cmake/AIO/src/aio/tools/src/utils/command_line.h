/**
 * \file   command_line.h
 * \author akirby
 */

#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H

/* header files */
#include "precision_types.h"

/* system header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char *search_path;
    char *pattern;
    char output_flag;
    char search_mode;
    char inform_all;
    char depth;
} cmd_args_t;

void command_line_default(cmd_args_t *cmdargs);

void command_line_initialize(int argc,char **argv,cmd_args_t *cmdargs);

#ifdef __cplusplus
}
#endif
#endif /* COMMAND_LINE_H */