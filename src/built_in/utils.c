/*
** EPITECH PROJECT, 2025
** utils
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/parser.h"
#include "shell/built_in.h"
#include "shell/config/data.h"

void sh_builtin_perror(char *cmd, char *msg)
{
    if (msg == NULL)
        return;
    if (cmd == NULL)
        my_putstr_fd("(null command)", STDERR);
    else
        my_putstr_fd(cmd, STDERR);
    my_putstr_fd(": ", STDERR);
    my_putstr_fd(msg, STDERR);
    my_putstr_fd(".\n", STDERR);
}

int sh_builtin_verify(sh_prsent_t *chain,
    sh_bltin_verify_t verif)
{
    int len = 0;
    char *command = NULL;

    if (chain == NULL)
        return FUNC_FAILED;
    len = sh_get_prsent_len(chain) - 1;
    command = sh_get_prsent_index(chain, 0);
    if (verif.maximum > -1)
        if (len > verif.maximum) {
            sh_builtin_perror(command, "Too many arguments");
            return FUNC_FAILED;
        }
    if (verif.minimum > -1)
        if (len < verif.minimum) {
            sh_builtin_perror(command, "Too few arguments");
            return FUNC_FAILED;
        }
    return FUNC_SUCCESS;
}

int sh_builtin_success(shell_data_t *shell_data, int exit_code)
{
    if (shell_data == NULL)
        return FUNC_SEMFAIL;
    if (exit_code < 0)
        shell_data->last_excode = 0;
    else
        shell_data->last_excode = exit_code;
    return FUNC_SUCCESS;
}

int sh_builtin_fail(shell_data_t *shell_data, int exit_code)
{
    if (shell_data == NULL)
        return FUNC_FAILED;
    if (exit_code < 0)
        shell_data->last_excode = 1;
    else
        shell_data->last_excode = exit_code;
    return FUNC_FAILED;
}
