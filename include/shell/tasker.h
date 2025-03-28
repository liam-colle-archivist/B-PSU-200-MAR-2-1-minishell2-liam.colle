/*
** EPITECH PROJECT, 2025
** tasker
** File description:
** minishell1
*/

#include "shell.h"
#include "shell/parser.h"

#ifndef SH_TASKER_H
    #define SH_TASKER_H

int sh_build_tasker(shell_data_t *shell_data);
int sh_tasker_execute(shell_data_t *shell_data);

#endif

#ifndef SH_TASKER_ID_H
    #define SH_TASKER_ID_H

sh_tasker_type_t sh_tasker_identify_type(sh_prsent_t *args);
int sh_is_apart_of_path(char *path, sh_tasker_t *task);

#endif

#ifndef SH_TASKER_CHAINER_H
    #define SH_TASKER_CHAINER_H

sh_tasker_t *sh_tasker_create(shell_data_t *shell_data, sh_prsent_t *args);
int sh_tasker_chain(sh_tasker_t **start, sh_tasker_t *chain);
int sh_tasker_chain_ppipe(sh_tasker_t **start, sh_tasker_t *chain);
sh_tasker_t *sh_tasker_get_ptask(sh_tasker_t *task, int index);
void sh_tasker_free(sh_tasker_t *chain);
void sh_tasker_destroy(sh_tasker_t *chain);

#endif
