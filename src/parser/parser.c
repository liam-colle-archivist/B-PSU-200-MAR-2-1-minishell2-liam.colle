/*
** EPITECH PROJECT, 2025
** parser
** File description:
** minishell
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/parser.h"

static char *get_final_quote(char *line, char **last_stop, int i)
{
    if (line == NULL || last_stop == NULL || i < 0)
        return NULL;
    *last_stop = &line[i + 1];
    if (line[i + 1] == ' ' || line[i + 1] == '\t')
        *last_stop = &line[i + 2];
    return my_strptrdup(&line[1], &line[i]);
}

static char *get_doublequote_shard(char *line, char **last_stop)
{
    if (line == NULL || last_stop == NULL)
        return NULL;
    if (line[0] == '\0')
        return NULL;
    for (int i = 1; line[i] != '\0'; i++) {
        if (line[i] == '"') {
            return get_final_quote(line, last_stop, i);
        }
        if (line[i] == '\0')
            return my_strdup(line);
    }
    *last_stop = "";
    return my_strdup(line);
}

static char *get_shard(char *line, char **last_stop)
{
    if (line == NULL || last_stop == NULL)
        return NULL;
    if (line[0] == '\0')
        return NULL;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\t') {
            *last_stop = &line[i + 1];
            return my_strptrdup(line, &line[i]);
        }
        if (line[i] == '"')
            return get_doublequote_shard(line, last_stop);
    }
    *last_stop = "";
    return my_strdup(line);
}

static bool_t is_supported_pipe(const char *shard)
{
    const char *supported_pipes[] = {";", ">", ">>", "<",
        "<<", "|", "||", NULL};

    if (shard == NULL)
        return FALSE;
    return my_isin(shard, supported_pipes);
}

static int get_arguments(sh_prsent_t **chain, char *line)
{
    char *shard = NULL;
    char *last_stop = line;
    sh_prsent_t *curr_chain = NULL;
    bool_t argument_parser_run = TRUE;

    if (chain == NULL || line == NULL)
        return FUNC_FAILED;
    while (argument_parser_run) {
        shard = get_shard(last_stop, &last_stop);
        if (shard == NULL)
            return (*chain != NULL) ? FUNC_SUCCESS : FUNC_FAILED;
        if (is_supported_pipe(shard) == TRUE)
            curr_chain = sh_prsent_create(shard, SH_PARSER_PIPE);
        else
            curr_chain = sh_prsent_create(shard, SH_PARSER_COMMAND);
        if (sh_prsent_chain(chain, curr_chain) == FUNC_FAILED)
            return FUNC_FAILED;
        shard = last_stop;
    }
    return FUNC_FAILED;
}

int sh_parse_entry(shell_data_t *shell_data)
{
    char *line = NULL;

    if (shell_data == NULL)
        return FUNC_FAILED;
    line = sh_get_entry(stdin);
    if (line == NULL)
        return FUNC_FAILED;
    if (line[0] == '\0') {
        free(line);
        shell_data->last_excode = EXIT_SUCCESS;
        return FUNC_SEMFAIL;
    }
    if (get_arguments(&shell_data->command_chain, line) == FUNC_FAILED)
        return FUNC_FAILED;
    free(line);
    return FUNC_SUCCESS;
}
