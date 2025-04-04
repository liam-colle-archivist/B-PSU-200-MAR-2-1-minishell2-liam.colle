/*
** EPITECH PROJECT, 2025
** my_chardict_free
** File description:
** libmy
*/

#include <stdlib.h>
#include "utils.h"

void my_chardict_free(char_dict_t *dict)
{
    char_dict_t *next_dict = NULL;

    if (dict == NULL)
        return;
    while (dict != NULL) {
        next_dict = dict->next;
        free(dict);
        dict = next_dict;
    }
}

void my_chardict_free_ext(char_dict_t *dict)
{
    char_dict_t *next_dict = NULL;

    if (dict == NULL)
        return;
    while (dict != NULL) {
        next_dict = dict->next;
        free(dict->key);
        free(dict->value);
        free(dict);
        dict = next_dict;
    }
}
