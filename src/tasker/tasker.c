/*
** EPITECH PROJECT, 2025
** tasker
** File description:
** minishell2
*/

#include <stdio.h>
#include "my.h"
#include "shell/shell.h"
#include "shell/parser.h"
#include "shell/tasker.h"
#include "shell/exec.h"
#include "shell/pipes.h"

static void move_to_next_command(sh_prsent_t **parser_ent)
{
    sh_prsent_t *curr_ent = NULL;

    if (parser_ent == NULL)
        return;
    curr_ent = *parser_ent;
    for (; curr_ent != NULL; curr_ent = curr_ent->next)
        if (sh_parser_is_anypipe(curr_ent) == TRUE) {
            *parser_ent = curr_ent->next;
            return;
        }
    *parser_ent = NULL;
}

static int consume_p_pipe(sh_tasker_t *tasker, sh_prsent_t **parser_ent)
{
    sh_prsent_t *curr_ent = NULL;
    sh_tasker_t *new_task = NULL;

    if (tasker == NULL || parser_ent == NULL)
        return FUNC_FAILED;
    for (curr_ent = *parser_ent; curr_ent != NULL &&
        sh_parser_is_spipe(curr_ent) == FALSE; curr_ent = curr_ent->next) {
        if (curr_ent->type != SH_PARSER_PROG_PIPE)
            continue;
        new_task = sh_tasker_create(tasker->shell_data, curr_ent->next);
        if (new_task == NULL)
            return FUNC_FAILED;
        new_task->exec_fnc = sh_exec_program_ppipe;
        tasker->exec_fnc = sh_exec_program_ppipe;
        sh_tasker_chain_ppipe(&tasker->prog_pipes, new_task);
    }
    return FUNC_SUCCESS;
}

static int consume_pipe(sh_tasker_t *tasker, sh_prsent_t **parser_ent)
{
    sh_prsent_t *curr_ent = NULL;

    if (tasker == NULL || parser_ent == NULL)
        return FUNC_FAILED;
    if (consume_p_pipe(tasker, parser_ent) == FUNC_FAILED)
        return FUNC_FAILED;
    for (curr_ent = *parser_ent; curr_ent != NULL &&
        sh_parser_is_spipe(curr_ent) == FALSE; curr_ent = curr_ent->next) {
        if (curr_ent->type == SH_PARSER_COMMAND)
            continue;
        if (sh_pipes_interpret(tasker, curr_ent->entry, curr_ent->next
            != NULL ? curr_ent->next->entry : NULL) == FUNC_FAILED)
            return FUNC_FAILED;
        *parser_ent = curr_ent->next != NULL ? curr_ent->next->next : NULL;
        curr_ent = curr_ent->next != NULL ? curr_ent->next : curr_ent;
        }
    return FUNC_SUCCESS;
}

static int build_task(sh_tasker_t **tasker, sh_prsent_t **parser_ent,
    sh_tasker_pre_data_t *pre_data)
{
    sh_tasker_t *new_task = NULL;

    if (tasker == NULL || parser_ent == NULL || pre_data == NULL)
        return FUNC_FAILED;
    new_task = sh_tasker_create(pre_data->shell_data, *parser_ent);
    if (new_task == NULL)
        return FUNC_FAILED;
    if (sh_tasker_chain(tasker, new_task) == FUNC_FAILED)
        return FUNC_FAILED;
    consume_pipe(new_task, parser_ent);
    return FUNC_SUCCESS;
}

int sh_build_tasker(shell_data_t *shell_data)
{
    sh_tasker_t *tasker = NULL;
    sh_tasker_pre_data_t pre_dat = {SH_TASKER_DEF_PREDAT};
    sh_prsent_t *args = NULL;

    if (shell_data == NULL)
        return FUNC_FAILED;
    pre_dat.shell_data = shell_data;
    args = shell_data->command_chain;
    while (args != NULL) {
        if (build_task(&tasker, &args, &pre_dat) == FUNC_FAILED) {
            my_putstr_fd("mysh: Failed to build tasker\n", STDOUT);
            shell_data->tasks = tasker;
            return FUNC_SEMFAIL;
        }
        move_to_next_command(&args);
    }
    shell_data->tasks = tasker;
    return FUNC_SUCCESS;
}
