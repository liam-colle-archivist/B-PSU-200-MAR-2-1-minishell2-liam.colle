##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## minishell1 (Shell Tester)
##

NAME = mysh

all:
	@$(CC) ./my_segfault_source/main.c -o my_segfault -w
	@$(CC) ./my_divzero_source/main.c -o my_divzero -w
	@cp ./my_divzero ./example_files/perm_err/my_divzero
	@chmod -x ./example_files/perm_err/my_divzero
	@./tester.sh

fclean:
	@$(RM) $(NAME)
	@$(RM) my_divzero my_segfault ./example_files/perm_err/my_divzero
