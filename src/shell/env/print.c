/*
** EPITECH PROJECT, 2025
** print
** File description:
** minishell1
*/

#include <stdio.h>
#include "my_printf.h"
#include "utils.h"

int sh_env_print(char_dict_t *env)
{
    if (env == NULL)
        return FUNC_FAILED;
    for (; env != NULL; env = env->next)
        my_printf("%s=%s\n", env->key, env->value);
    return FUNC_SUCCESS;
}
