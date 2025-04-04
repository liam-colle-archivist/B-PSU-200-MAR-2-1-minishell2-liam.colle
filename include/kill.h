/*
** EPITECH PROJECT, 2025
** kill
** File description:
** minishell2
*/

#include <sys/types.h>
#include <signal.h>

#ifndef KILL_H
    #define KILL_H

int kill(pid_t __pid, int __sig);

#endif
