/*
** EPITECH PROJECT, 2025
** cd_nav_usrdirext
** File description:
** minishell1
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/env.h"

static char *cat_and_dup(char *homedir, char *arg)
{
    if (homedir == NULL || arg == NULL)
        return NULL;
    if (my_strlen(arg) < 3)
        return my_strdup(homedir);
    return my_strcdup(homedir, &arg[1]);
}

char *sh_cd_nav_usrdirext(shell_data_t *shell_data)
{
    char *home_path = NULL;
    char *arg = NULL;

    if (shell_data == NULL)
        return NULL;
    arg = sh_get_prsent_index(shell_data->command_chain, 1);
    if (arg == NULL)
        return NULL;
    home_path = sh_env_get(shell_data->env, "HOME");
    if (home_path == NULL) {
        if (shell_data->user_data->user_homedir == NULL)
            return my_strdup("/home");
        else
            return cat_and_dup(shell_data->user_data->user_homedir, arg);
    }
    return cat_and_dup(home_path, arg);
}
