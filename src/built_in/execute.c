/*
** EPITECH PROJECT, 2025
** execute
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/built_in.h"
#include "shell/config/built_in.h"

int (*sh_get_builtin_exec(sh_prsent_t *parser_entry))(shell_data_t *,
    sh_tasker_t *)
{
    char *entry = NULL;

    if (parser_entry == NULL)
        return NULL;
    if (parser_entry->entry == NULL)
        return NULL;
    entry = parser_entry->entry;
    for (int i = 0; sh_builtins[i].command != NULL; i++)
        if (my_strcmp(entry, sh_builtins[i].command) == CMP_EXACT)
            return sh_builtins[i].builtin_f;
    return NULL;
}
