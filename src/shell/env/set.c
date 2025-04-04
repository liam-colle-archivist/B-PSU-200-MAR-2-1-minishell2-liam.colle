/*
** EPITECH PROJECT, 2025
** set
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "utils.h"

int sh_env_set(char_dict_t *env, char *key, char *value)
{
    if (env == NULL || key == NULL)
        return FUNC_FAILED;
    return my_chardict_set(env, key, value, TRUE);
}
