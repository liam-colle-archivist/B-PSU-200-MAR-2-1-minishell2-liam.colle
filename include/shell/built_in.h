/*
** EPITECH PROJECT, 2025
** builtin
** File description:
** minishell1
*/
#include "shell.h"
#include "config/data.h"

#ifndef SH_BUILTIN_H
    #define SH_BUILTIN_H

    #define SETENV_AFAIL "Variable name must contain alphanumeric characters"

typedef enum {
    SH_BLTIN_EXE_SUCCESS,
    SH_BLTIN_EXE_FAILURE,
    SH_BLTIN_EXE_NOTBUILTIN
} sh_blttin_exe_st_t;

typedef struct {
    int minimum;
    int maximum;
} sh_bltin_verify_t;

sh_blttin_exe_st_t sh_execute_builtin(shell_data_t *shell_data);
int (*sh_get_builtin_exec(sh_prsent_t *parser_entry))(shell_data_t *,
    sh_tasker_t *);

int sh_builtin_clear(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_exit(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_return(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_cd(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_env(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_env_bypass(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_setenv(shell_data_t *shell_data, sh_tasker_t *task);
int sh_builtin_unsetenv(shell_data_t *shell_data, sh_tasker_t *task);

#endif

#ifndef SH_BUILTIN_UTILS_H
    #define SH_BUILTIN_UTILS_H

void sh_builtin_perror(char *cmd, char *msg);
int sh_builtin_verify(sh_prsent_t *chain,
    sh_bltin_verify_t verif);
int sh_builtin_success(shell_data_t *shell_data, int exit_code);
int sh_builtin_fail(shell_data_t *shell_data, int exit_code);

#endif
