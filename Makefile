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

SRC =	$(CLIENT_PATH)main.cpp 						\
		$(CLIENT_PATH)parser/Parser.cpp				\
		$(CLIENT_PATH)client/Client.cpp				\
		$(CLIENT_PATH)$(COMMANDS)Commands.cpp		\
		$(CLIENT_PATH)$(COMMANDS)Player.cpp			\
		$(CLIENT_PATH)$(COMMANDS)Ai.cpp				\
		$(CLIENT_PATH)utils/Utils.cpp

SERVSRC	=	$(SERVER_PATH)main.c					\
			$(SERVER_PATH)client_interaction/client_management.c	\
			$(SERVER_PATH)client_interaction/client_interaction.c	\
			$(SERVER_PATH)client_interaction/instructions.c			\
			$(SERVER_PATH)client_interaction/look.c					\
			$(SERVER_PATH)client_interaction/take.c					\
			$(SERVER_PATH)client_interaction/delete_client.c		\
			$(SERVER_PATH)client_interaction/forward.c				\
			$(SERVER_PATH)error_management.c			\
			$(SERVER_PATH)fd_management.c				\
			$(SERVER_PATH)get_arguments.c				\
			$(SERVER_PATH)init_server.c					\
			$(SERVER_PATH)start_server.c				\
			$(SERVER_PATH)map_creation/create_map.c 	\
			$(SERVER_PATH)grafic_motor/map_grafic.c		\
			$(SERVER_PATH)grafic_motor/rect_sdl.c		\
			$(SERVER_PATH)grafic_motor/rect_map.c		\
			$(SERVER_PATH)grafic_motor/color_sdl.c

OBJ	=	$(SRC:.cpp=.o)

SERVOBJ	=	$(SERVSRC:.c=.o)

NAME	=	zappy_ai

SERVNAME =	zappy_server

all	:	$(NAME) $(SERVNAME)

rmfifo: 
	rm -rf client/src/fifos/read/myfifo

$(NAME)	:	rmfifo $(OBJ)
	g++ -g -Wall -Wextra -o $(NAME) $(SRC)

$(SERVNAME)	:	$(SERVOBJ)
	gcc -g -Wall -Wextra  -o $(SERVNAME) $(SERVSRC) -lSDL2main -lSDL2

clean:
	rm -rf $(OBJ)
	rm -rf $(SERVOBJ)

fclean:	clean
	rm -rf $(NAME)
	rm -rf $(SERVNAME)
	rm -rf *~ *# *.o

re:	fclean all
