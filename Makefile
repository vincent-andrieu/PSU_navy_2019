##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC =   src/main.c			\
		src/navy.c			\
		src/map.c			\
		src/map_errors.c	\
		src/init.c			\
		src/send.c			\
		src/receive.c		\
		src/game.c			\
		src/attack.c		\
		src/defend.c

OBJ =   $(SRC:.c=.o)

NAME    =   navy

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

all:    $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@make clean -C lib/my/ --no-print-directory
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/my/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean