/*
** EPITECH PROJECT, 2019
** player created by
** File description:
** Mr.Luis
*/

#ifndef playerfile
#define playerfile
#include "../../include/list.hpp"
#include "../Interact.hpp"
# include	<iostream>
# include	<string.h>
# include	<cstdlib>
# include	<unistd.h>
# include	<netdb.h>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<arpa/inet.h>

class Player {
	public:
		Player(int port, std::string name, std::string machine);
		~Player();
        int     createSocket();
        int     welcomeInteraction();
        int     interactWithServer();
        std::vector<std::string> separate_string(std::string , char);
        int        setClientNumMapSpace(std::string read_from);
        int start_game();
	protected:
	private:
        int _port;
        std::string _name;
        std::string _machine;

        int _socket_fd;
        int _client_num;
        int _x;
        int _y;

        Interact _interact;
        
};

#endif /* !andOriol */
