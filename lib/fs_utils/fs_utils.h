/*
** EPITECH PROJECT, 2024
** fs_utils
** File description:
** Setting Up
*/

#ifndef FS_HANDLER_H
    #define FS_HANDLER_H

int fs_open_file(char const *filepath);

#endif

#ifndef FS_CAT_H
    #define FS_UTILS_H

char *fs_read_x_bytes(char const *filepath, int x);
char *fs_read_entire_file(char const *filepath);

#endif

#ifndef FS_STRINGS_H
    #define FS_STRINGS_H

void fs_putstr_fd(const char *str, int fd);
int fs_abort(const char *str);
void fs_putstr(const char *str);

#endif
