/*
** EPITECH PROJECT, 2025
** clear
** File description:
** minishell1
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/built_in.h"
#include "my.h"
#include "utils.h"

int sh_builtin_return(shell_data_t *shell_data, sh_tasker_t *task)
{
    char *value = NULL;
    sh_bltin_verify_t prerequisites = {1, 1};

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    value = sh_get_prsent_index(task->parser_entry, 1);
    if (value == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (my_str_isnum(value) == FALSE)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    return sh_builtin_success(shell_data, my_getnbr(value));
}
