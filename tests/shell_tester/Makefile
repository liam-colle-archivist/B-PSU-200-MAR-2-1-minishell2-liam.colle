##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## minishell1 (Shell Tester)
##

NAME = mysh

all:
	@$(CC) $(PWD)/my_segfault_source/main.c -o $(PWD)/my_segfault -w
	@$(CC) $(PWD)/my_divzero_source/main.c -o $(PWD)/my_divzero -w
	@cp $(PWD)/my_divzero $(PWD)/example_files/perm_err/my_divzero
	@chmod -x $(PWD)/example_files/perm_err/my_divzero
	@./tester.sh

fclean:
	@$(RM) $(NAME)
	@$(RM) $(PWD)/my_divzero $(PWD)/my_segfault $(PWD)/example_files/perm_err/my_divzero
