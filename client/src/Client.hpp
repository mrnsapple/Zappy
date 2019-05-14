/*
** EPITECH PROJECT, 2019
** Client
** File description:
** Info about client
*/

# include "Interact.hpp"
#ifndef MyClient
#define MyClient
# include "../include/list.hpp"
# include	<iostream>
# include	<string.h>
# include	<cstdlib>
# include	<unistd.h>
# include	<netdb.h>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<arpa/inet.h>

class Client {
	public:
		Client();
		~Client();
        void    setName(std::string);
        void    setPort(int);
        void    setMachine(std::string);
        int     createSocket();
        int     interactWithServer();
	protected:
	private:
        int _port;
        int _socket_fd;
        int _client_num;
        int _x;
        int _y;
        std::string _name;
        std::string _machine;

        Interact _interact;
};

#endif /* !d */
