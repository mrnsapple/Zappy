##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Oscar
##

#ifndef _MAKE_
#define _MAKE_

SRC =	map_grafic.c

OBJ =	$(SRC:.c=.o)

NAME =	sappy

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lSDL2main -lSDL2 

clean:
	rm -f *.o

fclean:	clean

	rm -f $(NAME)

re:	fclean all

#endif
