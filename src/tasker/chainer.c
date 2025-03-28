/*
** EPITECH PROJECT, 2025
** chainer
** File description:
** minishell1
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell/exec.h"
#include "shell/parser.h"
#include "shell/built_in.h"
#include "shell/tasker.h"
#include "my.h"
#include "utils.h"

sh_tasker_t *sh_tasker_create(shell_data_t *shell_data, sh_prsent_t *args)
{
    sh_tasker_t *new_chain = NULL;

    if (shell_data == NULL || args == NULL)
        return NULL;
    new_chain = malloc(sizeof(sh_tasker_t));
    if (new_chain == NULL)
        return NULL;
    new_chain->type = sh_tasker_identify_type(args);
    new_chain->program = my_strdup(sh_get_prsent_index(args, 0));
    new_chain->args = sh_prsent_to_char_tab(args);
    new_chain->parser_entry = args;
    new_chain->pipes = (sh_tasker_redirect_t) {SH_TSKPIPE_DEF};
    new_chain->prog_pipes = NULL;
    new_chain->exec_fnc = sh_exec_program;
    new_chain->shell_data = shell_data;
    if (new_chain->type == SH_TASKER_BUILTIN)
        new_chain->exec_fnc = sh_get_builtin_exec(args);
    new_chain->next = NULL;
    new_chain->prev = NULL;
    return new_chain;
}

int sh_tasker_chain(sh_tasker_t **start, sh_tasker_t *chain)
{
    sh_tasker_t *curr_chain = NULL;

    if (start == NULL || chain == NULL)
        return FUNC_FAILED;
    if (*start == NULL) {
        *start = chain;
        return FUNC_SUCCESS;
    }
    curr_chain = *start;
    for (; curr_chain->next != NULL; curr_chain = curr_chain->next);
    curr_chain->next = chain;
    chain->prev = curr_chain;
    return FUNC_SUCCESS;
}

int sh_tasker_chain_ppipe(sh_tasker_t **start, sh_tasker_t *chain)
{
    sh_tasker_t *curr_chain = NULL;

    if (start == NULL || chain == NULL)
        return FUNC_FAILED;
    if (*start == NULL) {
        *start = chain;
        return FUNC_SUCCESS;
    }
    curr_chain = *start;
    for (; curr_chain->prog_pipes != NULL;
        curr_chain = curr_chain->prog_pipes);
    curr_chain->prog_pipes = chain;
    chain->prev = curr_chain;
    return FUNC_SUCCESS;
}

void sh_tasker_free(sh_tasker_t *chain)
{
    if (chain == NULL)
        return;
    free(chain->program);
    my_tabfree((void *) chain->args);
    sh_tasker_free(chain->prog_pipes);
    free(chain);
}

void sh_tasker_destroy(sh_tasker_t *chain)
{
    sh_tasker_t *next_chain = NULL;

    if (chain == NULL)
        return;
    while (chain != NULL) {
        next_chain = chain->next;
        sh_tasker_free(chain);
        chain = next_chain;
    }
}
