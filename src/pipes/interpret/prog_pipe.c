/*
** EPITECH PROJECT, 2025
** prog_pipe
** File description:
** Minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/pipes.h"
#include "shell/parser.h"
#include "shell/exec.h"
#include "utils.h"

int sh_tsk_intprt_prog_pipe(sh_tasker_t *task, char *shard,
    char *next_argument)
{
    if (task == NULL || shard == NULL || next_argument == NULL)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}
