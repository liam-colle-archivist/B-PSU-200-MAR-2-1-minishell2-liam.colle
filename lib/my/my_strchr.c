/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Day 6, Task 5
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "utils.h"

char *my_strchr(const char *str, const char to_find)
{
    if (str == NULL)
        return NULL;
    if (to_find == '\0')
        return (char *) str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == to_find)
            return (char *) &str[i];
    }
    return NULL;
}
