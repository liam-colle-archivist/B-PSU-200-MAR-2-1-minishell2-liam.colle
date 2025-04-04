/*
** EPITECH PROJECT, 2025
** my_isin
** File description:
** libmy
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

bool_t my_isin(const char *string, const char **string_list)
{
    if (string == NULL || string_list == NULL)
        return FALSE;
    for (int i = 0; string_list[i] != NULL; i++)
        if (my_strcmp(string, string_list[i]) == CMP_EXACT)
            return TRUE;
    return FALSE;
}
