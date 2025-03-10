/*
** EPITECH PROJECT, 2025
** cd_nav_usrdir
** File description:
** minishell1
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"

char *sh_cd_nav_usrdir(shell_data_t *shell_data)
{
    char *home_path = NULL;

    if (shell_data == NULL)
        return NULL;
    home_path = sh_env_get(shell_data->env, "HOME");
    if (home_path == NULL) {
        if (shell_data->user_data == NULL)
            return my_strdup("/home");
        else
            return my_strdup(shell_data->user_data->user_homedir);
    }
    return my_strdup(home_path);
}
