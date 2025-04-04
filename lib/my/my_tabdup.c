/*
** EPITECH PROJECT, 2024
** my_tabdup
** File description:
** day 4, task 3
** my_strlen.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

char **my_tabdup(char **src)
{
    int tab_len = my_tablen((const void **) src);
    char **new_tab = NULL;

    if (src == NULL)
        return NULL;
    new_tab = malloc(sizeof(char **) * tab_len);
    if (new_tab == NULL)
        return NULL;
    for (int i = 0; src[i] != NULL; i++)
        new_tab[i] = my_strdup(src[i]);
    new_tab[tab_len] = NULL;
    return new_tab;
}
