/*
** EPITECH PROJECT, 2025
** types
** File description:
** minishell1
*/

#include <stdio.h>
#include "../parser.h"
#include "../../utils.h"

#ifndef SH_TYPES_H
    #define SH_TYPES_H

typedef enum {
    STMODE_STANDARD,
    STMODE_PREEXEC
} sh_st_mode_t;

typedef struct {
    sh_st_mode_t start_mode;
    char *start_command;
    char *start_path;
} sh_st_options_t;

#endif
