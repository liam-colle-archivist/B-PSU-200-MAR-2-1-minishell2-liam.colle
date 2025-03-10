/*
** EPITECH PROJECT, 2025
** exec_program
** File description:
** minishell1
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

static void print_crash(int status)
{
    if (WTERMSIG(status) == SIGFPE)
        my_putstr_fd("Floating exception", STDERR);
    else
        my_putstr_fd(strsignal(WTERMSIG(status)), STDERR);
    if (WCOREDUMP(status) != 0)
            my_putstr_fd(" (core dumped)", STDERR);
    my_putstr_fd("\n", STDERR);
}

static void print_execerror(char *program, int errcode)
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

static int is_dad(shell_data_t *shell_data, pid_t child_pid)
{
    int status = EXIT_SUCCESS;

    if (shell_data == NULL)
        return FUNC_FAILED;
    if (waitpid(child_pid, &status, 0) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE_84);
    if (WIFSIGNALED(status)) {
        print_crash(status);
        return sh_builtin_fail(shell_data, status);
    }
    if (WEXITSTATUS(status) == 127)
        return sh_builtin_fail(shell_data, WEXITSTATUS(status));
    return sh_builtin_success(shell_data, WEXITSTATUS(status));
}

static int is_child(sh_tasker_t *task)
{
    char **env = NULL;

    if (task == NULL) {
        exit(EXIT_FAILURE);
        return FUNC_FAILED;
    }
    if (task->shell_data != NULL)
        env = sh_env_to_tab(task->shell_data->env);
    if (env == NULL)
        my_putstr_fd("mysh: Cannot convert env\n", STDERR);
    if (execve(task->program, task->args, env) == FUNC_FAILED) {
        if (task->program != NULL)
            print_execerror(task->program, errno);
        exit(EXIT_FAILURE);
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}

int sh_exec_program(shell_data_t *shell_data, sh_tasker_t *task)
{
    int fork_result = 0;

    if (shell_data == NULL || task == NULL)
        return FUNC_FAILED;
    fork_result = fork();
    if (fork_result == FUNC_FAILED)
        return FUNC_FAILED;
    if (fork_result == 0)
        is_child(task);
    return is_dad(shell_data, fork_result);
}
