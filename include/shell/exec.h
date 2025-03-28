/*
** EPITECH PROJECT, 2025
** exec
** File description:
** minishell1
*/

#include "shell.h"

#ifndef SH_EXEC_H
    #define SH_EXEC_H

int sh_exec_program(shell_data_t *shell_data, sh_tasker_t *task);
int sh_exec_program_pipe(shell_data_t *shell_data, sh_tasker_t *task);
int sh_exec_program_ppipe(shell_data_t *shell_data, sh_tasker_t *task);
void sh_exec_print_crash(int status);
void sh_exec_print_execerror(const char *program, int errcode);
int sh_exec_check_access(const char *program);

#endif
