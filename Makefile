##
## EPITECH PROJECT, 2019
## OOP_arcade_2018
## File description:
## Makefile
##

CLIENT_PATH = client/src/

SERVER_PATH = server/src/

COMMANDS = player/

FIFO = fifos/utils/

SRC =	$(CLIENT_PATH)main.cpp 					\
		$(CLIENT_PATH)Parser.cpp				\
		$(CLIENT_PATH)Client.cpp				\
		$(CLIENT_PATH)Interact.cpp				\
		$(CLIENT_PATH)$(COMMANDS)Commands.cpp	\
		$(CLIENT_PATH)$(COMMANDS)Player.cpp		\
		$(CLIENT_PATH)$(FIFO)Utils.cpp

SERVSRC	=	$(SERVER_PATH)main.c	\
			$(SERVER_PATH)error_management.c

OBJ	=	$(SRC:.cpp=.o)

SERVOBJ	=	$(SERVSRC:.c=.o)

NAME	=	zappy_ai

SERVNAME =	zappy_server

all	:	$(NAME) $(SERVNAME)

rmfifo: 
	rm -rf client/src/fifos/read/myfifo

$(NAME)	:	rmfifo $(OBJ)
	g++ -g -Wall -Wextra -o $(NAME) $(SRC)

	gcc -g -Wall -Wextra -Werror -o $(SERVNAME) $(SERVSRC)

clean:
	rm -rf $(OBJ)
	rm -rf $(SERVOBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(SERVNAME)
	rm -rf *~ *# *.o

re:	fclean all
