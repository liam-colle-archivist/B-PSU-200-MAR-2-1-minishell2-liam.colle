/*
** EPITECH PROJECT, 2025
** config
** File description:
** minishell1
*/

#include <stdlib.h>
#include "my.h"
#include "shell/config/built_in.h"

sh_builtin_conf_t **sh_return_builtin_fptr(void)
{
    sh_builtin_conf_t exit = {SH_BLTN_EXIT};
    sh_builtin_conf_t cd = {SH_BLTN_CD};
    sh_builtin_conf_t env = {SH_BLTN_ENV};
    sh_builtin_conf_t setenv = {SH_BLTN_SETENV};
    sh_builtin_conf_t unsetenv = {SH_BLTN_UNSETENV};
    sh_builtin_conf_t **builtins = malloc(sizeof(sh_builtin_conf_t *) * 6);

    builtins[0] = &exit;
    builtins[1] = &cd;
    builtins[2] = &env;
    builtins[3] = &setenv;
    builtins[4] = &unsetenv;
    builtins[5] = NULL;
    return builtins;
}
