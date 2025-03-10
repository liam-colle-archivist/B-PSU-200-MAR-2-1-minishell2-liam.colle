/*
** EPITECH PROJECT, 2025
** my_chardict_free
** File description:
** libmy
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

static int replace_key(char_dict_t *dict, char *key,
    char *value, bool_t do_free)
{
    if (dict == NULL || key == NULL || value == NULL)
        return FUNC_FAILED;
    if (my_strcmp(dict->key, key) == CMP_EXACT) {
        if (do_free == TRUE)
            free(dict->value);
        dict->value = value;
        return FUNC_SUCCESS;
    }
    return FUNC_SEMFAIL;
}

int my_chardict_set(char_dict_t *dict, char *key, char *value, bool_t do_free)
{
    char_dict_t *last_dict = NULL;
    char_dict_t *new_dict = NULL;

    if (dict == NULL || key == NULL)
        return FUNC_FAILED;
    for (; dict != NULL; dict = dict->next) {
        last_dict = dict;
        if (replace_key(dict, key, value, do_free) == FUNC_SUCCESS)
            return FUNC_SUCCESS;
    }
    new_dict = my_chardict_create(my_strdup(key), value);
    last_dict->next = new_dict;
    return FUNC_SUCCESS;
}
