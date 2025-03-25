/*
** EPITECH PROJECT, 2025
** sh_vclose
** File description:
** minishell2
*/

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

void sh_vclose(int n, ...)
{
    va_list args;

    if (n <= 0)
        return;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        close(va_arg(args, int));
    va_end(args);
}

int sh_vclose_ret(int code, int n, ...)
{
    va_list args;

    if (n <= 0)
        return code;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        close(va_arg(args, int));
    va_end(args);
    return code;
}
