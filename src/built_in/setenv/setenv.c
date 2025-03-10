/*
** EPITECH PROJECT, 2025
** setenv
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "shell/env.h"
#include "shell/built_in.h"
#include "my.h"
#include "utils.h"

static bool_t verify_validity(sh_tasker_t *task)
{
    sh_bltin_verify_t prerequisites = {0, 2};
    char *key = NULL;

    if (task == NULL)
        return FALSE;
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return FALSE;
    key = sh_get_prsent_index(task->parser_entry, 1);
    if (key == NULL)
        return FALSE;
    if (is_alpha(key[0]) == FALSE) {
        sh_builtin_perror("setenv", "Variable name must begin with a letter");
        return FALSE;
    }
    for (int i = 0; key[i] != '\0'; i++)
        if (is_alphanum(key[i]) == FALSE) {
            sh_builtin_perror("setenv", SETENV_AFAIL);
                return FALSE;
        }
    return TRUE;
}

int sh_builtin_setenv(shell_data_t *shell_data, sh_tasker_t *task)
{
    char *key = NULL;
    char *value = NULL;

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (verify_validity(task) == FALSE)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    key = my_strdup(sh_get_prsent_index(task->parser_entry, 1));
    value = my_strdup(sh_get_prsent_index(task->parser_entry, 2));
    if (key == NULL) {
        if (sh_env_print(shell_data->env) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
        return sh_builtin_fail(shell_data, EXIT_SUCCESS);
    }
    value = value != NULL ? value : my_strdup("");
    if (my_chardict_set(shell_data->env, key, value, TRUE) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    return sh_builtin_success(shell_data, EXIT_SUCCESS);
}
