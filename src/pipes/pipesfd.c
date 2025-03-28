/*
** EPITECH PROJECT, 2025
** pipesfd
** File description:
** Minishell2
*/

#include <stdlib.h>
#include <unistd.h>
#include "shell/tasker.h"

int sh_pipesfd_len(sh_tasker_t *tasks)
{
    int len = 0;
    sh_tasker_t *curr_task = NULL;

    if (tasks == NULL)
        return FUNC_FAILED;
    for (curr_task = tasks->prog_pipes; curr_task != NULL;
        curr_task = curr_task->prog_pipes)
        len++;
    return len;
}

int **sh_pipesfd_generate(sh_tasker_t *tasks)
{
    int len = 0;
    int **pipesfd = NULL;

    len = sh_pipesfd_len(tasks);
    if (len <= 0)
        return NULL;
    len++;
    pipesfd = malloc(sizeof(int *) * (len + 1));
    if (pipesfd == NULL)
        return NULL;
    pipesfd[len] = NULL;
    for (int i = 0; i < len; i++) {
        pipesfd[i] = malloc(sizeof(int) * 3);
        if (pipesfd[i] == NULL)
            return NULL;
        if (pipe(pipesfd[i]) == FUNC_FAILED)
            return NULL;
        pipesfd[i][2] = -1;
    }
    return pipesfd;
}

void sh_pipesfd_close_all(int **pipesfd)
{
    if (pipesfd == NULL)
        return;
    for (int i = 0; pipesfd[i] != NULL; i++) {
        close(pipesfd[i][0]);
        close(pipesfd[i][1]);
    }
}

void sh_pipesfd_free(int **pipesfd)
{
    if (pipesfd == NULL)
        return;
    for (int i = 0; pipesfd[i] != NULL; i++)
        free(pipesfd[i]);
    free(pipesfd);
}

void sh_pipesfd_close_free(int **pipesfd)
{
    if (pipesfd == NULL)
        return;
    sh_pipesfd_close_all(pipesfd);
    sh_pipesfd_free(pipesfd);
}
