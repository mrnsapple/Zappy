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
#include "../fifo/utils/Utils.hpp"
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
		Player(int port, std::string name, std::string machine, std::string );
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
        //The player num given by server
        int _client_num;
        //The socket of the player
        int _socket_fd;
        //The fifo to comunicate with the client for create new player
        std::string _fifo_read;
        int _x;
        int _y;
        // Stuff for communicate with server
        Interact _interact;
        // Stuff for communicate with client
        Utils _utils;
};

#endif /* !andOriol */
