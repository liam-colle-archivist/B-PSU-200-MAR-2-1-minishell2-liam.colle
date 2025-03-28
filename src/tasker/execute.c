/*
** EPITECH PROJECT, 2025
** execute
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "statutils.h"
#include "shell/shell.h"
#include "shell/env.h"
#include "shell/tasker.h"

static char *is_program_in_path(char *path, char *executable)
{
    char *buffer = NULL;
    char *result = NULL;

    if (path == NULL || executable == NULL)
        return NULL;
    buffer = my_strcdup(path, "/");
    result = my_strcdup(buffer, executable);
    free(buffer);
    if (stat_get_size(result) == FUNC_FAILED) {
        free(result);
        return NULL;
    }
    return result;
}

static int replace_arguments(char *new_arg, sh_tasker_t *task)
{
    if (new_arg == NULL || task == NULL) {
        free(new_arg);
        return FUNC_FAILED;
    }
    if (task->program != NULL) {
        free(task->program);
        task->program = my_strdup(new_arg);
    }
    free(new_arg);
    return FUNC_SUCCESS;
}

int sh_is_apart_of_path(char *path, sh_tasker_t *task)
{
    char *path_shard = NULL;
    char *buffer = NULL;

    if (task == NULL || path == NULL)
        return FUNC_FAILED;
    if (task->type == SH_TASKER_BUILTIN)
        return FUNC_SEMFAIL;
    path_shard = strtok(path, ":");
    while (path_shard != NULL) {
        buffer = is_program_in_path(path_shard, task->program);
        if (buffer != NULL)
            return replace_arguments(buffer, task);
        free(buffer);
        path_shard = strtok(NULL, ":");
        buffer = NULL;
    }
    return FUNC_SUCCESS;
}

int sh_tasker_execute(shell_data_t *shell_data)
{
    char *path_buffer = NULL;
    sh_tasker_t *curr_task = NULL;

    if (shell_data == NULL)
        return FUNC_FAILED;
    curr_task = shell_data->tasks;
    for (; curr_task != NULL; curr_task = curr_task->next) {
        if (!SH_EXEC_MLAX(curr_task) && !SH_EXEC_CCNT(shell_data))
            return FUNC_FAILED;
        path_buffer = my_strdup(sh_env_get(shell_data->env, "PATH"));
        sh_is_apart_of_path(path_buffer, curr_task);
        free(path_buffer);
        if (curr_task->exec_fnc == NULL)
            return FUNC_FAILED;
        if (curr_task->exec_fnc(shell_data, curr_task) == FUNC_FAILED)
            return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}
