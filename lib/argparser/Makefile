##
## EPITECH PROJECT, 2024
## libargparser
## File description:
## Lib Makefile v3
##

NAME = libargparser.a

INCLUDE = argparser.h

INCL_PATH = ../../include/

SRC = $(shell find . -type f -name '*.c')

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@cp $(NAME) ../../$(NAME)
	@cp $(INCLUDE) $(INCL_PATH)$(INCLUDE)

clean:
	@$(RM) $(OBJ)
	@$(RM) *.gch
	@$(RM) $(INCL_PATH)$(INCLUDE)

fclean: clean
	@$(RM) ../../$(NAME)
	@$(RM) $(NAME)

re: fclean all
