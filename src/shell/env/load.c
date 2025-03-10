/*
** EPITECH PROJECT, 2025
** load
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "utils.h"

static int env_process_entry(char_dict_t **dict, char *entry)
{
    char *key = NULL;
    char *value = NULL;
    char *equal_sign = NULL;
    char_dict_t *dict_ent = NULL;

    if (dict == NULL || entry == NULL)
        return FUNC_FAILED;
    equal_sign = my_strchr(entry, '=');
    if (equal_sign == NULL)
        return FUNC_FAILED;
    key = my_strptrdup(entry, equal_sign);
    if (*equal_sign != '\0')
        equal_sign++;
    value = my_strdup(equal_sign);
    dict_ent = my_chardict_create(key, value);
    return my_chardict_chain(dict, dict_ent);
}

char_dict_t *sh_env_load(char **env)
{
    char_dict_t *dict = NULL;

    if (env == NULL) {
        my_putstr_fd("mysh: Unable to load environment variables\n", STDERR);
        return NULL;
    }
    for (int i = 0; env[i] != NULL; i++)
        env_process_entry(&dict, env[i]);
    return dict;
}
