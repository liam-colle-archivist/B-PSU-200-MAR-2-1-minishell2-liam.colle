/*
** EPITECH PROJECT, 2025
** data
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell/shell.h"
#include "shell/env.h"
#include "shell/parser.h"
#include "my.h"

shell_usr_data_t *sh_usrdata_init(char_dict_t *env)
{
    shell_usr_data_t *shell_usrdata = NULL;

    shell_usrdata = malloc(sizeof(shell_usr_data_t));
    if (shell_usrdata == NULL)
        return NULL;
    shell_usrdata->user = my_strdup(sh_env_get(env, "USER"));
    shell_usrdata->user_homedir = my_strdup(sh_env_get(env, "HOME"));
    shell_usrdata->hostname = my_strdup(sh_env_get(env, "HOSTNAME"));
    shell_usrdata->path = NULL;
    return shell_usrdata;
}
