/*
** EPITECH PROJECT, 2019
** commands
** File description:
** by oriol
*/

#include "Commands.hpp"

Commands::Commands(int socket_fd) : _socket_fd(socket_fd)
{
    _inventory = { 
        {"food", 0},
        {"linemate", 0},
        {"dareumere", 0},
        {"sibur", 0},
        {"mediane", 0},
        {"phiras", 0},
        {"thystame", 0},
    };
}

Commands::~Commands()
{
}

bool    Commands::tryCommands()
{
    return true;
}

int    Commands::lookArround()
{
    return (0);
}

int    Commands::getInventory()
{
    std::string read_from;
    std::vector<std::string> vect_str;
    std::vector<std::string> vect_ptr;

    //Retrieve info
    read_from = Utils::writeInFd(_socket_fd, "Inventory\n");
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Inventory not recieved\n"), 84);
    // Parse result string
    std::cout << _socket_fd << " reads: "<< read_from << "\n";
    read_from.erase(std::remove(read_from.begin(), read_from.end(), '['), read_from.end());
    read_from.erase(std::remove(read_from.begin(), read_from.end(), ']'), read_from.end());
    std::cout << _socket_fd << " reads: "<< read_from << "\n";
    // Allocate in _inventory variable
    vect_str = Utils::separeteByChar(read_from, ',');
    for(std::string a: vect_str) {
        vect_ptr = Utils::separeteByChar(a, ' ');
        for(std::string b: vect_ptr)
            std::cout << ":" << b << ":\n"; 
    }    
    return (0);
}

int    Commands::sendBroadcastText( std::string text)
{
    std::string read_from;
    read_from = Utils::writeInFd(_socket_fd, "Broadcast " + text + "\n");
    //std::cout << "Player " << _client_num << "reads: "<< read_from << "\n";
    return (0);
}

int		Commands::executeCommands()
{
    getInventory();
    return (0);
}