/*
** EPITECH PROJECT, 2025
** parser (Shell)
** File description:
** minishell1
*/

#include <stdio.h>
#include "config/data.h"

#ifndef SH_PARSER_H
    #define SH_PARSER_H

int sh_parse_entry(shell_data_t *shell_data);

#endif

#ifndef SH_PARSER_GET_H
    #define SH_PARSER_GET_H

char *sh_get_entry(FILE *file);
int sh_get_prsent_len(sh_prsent_t *chain);
int sh_get_prsent_eltslen(sh_prsent_t *chain);
char *sh_get_prsent_index(sh_prsent_t *chain, int index);

#endif

#ifndef SH_PARSER_CHAINER_H
    #define SH_PARSER_CHAINER_H

sh_prsent_t *sh_prsent_create(char *entry, sh_prsent_type_t type);
int sh_prsent_chain(sh_prsent_t **start, sh_prsent_t *chain);
void sh_prsent_free(sh_prsent_t *chain);
void sh_prsent_destroy(sh_prsent_t *chain);

#endif

#ifndef SH_PARSER_CONVERTER_H
    #define SH_PARSER_CONVERTER_H

char *sh_prsent_to_char_ptr(sh_prsent_t *chain);
char **sh_prsent_to_char_tab(sh_prsent_t *chain);

#endif
