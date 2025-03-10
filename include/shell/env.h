/*
** EPITECH PROJECT, 2025
** env
** File description:
** minishell1
*/

#include "../my.h"

#ifndef SH_ENV_H
    #define SH_ENV_H

char_dict_t *sh_env_load(char **env);
char **sh_env_to_tab(char_dict_t *dict);
char *sh_env_get(char_dict_t *env, char *key);
int sh_env_set(char_dict_t *env, char *key, char *value);
int sh_env_print(char_dict_t *env);

#endif
