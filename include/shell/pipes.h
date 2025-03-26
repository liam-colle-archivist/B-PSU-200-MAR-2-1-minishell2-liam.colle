/*
** EPITECH PROJECT, 2025
** pipes
** File description:
** Minishell2
*/

#include "shell/config/data.h"
#include "utils.h"

#ifndef SH_PIPES_H
    #define SH_PIPES_H

bool_t sh_pipe_is_redirect(char *shard);
bool_t sh_pipe_is_stop(char *shard);

int sh_pipes_interpret(sh_tasker_t *task, char *shard,
    char *next_argument);
int sh_tsk_intprt_std_pipe(sh_tasker_t *task, char *shard,
    char *next_argument);
int sh_tsk_intprt_stop_pipe(sh_tasker_t *task, char *shard,
    char *next_argument);

extern const sh_pipe_info_t sh_pipe_info[];

#endif
