/*
** EPITECH PROJECT, 2025
** clear
** File description:
** minishell2
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/built_in.h"
#include "my.h"
#include "utils.h"

int sh_builtin_clear(shell_data_t *shell_data, sh_tasker_t *task)
{
    sh_bltin_verify_t prerequisites = {0, 0};

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    my_putstr("\x1B[2J\x1B[H");
    if (task->shell_data != NULL)
        return sh_builtin_success(task->shell_data, EXIT_SUCCESS);
    return sh_builtin_success(shell_data, EXIT_SUCCESS);
}
