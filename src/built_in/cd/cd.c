/*
** EPITECH PROJECT, 2025
** cd
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "shell/env.h"
#include "shell/shell.h"
#include "shell/built_in.h"
#include "shell/config/cd.h"
#include "utils.h"

static int update_path(shell_data_t *shell_data, char *path)
{
    char *pwd = NULL;
    char *cwd = NULL;

    if (shell_data == NULL || path == NULL)
        return FUNC_FAILED;
    if (chdir(path) == FUNC_FAILED) {
        sh_builtin_perror(path, strerror(errno));
        return FUNC_FAILED;
    }
    free(path);
    pwd = sh_env_get(shell_data->env, "PWD");
    if (sh_env_set(shell_data->env, "OLDPWD", my_strdup(pwd))
        == FUNC_FAILED)
        return FUNC_FAILED;
    if (sh_env_set(shell_data->env, "PWD", getcwd(cwd, 0)) == FUNC_FAILED)
        return FUNC_FAILED;
    return FUNC_SUCCESS;
}

static int bootstrap_cd(shell_data_t *shell_data, char *path)
{
    sh_cd_conf_t config[] = {{SH_CD_USRDIREXT}, {SH_CD_USRDIR},
        {SH_CD_OLDPWD}, {SH_CD_BLANK}};

    if (shell_data == NULL || path == NULL)
        return FUNC_FAILED;
    if (path == NULL)
        return FUNC_FAILED;
    for (int i = 0; config[i].path != NULL; i++)
        if (my_strncmp(path, config[i].path, 2) == CMP_EXACT)
            return update_path(shell_data, config[i].cd_f(shell_data));
    return update_path(shell_data, my_strdup(path));
}

int sh_builtin_cd(shell_data_t *shell_data, sh_tasker_t *task)
{
    char *path = NULL;
    sh_bltin_verify_t prerequisites = {0, 1};

    if (shell_data == NULL || task == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (sh_builtin_verify(task->parser_entry, prerequisites) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    if (shell_data->command_chain == NULL)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    path = sh_get_prsent_index(task->parser_entry, 1);
    if (path == NULL)
        path = "~";
    if (bootstrap_cd(shell_data, path) == FUNC_FAILED)
        return sh_builtin_fail(shell_data, EXIT_FAILURE);
    return sh_builtin_success(shell_data, EXIT_SUCCESS);
}
