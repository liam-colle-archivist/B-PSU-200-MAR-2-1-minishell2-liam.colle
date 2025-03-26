/*
** EPITECH PROJECT, 2025
** interpret
** File description:
** Minishell2
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/parser.h"
#include "shell/pipes.h"
#include "utils.h"

int sh_pipes_interpret(sh_tasker_t *task, char *shard,
    char *next_argument)
{
    if (task == NULL || shard == NULL || next_argument == NULL)
        return FUNC_FAILED;
    if (sh_pipe_is_redirect(shard) == TRUE)
        if (sh_pipe_info[SH_PARSER_PIPE].tsk_interpret_f != NULL)
            return sh_pipe_info[SH_PARSER_PIPE].tsk_interpret_f(task,
                shard, next_argument);
    if (sh_pipe_is_stop(shard) == TRUE)
        if (sh_pipe_info[SH_PARSER_STOP_PIPE].tsk_interpret_f != NULL)
            return sh_pipe_info[SH_PARSER_STOP_PIPE].tsk_interpret_f(task,
                shard, next_argument);
    return FUNC_SUCCESS;
}
