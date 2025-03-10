/*
** EPITECH PROJECT, 2025
** get
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell/parser.h"
#include "getline.h"
#include "my.h"
#include "utils.h"

int sh_get_prsent_eltslen(sh_prsent_t *chain)
{
    int total_len = 0;

    for (; chain != NULL; chain = chain->next) {
        if (chain->type == SH_PARSER_PIPE)
            return total_len;
        if (my_strcmp(chain->entry, "") == CMP_EXACT)
            continue;
        total_len += my_strlen(chain->entry);
    }
    return total_len;
}

int sh_get_prsent_len(sh_prsent_t *chain)
{
    int total_len = 0;

    for (; chain != NULL; chain = chain->next) {
        if (chain->type == SH_PARSER_PIPE)
            return total_len;
        if (my_strcmp(chain->entry, "") == CMP_EXACT)
            continue;
        total_len += 1;
    }
    return total_len;
}

char *sh_get_prsent_index(sh_prsent_t *chain, int index)
{
    int curr_index = 0;

    for (; chain != NULL; chain = chain->next) {
        if (my_strcmp(chain->entry, "") == CMP_EXACT)
            continue;
        if (curr_index == index && chain->type != SH_PARSER_PIPE)
            return chain->entry;
        if (chain->type == SH_PARSER_PIPE)
            return NULL;
        curr_index++;
    }
    return NULL;
}

char *sh_get_entry(FILE *file)
{
    char *line = NULL;
    char *ret_line = NULL;
    char *newline = NULL;
    size_t size = 0;

    if (getline(&line, &size, file) == FUNC_FAILED) {
        free(line);
        return NULL;
    }
    newline = my_strstr(line, "\n");
    if (newline != NULL)
        *newline = '\0';
    ret_line = my_strdup(line);
    free(line);
    return ret_line;
}
