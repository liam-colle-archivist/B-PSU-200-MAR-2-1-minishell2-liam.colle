/*
** EPITECH PROJECT, 2024
** my_strstrdup
** File description:
** Day 8, Task 1
*/

#include <stdlib.h>
#include "my.h"
#include "utils.h"

char *my_strchrdup(const char *src, const char to_find)
{
    int i = 0;
    int len = FUNC_FAILED;
    char *dest = NULL;
    char *ref_ptr = NULL;

    if (src == NULL)
        return NULL;
    len = my_strchrlen(src, to_find);
    ref_ptr = my_strchr(src, to_find);
    if (len == FUNC_FAILED)
        return NULL;
    dest = malloc(sizeof(char) * (len + 1));
    if (dest == NULL)
        return NULL;
    for (; i < len && &src[i] != ref_ptr; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
