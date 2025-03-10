/*
** EPITECH PROJECT, 2025
** my_chardict_free
** File description:
** libmy
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

static int patch_chardict(char_dict_t **start, char_dict_t *dict,
    char_dict_t *prev_dict, bool_t do_free)
{
    if (start == NULL || dict == NULL || prev_dict == NULL)
        return FUNC_FAILED;
    if (dict == *start && *start != NULL)
        *start = (*start)->next;
    if (prev_dict != dict)
        prev_dict->next = dict->next;
    if (do_free) {
        free(dict->key);
        free(dict->value);
    }
    free(dict);
    return FUNC_SUCCESS;
}

int my_chardict_del(char_dict_t **dict, void *value,
    int (*search_func)(void *, char_dict_t *), bool_t do_free)
{
    char_dict_t *curr_dict = NULL;
    char_dict_t *old_dict = NULL;

    if (dict == NULL)
        return FUNC_FAILED;
    if (*dict == NULL)
        return FUNC_FAILED;
    curr_dict = *dict;
    old_dict = curr_dict;
    for (; curr_dict != NULL; curr_dict = curr_dict->next) {
        if (search_func(value, curr_dict) == TRUE)
            return patch_chardict(dict, curr_dict, old_dict, do_free);
        old_dict = curr_dict;
    }
    return FUNC_SEMFAIL;
}
