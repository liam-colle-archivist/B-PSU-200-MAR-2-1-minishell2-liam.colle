##
## EPITECH PROJECT, 2024
## main
## File description:
## Makefile v5
##

## //> Project Data
## * Names

NAME = mysh

DEBUG = mysh_dbg

TNAME = unit_tests

## * Compiling - Paths (Sources)

SRC = $(wildcard *.c) $(shell find ./src/. -type f -name '*.c')

TOBJ = $(filter-out main.c,$(wildcard *.c)) \
	$(shell find ./src -type f -name '*.c')

TSRC = $(shell find ./tests/c_tests/ -type f -name '*.c')

LIBSRC := $(wildcard ./lib/*/)

## * Compiling - Paths (Objects)

OBJ = $(SRC:.c=.o)

## * Compiling - Flags

INCLPATH = include/

LIBFLGS = -L. -lmy -lstatutils -largparser

DBGFLGS = -Wall -Wextra -g3

CFLAGS = -Wall -Wextra -I$(INCLPATH) $(LIBFLGS)

TCFLGS = -lcriterion

## //> Scripts

## * Global Compilation

all: libs $(NAME)

dbg: dbg_libs $(DEBUG)

## * Global Compilation (Subtasks)

$(NAME): $(OBJ)
	@$(CC) $(SRC) -o $(NAME) $(CFLAGS)

$(DEBUG): $(OBJ)
	@$(CC) $(SRC) -o $(DEBUG) $(DBGFLGS) $(CFLAGS)

## * Lib Compilation

libs: $(LIBSRC)
	@for fld in $^ ; do $(MAKE) -C $$fld --no-print-directory ; done

dbg_libs: $(LIBSRC)
	@for fld in $^ ; do $(MAKE) -C $$fld CFLGS='$(DBGFLGS)' \
		--no-print-directory ; done

## * Cleaning

clean:
	@for fld in $(LIBSRC) ; do $(MAKE) clean -C $$fld \
		--no-print-directory ; done
	@$(RM) $(OBJ)
	@$(RM) unit_tests *.gc*
	@$(RM) vgcore*

fclean: clean
	@for fld in $(LIBSRC) ; do $(MAKE) fclean -C $$fld \
		--no-print-directory ; done
	@cd ./tests/shell_tester/; $(MAKE) fclean\
		PWD='$(PWD)/tests/shell_tester' --no-print-directory
	@$(RM) $(NAME)
	@$(RM) $(NAME)-noflags
	@$(RM) $(DEBUG)
	@$(RM) $(DEBUG)-noflags

## * Recompilation

re: fclean all

dbg_re: fclean dbg

## * Checks

style: fclean
	@../coding-style-checker/coding-style.sh ./
	@cat coding-style-reports.log
	@$(RM) -f coding-style-reports.log

## * Unit tests

tests_run: unit_tests
	@./unit_tests

unit_tests: re
	@cp $(NAME) ./tests/shell_tester/
	@$(MAKE) all -C ./tests/shell_tester/ PWD='$(PWD)/tests/shell_tester'\
		--no-print-directory
	@$(CC) $(TSRC) -o $(TNAME) $(TCFLGS) $(CFLGS) -I./include
