/*
** EPITECH PROJECT, 2025
** pipes
** File description:
** Minishell2
*/

#include "shell/shell.h"
#include "shell/pipes.h"
#include "utils.h"

const sh_pipe_info_t sh_pipe_info[] = {
    {SH_PARSER_PIPE, (char *[]) {">", ">>", "<", "<<", NULL},
        sh_tsk_intprt_std_pipe},
    {SH_PARSER_PROG_PIPE, (char *[]) {"|", "||"}, NULL},
    {SH_PARSER_STOP_PIPE, (char *[]) {";", "&", "&&", NULL},
        sh_tsk_intprt_stop_pipe},
    {SH_PARSER_UNKNOWN, NULL, NULL}
};
