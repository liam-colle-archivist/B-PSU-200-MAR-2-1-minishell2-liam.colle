/*
** EPITECH PROJECT, 2025
** exit
** File description:
** minishell1
*/

#include <stdio.h>
#include "shell/built_in.h"
#include "shell/shell.h"
#include "my.h"
#include "utils.h"

static int exit_with_code(char *argument, sh_tasker_t *task)
{
    if (task == NULL)
        return FUNC_FAILED;
    if (my_str_isnum(argument) == FALSE) {
        sh_builtin_perror(task->program, "Expression Syntax.");
        return FUNC_FAILED;
    }
    task->shell_data->last_excode = my_getnbr(argument);
    return FUNC_SUCCESS;
}

int sh_builtin_exit(shell_data_t *shell_data, sh_tasker_t *task)
{
    sh_bltin_verify_t prerequisites = {0, 1};
    char *argument = NULL;

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    argument = sh_get_prsent_index(task->parser_entry, 1);
    if (argument != NULL)
        if (exit_with_code(argument, task) == FUNC_FAILED)
            return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (task->shell_data != NULL)
        task->shell_data->is_active = FALSE;
    else
        shell_data->is_active = FALSE;
    return sh_builtin_success(shell_data, shell_data->last_excode);
}
