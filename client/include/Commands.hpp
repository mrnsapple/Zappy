/*
** EPITECH PROJECT, 2019
** commands 
** File description:
** by oriol
*/

#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_
#include "Utils.hpp"
#include <stdio.h>
#include <string.h>
#include <string>

#include <array>
#include <map>
#include <vector>
#include <algorithm>

class Commands {
	public:
		Commands(int socket_fd,
    		std::map<std::string, int> *inventory, 
 			std::map<std::string, int> *gems_finding,
			 std::vector<std::map<std::string, int>> *,
			 std::string);
		~Commands();
        // Send vector of mesages to server
		int sendCommands(std::vector<std::string>);

		
		//Retrieve inventory
		std::map<std::string, int>   getInventory();
		bool    tryCommands();
       std::vector<std::map<std::string, int>>    getLookArround();
        int    sendBroadcastText( std::string);
		int getConnectNbr();

	protected:
	private:
		int _socket_fd;
		std::map<std::string, int> _stuff_in_tile;
		std::vector<std::map<std::string, int>> *_stuff_in_tiles;

		std::map<std::string, int> *_inventory;
		std::map<std::string, int> *_gems_finding;
        
		std::string _fifo_read;

};

#endif /* !COMMANDS_HPP_ */
