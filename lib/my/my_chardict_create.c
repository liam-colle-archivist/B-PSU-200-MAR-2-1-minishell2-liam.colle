/*
** EPITECH PROJECT, 2025
** my_chardict_free
** File description:
** libmy
*/

#include <stdlib.h>
#include "utils.h"

char_dict_t *my_chardict_create(char *key, char *value)
{
    char_dict_t *dict = NULL;

    if (key == NULL || value == NULL)
        return NULL;
    dict = malloc(sizeof(char_dict_t));
    if (dict == NULL)
        return NULL;
    dict->key = key;
    dict->value = value;
    dict->next = NULL;
    return dict;
}
