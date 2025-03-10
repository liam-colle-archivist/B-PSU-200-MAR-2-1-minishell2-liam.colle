/*
** EPITECH PROJECT, 2025
** get
** File description:
** minishell1
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

char *sh_env_get(char_dict_t *env, char *key)
{
    if (env == NULL || key == NULL)
        return NULL;
    for (; env != NULL; env = env->next) {
        if (my_strcmp(env->key, key) == CMP_EXACT)
            return env->value;
    }
    return NULL;
}
