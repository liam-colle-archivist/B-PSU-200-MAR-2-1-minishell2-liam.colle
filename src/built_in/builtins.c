/*
** EPITECH PROJECT, 2025
** builtins
** File description:
** minishell2
*/

#include "shell/config/built_in.h"

sh_builtin_conf_t sh_builtins[] = {
    {SH_BLTN_CLS},
    {SH_BLTN_EXIT},
    {SH_BLTN_CD},
    {SH_BLTN_ENV},
    {SH_BLTN_SETENV},
    {SH_BLTN_UNSETENV},
    {SH_BLTN_RETURN},
    {SH_BLTN_BLANK}
};
