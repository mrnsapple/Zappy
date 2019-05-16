##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

CLIENT_PATH = client/src/

COMMANDS = player/

FIFO = fifos/utils/

SRC =	$(CLIENT_PATH)main.cpp 					\
		$(CLIENT_PATH)Parser.cpp				\
		$(CLIENT_PATH)Client.cpp				\
		$(CLIENT_PATH)Interact.cpp				\
		$(CLIENT_PATH)$(COMMANDS)Commands.cpp	\
		$(CLIENT_PATH)$(COMMANDS)Player.cpp		\
		$(CLIENT_PATH)$(FIFO)Utils.cpp




OBJ	=	$(SRC:.cpp=.o)

	

NAME	=	zappy_ai

all	:	$(NAME)

#rmfifo: 
#	rm -rf client/src/fifos/read/myfifo

$(NAME)	:	$(OBJ)
	#g++ -g -Werror -Wall -Wextra -o $(NAME) $(SRC)
	g++ -g -Wall -Wextra -o $(NAME) $(SRC)

clean:
	rm -rf $(LIBOBJ)
	rm -rf $(GAMESOBJ)
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME) *~ *# *.o
	rm -rf lib/*.so
	rm -rf games/*.so

re:	fclean all
