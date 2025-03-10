/*
** EPITECH PROJECT, 2024
** fs_cat
** File description:
** Setting Up (Bootstrap)
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "fs_utils.h"
#include "utils.h"

char *fs_read_x_bytes(char const *filepath, int x)
{
    int fd = fs_open_file(filepath);
    char *buffer = malloc(sizeof(char) * (x + 1));
    int rd_size = read(fd, buffer, x);

    if (fd == FUNC_FAILED)
        return NULL;
    if (buffer == NULL) {
        close(fd);
        return NULL;
    }
    for (int i = rd_size; i < (x + 1); i++)
        buffer[i] = '\0';
    close(fd);
    return buffer;
}

char *fs_read_entire_file(char const *filepath)
{
    struct stat sb;
    char *str = NULL;

    if (stat(filepath, &sb) == FUNC_FAILED)
        return NULL;
    str = fs_read_x_bytes(filepath, sb.st_size);
    if (str == NULL)
        return NULL;
    return str;
}
