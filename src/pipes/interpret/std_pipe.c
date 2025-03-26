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
#include "shell/exec.h"
#include "utils.h"

static int assign_output(sh_tasker_t *task, int fd, char *argument)
{
    if (fd < 0 || fd > 2 || task == NULL || argument == NULL)
        return FUNC_FAILED;
    if (fd == STDIN) {
        task->pipes.stdin_fd = STDIN;
        task->pipes.stdin_fn = argument;
    }
    if (fd == STDOUT) {
        task->pipes.stdout_fd = STDOUT;
        task->pipes.stdout_fn = argument;
    }
    if (fd == STDERR) {
        task->pipes.stderr_fd = STDERR;
        task->pipes.stderr_fn = argument;
    }
    task->exec_fnc = sh_exec_program_pipe;
    return FUNC_SUCCESS;
}

static int sh_tsk_check_positive_pipe(sh_tasker_t *task, char *shard,
    char *next_argument)
{
    if (task == NULL || shard == NULL || next_argument == NULL)
        return FUNC_FAILED;
    if (my_strcmp(">", shard) == CMP_EXACT) {
        task->pipes.pipe_type = SH_TPIPE_REDIR;
        return assign_output(task, STDOUT, next_argument);
    }
    if (my_strcmp(">>", shard) == CMP_EXACT) {
        task->pipes.pipe_type = SH_TPIPE_REDIR_APPEND;
        return assign_output(task, STDOUT, next_argument);
    }
    return FUNC_FAILED;
}

static int sh_tsk_check_negative_pipe(sh_tasker_t *task, char *shard,
    char *next_argument)
{
    if (task == NULL || shard == NULL || next_argument == NULL)
        return FUNC_FAILED;
    if (my_strcmp("<", shard) == CMP_EXACT) {
        task->pipes.pipe_type = SH_TPIPE_IREDIR;
        return assign_output(task, STDOUT, next_argument);
    }
    if (my_strcmp("<<", shard) == CMP_EXACT) {
        task->pipes.pipe_type = SH_TPIPE_IREDIR_APPEND;
        return assign_output(task, STDOUT, next_argument);
    }
    return FUNC_FAILED;
}

int sh_tsk_intprt_std_pipe(sh_tasker_t *task, char *shard,
    char *next_argument)
{
    if (task == NULL || shard == NULL || next_argument == NULL)
        return FUNC_FAILED;
    if (shard[0] == '0' || shard[0] == '1' || shard[0] == '2') {
        if (shard[1] == '>')
            return sh_tsk_check_positive_pipe(task, &shard[1], next_argument);
        else
            return sh_tsk_check_negative_pipe(task, &shard[1], next_argument);
    }
    if (shard[0] == '>')
        return sh_tsk_check_positive_pipe(task, shard, next_argument);
    return sh_tsk_check_negative_pipe(task, shard, next_argument);
}
