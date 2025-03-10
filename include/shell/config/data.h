/*
** EPITECH PROJECT, 2025
** data
** File description:
** minishell1
*/

#include "../../utils.h"

#ifndef SH_PARSER_TYPES_H
    #define SH_PARSER_TYPES_H

typedef enum {
    SH_PARSER_UNKNOWN = -1,
    SH_PARSER_COMMAND,
    SH_PARSER_PIPE
} sh_prsent_type_t;

typedef struct sh_prsent_s {
    char *entry;
    sh_prsent_type_t type;
    struct sh_prsent_s *next;
} sh_prsent_t;

#endif

#ifndef SH_DATA_H
    #define SH_DATA_H

typedef int sh_exit_code_t;

typedef struct {
    char *user;
    char *user_homedir;
    char *hostname;
    char **path;
} shell_usr_data_t;

typedef struct {
    char *pwd;
    char *old_pwd;
    char_dict_t *env;
    sh_prsent_t *command_chain;
    shell_usr_data_t *user_data;
    struct sh_tasker_s *tasks;
    sh_exit_code_t last_excode;
    bool_t is_active;
} shell_data_t;

    #define SH_DATA_DEFAULT NULL, NULL, NULL, -1, TRUE
    #define SH_DATA_DEFAULT_EC -1

#endif

#ifndef SH_TASKS_H
    #define SH_TASKS_H

typedef enum {
    SH_TASKER_UNKNOWN = -1,
    SH_TASKER_COMMAND,
    SH_TASKER_BUILTIN,
} sh_tasker_type_t;

typedef struct sh_tasker_s {
    sh_tasker_type_t type;
    char *program;
    char **args;
    int (*exec_fnc)(shell_data_t *, struct sh_tasker_s *);
    int stdin_fd;
    int stdout_fd;
    int stderr_fd;
    shell_data_t *shell_data;
    sh_prsent_t *parser_entry;
    struct sh_tasker_s *next;
} sh_tasker_t;

typedef struct {
    shell_data_t *shell_data;
    int stdin_fd;
    int stdout_fd;
    int stderr_fd;
} sh_tasker_pre_data_t;

    #define SH_TASKER_DEF_PREDAT  NULL, STDIN, STDERR, STDOUT

#endif
