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
	@cp $(PWD)/my_divzero $(PWD)/my_divzero_permfault
	@chmod -x $(PWD)/my_divzero_permfault
	@./tester.sh > test_results
	@echo === SUCCESSFUL TESTS ===
	@grep --color=never "OK" test_results; true
	@echo === FAILED TESTS ===
	@grep --color=never "KO" test_results; true
	@echo === END OF LOG ===
# @grep -q "KO" test_results && exit 1 || true

fclean:
	@$(RM) $(NAME)
	@$(RM) out_test test_results
	@$(RM) $(PWD)/my_divzero $(PWD)/my_segfault\
		$(PWD)/my_divzero_permfault
