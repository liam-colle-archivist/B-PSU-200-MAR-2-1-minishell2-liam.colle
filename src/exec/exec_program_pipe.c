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
#include "shell/env.h"
#include "shell/misc.h"
#include "shell/exec.h"

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
    return sh_builtin_success(shell_data, WEXITSTATUS(status));
}

static int pipe_and_redirect(const char *filename, int fd, int fd_to_replace)
{
    int new_fd = FUNC_FAILED;
    int ret_stat = FUNC_FAILED;

    if (fd_to_replace < 0)
        return FUNC_FAILED;
    if (filename != NULL) {
        new_fd = open(filename, O_CREAT | O_WRONLY, 0644);
        if (new_fd < 0)
            return FUNC_FAILED;
        ret_stat = dup2(new_fd, fd_to_replace);
        close(new_fd);
        return ret_stat;
    }
    return dup2(fd, fd_to_replace);
}

static int assign_pipes(sh_tasker_redirect_t *rd, int p_fd[2])
{
    if (rd == NULL || p_fd == NULL)
        return FUNC_FAILED;
    if (rd->stdin_fd != -1)
        return SH_STDIN_REX(rd) ? pipe_and_redirect(SH_STDIN_RFN(rd),
        -1, STDIN) : pipe_and_redirect(SH_STDIN_RFN(rd), p_fd[0], STDIN);
    if (rd->stdout_fd != -1)
        return SH_STDOUT_REX(rd) ? pipe_and_redirect(SH_STDOUT_RFN(rd),
        -1, STDOUT) : pipe_and_redirect(SH_STDOUT_RFN(rd), p_fd[0], STDOUT);
    if (rd->stderr_fd != -1)
        return SH_STDERR_REX(rd) ? pipe_and_redirect(SH_STDERR_RFN(rd),
        -1, STDERR) : pipe_and_redirect(SH_STDERR_RFN(rd), p_fd[0], STDERR);
    return FUNC_SUCCESS;
}

static int is_child(sh_tasker_t *task, int pipe_fd[2])
{
    char **env = NULL;

    if (task == NULL || pipe_fd == NULL) {
        exit(EXIT_FAILURE);
        return FUNC_FAILED;
    }
    if (assign_pipes(&task->pipes, pipe_fd) == FUNC_FAILED)
        return sh_vclose_ret(FUNC_FAILED, 2, pipe_fd[0], pipe_fd[1]);
    sh_vclose(2, pipe_fd[0], pipe_fd[1]);
    if (task->shell_data != NULL)
        env = sh_env_to_tab(task->shell_data->env);
    if (env == NULL)
        my_putstr_fd("mysh: Cannot convert env\n", STDERR);
    if (execve(task->program, task->args, env) == FUNC_FAILED) {
        if (task->program != NULL)
            sh_exec_print_execerror(task->program, errno);
        exit(EXIT_FAILURE);
        return FUNC_FAILED;
    }
    return FUNC_SUCCESS;
}

int sh_exec_program_pipe(shell_data_t *shell_data, sh_tasker_t *task)
{
    int pipe_fd[2] = {-1, -1};
    int fork_result = 0;

    if (shell_data == NULL || task == NULL)
        return FUNC_FAILED;
    if (pipe(pipe_fd) == FUNC_FAILED)
        return FUNC_FAILED;
    fork_result = fork();
    if (fork_result == FUNC_FAILED)
        return FUNC_FAILED;
    if (fork_result == 0)
        is_child(task, pipe_fd);
    return is_dad(shell_data, fork_result);
}
