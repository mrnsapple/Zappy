/*
** EPITECH PROJECT, 2019
** commands 
** File description:
** by oriol
*/

#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_
#include "../../include/list.hpp"
#include "../utils/Utils.hpp"

class Commands {
	public:
		Commands(int);
		~Commands();
        
		
		//Retrieve inventory
		std::map<std::string, int>   getInventory();
		void    printInventoryItem(std::map<std::string, int> );
		void 	printStuffInTiles();
		bool    tryCommands();
       std::vector<std::map<std::string, int>>    getLookArround();
        int    sendBroadcastText( std::string);
		
	protected:
	private:
		int _socket_fd;
		std::map<std::string, int> _stuff_in_tile;
		std::vector<std::map<std::string, int>> _stuff_in_tiles;

		std::map<std::string, int> _inventory;

};

#endif /* !COMMANDS_HPP_ */
