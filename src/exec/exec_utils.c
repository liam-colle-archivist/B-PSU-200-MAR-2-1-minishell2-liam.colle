/*
** EPITECH PROJECT, 2025
** exec_utils
** File description:
** minishell2
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "kill.h"
#include "shell/built_in.h"
#include "shell/shell.h"
#include "shell/env.h"
#include "shell/misc.h"

void sh_exec_print_crash(int status)
{
    if (WTERMSIG(status) == SIGFPE)
        my_putstr_fd("Floating exception", STDERR);
    else
        my_putstr_fd(strsignal(WTERMSIG(status)), STDERR);
    if (WCOREDUMP(status) != 0)
            my_putstr_fd(" (core dumped)", STDERR);
    my_putstr_fd("\n", STDERR);
}

void sh_exec_print_execerror(const char *program, int errcode)
{
    my_putstr_fd(program, STDERR);
    if (errcode == ENOENT) {
        my_putstr_fd(": Command not found.\n", STDERR);
        return;
    }
    my_putstr_fd(": ", STDERR);
    my_putstr_fd(strerror(errcode), STDERR);
    my_putstr_fd(".\n", STDERR);
}

int sh_exec_check_access(const char *program)
{
    if (program == NULL)
        return FUNC_FAILED;
    if (access(program, X_OK) == FUNC_FAILED) {
        sh_exec_print_execerror(program, errno);
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}
