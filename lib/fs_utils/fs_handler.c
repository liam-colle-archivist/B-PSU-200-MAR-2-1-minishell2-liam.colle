/*
** EPITECH PROJECT, 2024
** fs_handler
** File description:
** Setting Up (Bootstrap)
*/

#include <fcntl.h>
#include <unistd.h>
#include "utils.h"

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return FUNC_FAILED;
    return fd;
}
