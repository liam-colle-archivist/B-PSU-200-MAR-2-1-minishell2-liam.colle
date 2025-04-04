/*
** EPITECH PROJECT, 2025
** cd
** File description:
** minishell2
*/

#include "data.h"

#ifndef SH_CONFIG_CD_H
    #define SH_CONFIG_CD_H

    #define SH_CD_BLANK NULL, NULL
    #define SH_CD_USRDIR "~", sh_cd_nav_usrdir
    #define SH_CD_OLDPWD "-", sh_cd_nav_oldpwd
    #define SH_CD_USRDIREXT "~/", sh_cd_nav_usrdirext

typedef struct {
    char *path;
    char *(*cd_f)(shell_data_t *);
} sh_cd_conf_t;

char *sh_cd_nav_usrdir(shell_data_t *shell_data);
char *sh_cd_nav_oldpwd(shell_data_t *shell_data);
char *sh_cd_nav_usrdirext(shell_data_t *shell_data);

#endif
