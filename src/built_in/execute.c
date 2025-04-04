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

static int execbltin(shell_data_t *shell_data)
{
    char *entry = NULL;
    sh_builtin_conf_t config[] = {{SH_BLTN_CLS}, {SH_BLTN_EXIT}, {SH_BLTN_CD},
        {SH_BLTN_ENV}, {SH_BLTN_SETENV}, {SH_BLTN_UNSETENV}, {SH_BLTN_RETURN},
        {SH_BLTN_BLANK}};

    if (shell_data == NULL)
        return FUNC_FAILED;
    if (shell_data->command_chain == NULL)
        return FUNC_FAILED;
    entry = shell_data->command_chain->entry;
    for (int i = 0; config[i].command != NULL; i++) {
        if (my_strcmp(entry, config[i].command) == CMP_EXACT)
            return config[i].builtin_f(shell_data, NULL);
    }
    return FUNC_SUCCESS;
}

sh_blttin_exe_st_t sh_execute_builtin(shell_data_t *shell_data)
{
    if (shell_data == NULL)
        return SH_BLTIN_EXE_FAILURE;
    return execbltin(shell_data) == FUNC_SUCCESS ? SH_BLTIN_EXE_SUCCESS
        : SH_BLTIN_EXE_FAILURE;
    return SH_BLTIN_EXE_NOTBUILTIN;
}

int (*sh_get_builtin_exec(sh_prsent_t *parser_entry))(shell_data_t *,
    sh_tasker_t *)
{
    char *entry = NULL;
    sh_builtin_conf_t config[] = {{SH_BLTN_CLS}, {SH_BLTN_EXIT}, {SH_BLTN_CD},
        {SH_BLTN_ENV}, {SH_BLTN_SETENV}, {SH_BLTN_UNSETENV}, {SH_BLTN_RETURN},
        {SH_BLTN_BLANK}};

    if (parser_entry == NULL)
        return NULL;
    if (parser_entry->entry == NULL)
        return NULL;
    entry = parser_entry->entry;
    for (int i = 0; config[i].command != NULL; i++) {
        if (my_strcmp(entry, config[i].command) == CMP_EXACT)
            return config[i].builtin_f;
    }
    return NULL;
}
