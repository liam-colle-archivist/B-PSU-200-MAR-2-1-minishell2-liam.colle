/*
** EPITECH PROJECT, 2024
** my_strstrdup
** File description:
** Day 8, Task 1
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

char *my_strptrdup(const char *src, const char *tgt_ptr)
{
    int i = 0;
    int len = FUNC_FAILED;
    char *dest = NULL;

    if (src == NULL)
        return NULL;
    len = my_strptrlen(src, tgt_ptr);
    if (len == FUNC_FAILED)
        return NULL;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    for (; i < len && &src[i] != tgt_ptr; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
