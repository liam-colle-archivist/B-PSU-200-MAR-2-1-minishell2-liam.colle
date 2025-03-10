##
## EPITECH PROJECT, 2024
## fs_utils
## File description:
## Makefile v2
##

NAME = libfsutils.a

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@cp $(NAME) ../../$(NAME)
	@cp fs_utils.h ../../include/fs_utils.h

clean:
	@$(RM) $(OBJ)
	@$(RM) *.gch
	@$(RM) ../../include/fs_utils.h

fclean: clean
	@$(RM) ../../$(NAME)
	@$(RM) $(NAME)

re: fclean all
