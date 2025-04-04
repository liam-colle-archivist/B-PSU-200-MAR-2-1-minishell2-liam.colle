/*
** EPITECH PROJECT, 2025
** get
** File description:
** minishell2
*/

#include <stdio.h>
#include "shell/parser.h"
#include "my.h"

sh_tasker_t *sh_tasker_get_ptask(sh_tasker_t *task, int index)
{
    if (task == NULL || index < 0)
        return NULL;
    for (int i = 0; i < index && task != NULL; i++) {
        if (i == index)
            break;
        task = task->prog_pipes;
    }
    return task;
}
