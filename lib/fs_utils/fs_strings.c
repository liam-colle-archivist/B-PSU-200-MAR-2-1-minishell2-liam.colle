/*
** EPITECH PROJECT, 2024
** fs_strings
** File description:
** libfs
*/

#include "utils.h"
#include <unistd.h>

static int fs_strlen(const char *str)
{
    int i = 0;

    if (str == NULL)
        return FUNC_FAILED;
    for (; str[i] != '\0'; i++);
    return i;
}

void fs_putstr_fd(const char *str, int fd)
{
    int len = 0;

    if (str == NULL || fd < 0)
        return;
    len = fs_strlen(str);
    if (len == FUNC_FAILED)
        return;
    write(fd, str, sizeof(char) * len);
}

int fs_abort(const char *str)
{
    if (str == NULL)
        return FUNC_FAILED;
    fs_putstr_fd(str, STDERR);
    return FUNC_FAILED;
}

void fs_putstr(const char *str)
{
    fs_putstr_fd(str, STDOUT);
}
