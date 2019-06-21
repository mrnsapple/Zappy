/*
** EPITECH PROJECT, 2019
** player created by
** File description:
** Mr.Luis
*/

#ifndef playerfile
#define playerfile
#include "Utils.hpp"
#include "Ai.hpp"
#include "Commands.hpp"
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
               
                int start_game();
	private:
                int     interactWithServer();
                std::vector<std::string> separate_string(std::string , char);
                int        setClientNumMapSpace(std::string read_from);
                int     createSocket();
                void     createCommands();
                void    createAi();
                int     welcomeInteraction();
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
                // Command for communicate with server
                Commands *_commands;
                //Ai for know what to do
                Ai *_ai;
                // Ai result value
                std::vector<std::string> _ai_result;

                //Inventory given by Inventory\n
                std::map<std::string, int> _inventory;
                //Info by sending Look\n
		std::vector<std::map<std::string, int>> _stuff_in_tiles;
                // Client number by connect_nbr\n
                int     _connect_nbr;
                //Level of player
                int _lvl;
        
                std::map<std::string, int> _gems_finding;

};

#endif /* !andOriol */
