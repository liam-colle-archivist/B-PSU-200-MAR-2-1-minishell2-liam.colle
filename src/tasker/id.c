/*
** EPITECH PROJECT, 2025
** id
** File description:
** minishell1
*/

#include <stdio.h>
#include "shell/parser.h"
#include "my.h"

sh_tasker_type_t sh_tasker_identify_type(sh_prsent_t *args)
{
    const char *builtins[] = {"cd", "clear", "env", "exit", "return",
        "setenv", "unsetenv", NULL};

    if (args == NULL)
        return SH_TASKER_UNKNOWN;
    if (my_isin(args->entry, builtins) == TRUE)
        return SH_TASKER_BUILTIN;
    return SH_TASKER_COMMAND;
}
