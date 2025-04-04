/*
** EPITECH PROJECT, 2025
** main
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "argparser.h"
#include "utils.h"

int main(int argc, char **argv, char **env)
{
    int last_exit_code = EXIT_SUCCESS;
    shell_data_t *shell_data = init_shell_conf(env, NULL);
    arg_chain_t *start_args = args_getfromtab(argc, argv);

    free_arg_chain(start_args);
    if (shell_data == NULL) {
        my_putstr_fd("mysh (PANIC): Cannot create shell_data, panicing!.\n",
            STDERR);
        return EXIT_FAILURE_84;
    }
    if (shell(shell_data) == FUNC_FAILED) {
        last_exit_code = shell_data->last_excode;
        sh_data_purge(shell_data);
        return last_exit_code;
    }
    last_exit_code = shell_data->last_excode;
    sh_data_purge(shell_data);
    return last_exit_code;
}
