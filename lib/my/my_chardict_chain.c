/*
** EPITECH PROJECT, 2025
** my_chardict_free
** File description:
** libmy
*/

#include <stdlib.h>
#include "utils.h"

int my_chardict_chain(char_dict_t **dict, char_dict_t *chain)
{
    char_dict_t *curr_dict = NULL;

    if (dict == NULL || chain == NULL)
        return FUNC_FAILED;
    if (*dict == NULL) {
        *dict = chain;
        return FUNC_SUCCESS;
    }
    curr_dict = *dict;
    for (; curr_dict->next != NULL; curr_dict = curr_dict->next);
    curr_dict->next = chain;
    return FUNC_SUCCESS;
}
