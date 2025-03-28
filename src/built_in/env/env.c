/*
** EPITECH PROJECT, 2025
** env
** File description:
** minishell1
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/built_in.h"
#include "shell/env.h"
#include "utils.h"

int sh_builtin_env_bypass(shell_data_t *shell_data, sh_tasker_t *task)
{
    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (task->shell_data != NULL) {
        if (sh_env_print(shell_data->env) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
    } else
        if (sh_env_print(shell_data->env) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
    return sh_builtin_success(shell_data, EXIT_SUCCESS);
}

int sh_builtin_env(shell_data_t *shell_data, sh_tasker_t *task)
{
    sh_bltin_verify_t prerequisites = {0, 0};

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (task->shell_data != NULL) {
        if (sh_env_print(shell_data->env) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
    } else
        if (sh_env_print(shell_data->env) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
    return sh_builtin_success(shell_data, EXIT_SUCCESS);
}
