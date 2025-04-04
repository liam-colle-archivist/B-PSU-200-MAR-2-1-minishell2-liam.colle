/*
** EPITECH PROJECT, 2025
** my_chardict_find
** File description:
** libmy
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

int my_chardict_find(char_dict_t *dict, void *value,
    int (*search_func)(void *, char_dict_t *))
{
    if (dict == NULL || value == NULL || search_func == NULL)
        return FUNC_FAILED;
    for (; dict != NULL; dict = dict->next) {
        if (search_func(value, dict) == TRUE)
            return TRUE;
    }
    return FALSE;
}

int my_chardict_find_key(void *key, char_dict_t *dict)
{
    char *key_conv = NULL;

    if (key == NULL || dict == NULL)
        return FUNC_FAILED;
    key_conv = (char *) key;
    if (my_strcmp(dict->key, key_conv) == CMP_EXACT)
        return TRUE;
    return FALSE;
}
