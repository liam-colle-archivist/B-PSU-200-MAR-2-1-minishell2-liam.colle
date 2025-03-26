/*
** EPITECH PROJECT, 2025
** sh_is
** File description:
** Minishell2
*/

#include <stdio.h>
#include "shell/shell.h"
#include "shell/parser.h"
#include "utils.h"

bool_t sh_parser_is_spipe(sh_prsent_t *entry)
{
    if (entry == NULL)
        return FALSE;
    if (entry->type == SH_PARSER_STOP_PIPE)
        return TRUE;
    return FALSE;
}

bool_t sh_parser_is_anypipe(sh_prsent_t *entry)
{
    if (entry == NULL)
        return FALSE;
    if (entry->type == SH_PARSER_PIPE)
        return TRUE;
    if (entry->type == SH_PARSER_PROG_PIPE)
        return TRUE;
    if (entry->type == SH_PARSER_STOP_PIPE)
        return TRUE;
    return FALSE;
}
