/*
** EPITECH PROJECT, 2025
** render
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "my_printf.h"
#include "shell/shell.h"
#include "utils.h"

static int update_datas(shell_data_t *shell_data)
{
    char_dict_t *buffer = NULL;

    if (shell_data == NULL)
        return FUNC_FAILED;
    buffer = my_chardict_find_dict(shell_data->env,
        "PWD", my_chardict_find_key);
    shell_data->pwd = buffer != NULL ? buffer->value : NULL;
    buffer = my_chardict_find_dict(shell_data->env,
        "PWD", my_chardict_find_key);
    shell_data->old_pwd = buffer != NULL ? buffer->value : NULL;
    return FUNC_SUCCESS;
}

int sh_render_window(shell_data_t *shell_data)
{
    if (shell_data == NULL)
        return FUNC_FAILED;
    if (isatty(STDIN) == FALSE)
        return FUNC_FAILED;
    update_datas(shell_data);
    my_printf("[%s@%s", shell_data->user_data->user,
        shell_data->user_data->hostname, shell_data->pwd);
    if (shell_data->last_excode > 0)
        my_printf(" (%s%d)", shell_data->last_excode == 0 ? "✔ " : "✘ ",
            shell_data->last_excode);
    my_printf(" %s]$ ", shell_data->pwd);
    return FUNC_SUCCESS;
}
