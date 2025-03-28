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
    SH_PARSER_PIPE,
    SH_PARSER_PROG_PIPE,
    SH_PARSER_STOP_PIPE,
    SH_PARSER_COMMAND
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
    #define SH_DATA_DEFAULT_EC 0
    #define SH_LSTEXC(shell_data)   (shell_data->last_excode)
    #define SH_EXEC_CCNT(shell_data)    (SH_LSTEXC(shell_data) == 0)

#endif

#ifndef SH_PIPES_DATA_H
    #define SH_PIPES_DATA_H

typedef enum {
    SH_TPIPE_UNKNOWN = -1,
    SH_TPIPE_REDIR,
    SH_TPIPE_REDIR_APPEND,
    SH_TPIPE_IREDIR,
    SH_TPIPE_IREDIR_APPEND,
    SH_TPIPE_BRIDGE,
} sh_tasker_pipe_type_t;

typedef struct {
    sh_prsent_type_t type;
    char **symbol;
    int (*tsk_interpret_f)(struct sh_tasker_s *, char *, char *);
} sh_pipe_info_t;

#endif

#ifndef SH_TASKS_DATA_H
    #define SH_TASKS_DATA_H

typedef enum {
    SH_TASKER_UNKNOWN = -1,
    SH_TASKER_COMMAND,
    SH_TASKER_BUILTIN,
} sh_tasker_type_t;

typedef enum {
    SH_EXEC_UNKNOWN = -1,
    SH_EXEC_STRICT,
    SH_EXEC_LAX,
} sh_tasker_exec_type_t;

typedef struct {
    sh_tasker_pipe_type_t pipe_type;
    sh_tasker_exec_type_t exec_type;
    int stdin_fd;
    char *stdin_fn;
    int stdout_fd;
    char *stdout_fn;
    int stderr_fd;
    char *stderr_fn;
} sh_tasker_redirect_t;

typedef struct sh_tasker_s {
    sh_tasker_type_t type;
    char *program;
    char **args;
    int (*exec_fnc)(shell_data_t *, struct sh_tasker_s *);
    sh_tasker_redirect_t pipes;
    shell_data_t *shell_data;
    sh_prsent_t *parser_entry;
    struct sh_tasker_s *prog_pipes;
    struct sh_tasker_s *next;
    struct sh_tasker_s *prev;
} sh_tasker_t;

typedef struct {
    shell_data_t *shell_data;
    int stdin_fd;
    int stdout_fd;
    int stderr_fd;
} sh_tasker_pre_data_t;

    #define SH_TASKER_DEF_PREDAT  NULL, STDIN, STDERR, STDOUT
    #define SH_TSKPIPE_DEF SH_TPIPE_UNKNOWN, 0, -1, NULL, -1, NULL, -1, NULL
    #define SH_STDIN_REX(rd_data) (rd_data->stdin_fn != NULL)
    #define SH_STDIN_RFD(rd_data) (rd_data->stdin_fd)
    #define SH_STDIN_RFN(rd_data) (rd_data->stdin_fn)
    #define SH_STDOUT_REX(rd_data) (rd_data->stdout_fn != NULL)
    #define SH_STDOUT_RFD(rd_data) (rd_data->stdout_fd)
    #define SH_STDOUT_RFN(rd_data) (rd_data->stdout_fn)
    #define SH_STDERR_REX(rd_data) (rd_data->stderr_fn != NULL)
    #define SH_STDERR_RFD(rd_data) (rd_data->stderr_fd)
    #define SH_STDERR_RFN(rd_data) (rd_data->stderr_fn)
    #define SH_EXEC_MODE(task) (task->pipes.exec_type)
    #define SH_EXEC_MSTRICT(rd_data) (SH_EXEC_MODE(rd_data) == SH_EXEC_STRICT)
    #define SH_EXEC_MLAX(rd_data) (SH_EXEC_MODE(rd_data) == SH_EXEC_LAX)

#endif
