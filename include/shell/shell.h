/*
** EPITECH PROJECT, 2025
** shell (Header)
** File description:
** minishell2
*/

#include <unistd.h>
#include "config/types.h"
#include "parser.h"
#include "utils.h"

#ifndef SH_H
    #define SH_H

shell_data_t *init_shell_conf(char **env, sh_st_options_t *options);
shell_data_t *sh_data_init(char_dict_t *env);
shell_usr_data_t *sh_usrdata_init(char_dict_t *env);
void sh_data_purge(shell_data_t *shell_data);
int shell(shell_data_t *shell_data);

#endif
