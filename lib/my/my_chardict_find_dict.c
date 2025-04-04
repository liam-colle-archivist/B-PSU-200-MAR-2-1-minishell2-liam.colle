/*
** EPITECH PROJECT, 2025
** my_chardict_find
** File description:
** libmy
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

char_dict_t *my_chardict_find_dict(char_dict_t *dict, void *value,
    int (*search_func)(void *, char_dict_t *))
{
    if (dict == NULL || value == NULL || search_func == NULL)
        return NULL;
    for (; dict != NULL; dict = dict->next) {
        if (search_func(value, dict) == TRUE)
            return dict;
    }
    return NULL;
}
