/*
** EPITECH PROJECT, 2025
** std_pipe
** File description:
** Minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/pipes.h"
#include "shell/parser.h"
#include "utils.h"

static void consume_argument(char *next_argument)
{
    if (next_argument == NULL)
        return;
}

int sh_tsk_intprt_stop_pipe(sh_tasker_t *task, char *shard,
    char *next_argument)
{
    if (task == NULL || shard == NULL)
        return FUNC_FAILED;
    consume_argument(next_argument);
    if (my_strcmp(";", shard) == CMP_EXACT)
        task->pipes.exec_type = SH_EXEC_LAX;
    if (my_strcmp("&", shard) == CMP_EXACT
        || my_strcmp("&", shard) == CMP_EXACT)
        task->pipes.exec_type = SH_EXEC_STRICT;
    return FUNC_SUCCESS;
}
