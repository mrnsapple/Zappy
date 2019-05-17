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
#include "Inventory.hpp"

class Commands {
	public:
		Commands(int);
		~Commands();
        
		//Call all commands
		int		executeCommands();
		//Retrieve inventory
		int    getInventory();
		int    setInventoryItem();
		
		bool    tryCommands();
        int    lookArround();
        int    sendBroadcastText( std::string);
		
	protected:
	private:
		int _socket_fd;
		
		std::map<std::string, int> _inventory;

};

#endif /* !COMMANDS_HPP_ */
