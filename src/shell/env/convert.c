/*
** EPITECH PROJECT, 2025
** convert
** File description:
** minishell2
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

static char *get_env(char_dict_t *chain)
{
    char *temp_buffer = NULL;
    char *result = NULL;

    if (chain == NULL)
        return NULL;
    temp_buffer = my_strcdup(chain->key, "=");
    if (temp_buffer == NULL)
        return NULL;
    result = my_strcdup(temp_buffer, chain->value);
    free(temp_buffer);
    return result;
}

char **sh_env_to_tab(char_dict_t *dict)
{
    int len = 0;
    char **tab = NULL;

    if (dict == NULL)
        return NULL;
    len = my_chardict_len(dict);
    if (len == FUNC_FAILED)
        return NULL;
    tab = malloc(sizeof(char *) * (len + 1));
    if (tab == NULL)
        return NULL;
    tab[len] = NULL;
    for (int i = 0; i < len && dict != NULL; i++) {
        tab[i] = get_env(dict);
        dict = dict->next;
    }
    return tab;
}
