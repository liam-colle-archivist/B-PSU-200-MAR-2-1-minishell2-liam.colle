/*
** EPITECH PROJECT, 2025
** cd_nav_oldpwd
** File description:
** minishell1
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/env.h"

char *sh_cd_nav_oldpwd(shell_data_t *shell_data)
{
    char *old_dir = NULL;

    if (shell_data == NULL)
        return NULL;
    old_dir = sh_env_get(shell_data->env, "OLDPWD");
    if (old_dir == NULL)
        return my_strdup(shell_data->pwd);
    return my_strdup(old_dir);
}
