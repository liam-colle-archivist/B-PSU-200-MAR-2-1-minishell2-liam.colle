/*
** EPITECH PROJECT, 2025
** init
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"
#include "shell/config/types.h"
#include "utils.h"

static int configure_options(shell_data_t *shell_data,
    sh_st_options_t *options)
{
    if (shell_data == NULL || options == NULL)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}

shell_data_t *init_shell_conf(char **env, sh_st_options_t *options)
{
    shell_data_t *shell_data = NULL;
    char_dict_t *env_dict = NULL;

    if (env == NULL)
        return NULL;
    env_dict = sh_env_load(env);
    shell_data = sh_data_init(env_dict);
    if (options != NULL)
        if (configure_options(shell_data, options) == FUNC_FAILED)
            my_putstr_fd("mysh: Failed to load start options\n", STDERR);
    return shell_data;
}
