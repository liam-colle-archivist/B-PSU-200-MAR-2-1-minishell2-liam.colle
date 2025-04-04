/*
** EPITECH PROJECT, 2025
** unsetenv
** File description:
** minishell2
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/built_in.h"
#include "my.h"
#include "utils.h"

int sh_builtin_unsetenv(shell_data_t *shell_data, sh_tasker_t *task)
{
    char *value = NULL;
    sh_bltin_verify_t prerequisites = {1, -1};

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    for (int i = 0; i < sh_get_prsent_eltslen(task->parser_entry); i++) {
        value = sh_get_prsent_index(task->parser_entry, i);
        if (value == NULL && i == 0)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
        if (value == NULL)
            return sh_builtin_success(shell_data, EXIT_SUCCESS);
        if (my_chardict_del(&shell_data->env, value,
            my_chardict_find_key, TRUE) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
    }
    return sh_builtin_success(shell_data, EXIT_SUCCESS);
}
