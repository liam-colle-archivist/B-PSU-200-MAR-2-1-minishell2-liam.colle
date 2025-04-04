/*
** EPITECH PROJECT, 2025
** built-in (Config)
** File description:
** minishell2
*/

#include <stdio.h>
#include "data.h"
#include "../built_in.h"

#ifndef SH_CONFIG_BUILTIN_H
    #define SH_CONFIG_BUILTIN_H

typedef struct {
    char *command;
    int (*builtin_f)(shell_data_t *, sh_tasker_t *);
} sh_builtin_conf_t;

    #define SH_BUILTINS_LIST "cd", "env", "setenv", "unsetenv", NULL

    #define SH_BLTN_BLANK NULL, NULL
    #define SH_BLTN_CLS "clear", sh_builtin_clear
    #define SH_BLTN_RETURN "return", sh_builtin_return
    #define SH_BLTN_EXIT "exit", sh_builtin_exit
    #define SH_BLTN_CD "cd", sh_builtin_cd
    #define SH_BLTN_ENV "env", sh_builtin_env
    #define SH_BLTN_SETENV "setenv", sh_builtin_setenv
    #define SH_BLTN_UNSETENV "unsetenv", sh_builtin_unsetenv

// Deprecated. Causes 'unknown' instructions
sh_builtin_conf_t **sh_return_builtin_fptr(void);

#endif
