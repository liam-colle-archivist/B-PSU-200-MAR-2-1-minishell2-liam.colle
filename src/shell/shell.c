/*
** EPITECH PROJECT, 2025
** shell
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/render.h"
#include "shell/built_in.h"
#include "shell/parser.h"
#include "shell/tasker.h"
#include "utils.h"

static int shell_tty_mode(shell_data_t *shell_data)
{
    int exec_success = FUNC_SUCCESS;

    if (shell_data == NULL)
        return FUNC_FAILED;
    while (sh_parse_entry(shell_data) != FUNC_FAILED
        && exec_success == FUNC_SUCCESS) {
        sh_build_tasker(shell_data);
        exec_success = sh_tasker_execute(shell_data);
        sh_tasker_destroy(shell_data->tasks);
        sh_prsent_destroy(shell_data->command_chain);
        shell_data->command_chain = NULL;
    }
    return FUNC_SUCCESS;
}

int shell(shell_data_t *shell_data)
{
    if (shell_data == NULL)
        return FUNC_FAILED;
    if (isatty(STDIN) == FALSE)
        return shell_tty_mode(shell_data);
    do {
        sh_render_window(shell_data);
        shell_data->last_excode = SH_DATA_DEFAULT_EC;
        if (sh_parse_entry(shell_data) == FUNC_FAILED)
            shell_data->is_active = FALSE;
        sh_build_tasker(shell_data);
        sh_tasker_execute(shell_data);
        sh_tasker_destroy(shell_data->tasks);
        sh_prsent_destroy(shell_data->command_chain);
        shell_data->command_chain = NULL;
    } while (shell_data->is_active);
    return FUNC_SUCCESS;
}

int shell_auto(void)
{
    return FUNC_SUCCESS;
}
