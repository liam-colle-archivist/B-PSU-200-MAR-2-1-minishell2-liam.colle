/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** day 4, task 3
** my_strlen.c
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

int my_strstrlen(const char *str, const char *to_find)
{
    int i = 0;
    char *ref_ptr = NULL;

    if (str == NULL)
        return FUNC_FAILED;
    ref_ptr = my_strstr((char *) str, to_find);
    for (i = 0; str[i] != '\0' && &str[i] != ref_ptr; i++);
    return i;
}
