/*
** EPITECH PROJECT, 2025
** exec_program_pipe
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "shell/built_in.h"
#include "shell/shell.h"
#include "shell/tasker.h"
#include "shell/env.h"
#include "shell/misc.h"
#include "shell/exec.h"
#include "shell/pipes.h"

static int is_dad(shell_data_t *shell_data, pid_t child_pid)
{
    int status = EXIT_SUCCESS;

    if (shell_data == NULL)
        return FUNC_FAILED;
    if (waitpid(child_pid, &status, 0) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE_84);
    if (WIFSIGNALED(status)) {
        sh_exec_print_crash(status);
        return sh_builtin_fail(shell_data, status);
    }
    if (WEXITSTATUS(status) == 127)
        return sh_builtin_fail(shell_data, WEXITSTATUS(status));
    return sh_builtin_success(shell_data, shell_data->last_excode == 0 ?
        WEXITSTATUS(status) : shell_data->last_excode);
}

static int assign_pipes(int **pipesfd, int iter)
{
    if (pipesfd == NULL || iter < 0)
        return FUNC_FAILED;
    if (pipesfd[iter] == NULL)
        return FUNC_FAILED;
    if (iter > 0)
        if (dup2(pipesfd[iter][0], STDIN_FILENO) == FUNC_FAILED)
            return FUNC_FAILED;
    if (pipesfd[iter + 1] != NULL)
        if (dup2(pipesfd[iter + 1][1], STDOUT_FILENO) == FUNC_FAILED)
            return FUNC_FAILED;
    sh_pipesfd_close_all(pipesfd);
    return FUNC_SUCCESS;
}

static int check_commands(sh_tasker_t *task)
{
    int status = FUNC_SUCCESS;

    if (task == NULL)
        return FUNC_FAILED;
    for (; task != NULL; task = task->prog_pipes) {
        if (sh_is_apart_of_path(sh_env_get(task->shell_data->env, "PATH"),
            task) == FUNC_SEMFAIL)
            status = FUNC_FAILED;
        if (sh_exec_check_access(task->program) == FUNC_FAILED)
            status = FUNC_FAILED;
    }
    return status;
}

static int is_child(sh_tasker_t *task, int **pipesfd, int iter)
{
    char **env = NULL;

    if (task == NULL || pipesfd == NULL || iter < 0)
        exit(EXIT_FAILURE);
    if (assign_pipes(pipesfd, iter) == FUNC_FAILED) {
        sh_pipesfd_close_all(pipesfd);
        exit(EXIT_FAILURE);
    }
    if (task->shell_data != NULL)
        env = sh_env_to_tab(task->shell_data->env);
    if (execve(task->program, task->args, env) == FUNC_FAILED) {
        if (task->program != NULL)
            sh_exec_print_execerror(task->program, errno);
        exit(EXIT_FAILURE);
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}

static int create_children(sh_tasker_t *task, int **pipesfd)
{
    if (task == NULL || pipesfd == NULL) {
        sh_pipesfd_close_free(pipesfd);
        return FUNC_FAILED;
    }
    for (int i = 0; pipesfd[i] != NULL; i++) {
        pipesfd[i][2] = fork();
        if (pipesfd[i][2] == FUNC_FAILED) {
            sh_pipesfd_close_free(pipesfd);
            return FUNC_FAILED;
        }
        if (pipesfd[i][2] == 0)
            is_child(sh_tasker_get_ptask(task, i), pipesfd, i);
        if (pipesfd[i + 1] == NULL)
            sh_pipesfd_close_all(pipesfd);
    }
    return FUNC_SUCCESS;
}

int sh_exec_program_ppipe(shell_data_t *shell_data, sh_tasker_t *task)
{
    int **pipefd = NULL;

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, 1);
    if (check_commands(task) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, 1);
    pipefd = sh_pipesfd_generate(task);
    if (pipefd == NULL)
        return sh_builtin_fail(shell_data, 1);
    if (create_children(task, pipefd) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, 1);
    for (int i = 0; pipefd[i] != NULL; i++)
        if (is_dad(shell_data, pipefd[i][2]) == FUNC_FAILED) {
            sh_pipesfd_close_free(pipefd);
            return FUNC_FAILED;
        }
    sh_pipesfd_free(pipefd);
    return FUNC_SUCCESS;
}
