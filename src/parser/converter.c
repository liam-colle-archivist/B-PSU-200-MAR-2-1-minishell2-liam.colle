/*
** EPITECH PROJECT, 2025
** converter
** File description:
** minishell2
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell/parser.h"
#include "utils.h"

static char *convert_to_char_ptr(char *result, sh_prsent_t *chain)
{
    int index = 0;

    if (result == NULL || chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next) {
        if (sh_parser_is_anypipe(chain) == TRUE)
            return result;
        my_strcat(&result[index], chain->entry);
        index += my_strlen(chain->entry);
    }
    return result;
}

static char **convert_to_char_tab(char **result, sh_prsent_t *chain)
{
    int index = 0;

    if (result == NULL || chain == NULL)
        return NULL;
    for (; chain != NULL; chain = chain->next) {
        if (sh_parser_is_anypipe(chain) == TRUE)
            return result;
        if (my_strcmp(chain->entry, "") == CMP_EXACT)
            continue;
        result[index] = my_strdup(chain->entry);
        index++;
    }
    return result;
}

char *sh_prsent_to_char_ptr(sh_prsent_t *chain)
{
    char *result = NULL;
    int chain_elts_len = sh_get_prsent_eltslen(chain);
    int chain_gaps = sh_get_prsent_len(chain) - 1;

    if (chain == NULL || chain_elts_len <= 0 || chain_gaps < 0)
        return NULL;
    result = malloc(sizeof(char) * (chain_elts_len + chain_gaps + 1));
    if (result == NULL)
        return NULL;
    result[chain_elts_len + chain_gaps] = '\0';
    return convert_to_char_ptr(result, chain);
}

char **sh_prsent_to_char_tab(sh_prsent_t *chain)
{
    char **result = NULL;
    int chain_len = sh_get_prsent_len(chain);

    if (chain == NULL || chain_len <= 0)
        return NULL;
    result = malloc(sizeof(char *) * (chain_len + 1));
    if (result == NULL)
        return NULL;
    result[chain_len] = NULL;
    return convert_to_char_tab(result, chain);
}
