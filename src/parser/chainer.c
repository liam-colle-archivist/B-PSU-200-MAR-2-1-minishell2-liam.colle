/*
** EPITECH PROJECT, 2025
** chainer
** File description:
** minishell2
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell/parser.h"
#include "utils.h"

sh_prsent_t *sh_prsent_create(char *entry, sh_prsent_type_t type)
{
    sh_prsent_t *new_chain = NULL;

    if (entry == NULL)
        return NULL;
    new_chain = malloc(sizeof(sh_prsent_t));
    if (new_chain == NULL)
        return NULL;
    new_chain->entry = entry;
    new_chain->type = type;
    new_chain->next = NULL;
    return new_chain;
}

int sh_prsent_chain(sh_prsent_t **start, sh_prsent_t *chain)
{
    sh_prsent_t *curr_chain = NULL;

    if (start == NULL || chain == NULL)
        return FUNC_FAILED;
    if (*start == NULL) {
        *start = chain;
        return FUNC_SUCCESS;
    }
    curr_chain = *start;
    for (; curr_chain->next != NULL; curr_chain = curr_chain->next);
    curr_chain->next = chain;
    return FUNC_SUCCESS;
}

void sh_prsent_free(sh_prsent_t *chain)
{
    if (chain == NULL)
        return;
    free(chain->entry);
    free(chain);
}

void sh_prsent_destroy(sh_prsent_t *chain)
{
    sh_prsent_t *next_chain = NULL;

    if (chain == NULL)
        return;
    while (chain != NULL) {
        next_chain = chain->next;
        sh_prsent_free(chain);
        chain = next_chain;
    }
}
