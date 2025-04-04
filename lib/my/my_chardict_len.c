/*
** EPITECH PROJECT, 2025
** my_chardict_free
** File description:
** libmy
*/

#include <stdlib.h>
#include "utils.h"

int my_chardict_len(char_dict_t *dict)
{
    int len = 0;

    if (dict == NULL)
        return FUNC_FAILED;
    for (; dict != NULL; dict = dict->next)
        len++;
    return len;
}
