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

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL || n <= 0)
        return FUNC_FAILED;
    for (; s1[i] != '\0' && s1[i] == s2[i] && i < (n - 1); i++);
    return (int)(unsigned char)(s1[i]) - (int)(unsigned char)(s2[i]);
}
