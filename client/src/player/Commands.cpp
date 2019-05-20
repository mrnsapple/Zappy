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
    _stuff_in_tile = _inventory;
    _stuff_in_tile.insert(std::make_pair("player", 0));
    
}

Commands::~Commands()
{
}

bool    Commands::tryCommands()
{
    return true;
}

std::vector<std::map<std::string, int>>    Commands::getLookArround()
{
    std::string read_from;
    std::vector<std::string> vect_str;
    std::vector<std::string> vect_ptr;
    std::map<std::string, int> my_map;

    //Retrieve info
    read_from = Utils::writeInFd(_socket_fd, "Look\n");
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Inventory not recieved\n"), _stuff_in_tiles);
    // Parse result string
    read_from.erase(std::remove(read_from.begin(), read_from.end(), '['), read_from.end());
    read_from.erase(std::remove(read_from.begin(), read_from.end(), ']'), read_from.end());
    // Allocate in _stuff_in_tiles variable
    vect_str = Utils::separeteByChar(read_from, ',');
    for(std::string a: vect_str) {
        my_map = _stuff_in_tile;
        vect_ptr = Utils::separeteByChar(a, ' ');
        for(std::string b: vect_ptr) {
            std::map<std::string, int>::iterator it = _stuff_in_tile.find(b);
            if(it != _stuff_in_tile.end())
                my_map[b] = my_map[b] + 1;
            //std::cout << ":" << b << ":\n";      
        }
        _stuff_in_tiles.push_back(my_map);
    }    
    //std::cout << "read look:" << read_from << "\n";
    return (_stuff_in_tiles);
}

int Commands::getConnectNbr()
{
    std::string read_from;

    //Retrieve info
    read_from = Utils::writeInFd(_socket_fd, "Connect_nbr\n");
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Inventory not recieved\n"), -1);
    //std::cout << "read:" << read_from << "\n";
    return (std::stoi(read_from));
}

std::map<std::string, int>  Commands::getInventory()
{
    std::string read_from;
    std::vector<std::string> vect_str;
    std::vector<std::string> vect_ptr;

    //Retrieve info
    read_from = Utils::writeInFd(_socket_fd, "Inventory\n");
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Inventory not recieved\n"), _inventory);
    // Parse result string
    std::cout << "rad_form:" << read_from << "\n";
    read_from.erase(std::remove(read_from.begin(), read_from.end(), '['), read_from.end());
    read_from.erase(std::remove(read_from.begin(), read_from.end(), ']'), read_from.end());
    //std::cout << _socket_fd << " reads: "<< read_from << "\n";
    // Allocate in _inventory variable
    vect_str = Utils::separeteByChar(read_from, ',');
    for(std::string a: vect_str) {
        vect_ptr = Utils::separeteByChar(a, ' ');
        if (vect_ptr.size() == 3)
            _inventory[vect_ptr[1]] = std::stoi(vect_ptr[2]);
        //for(std::string b: vect_ptr)
        //    std::cout << ":" << b << ":\n";         
    }    
    return (_inventory);
}

int    Commands::sendBroadcastText( std::string text)
{
    std::string read_from;
    read_from = Utils::writeInFd(_socket_fd, "Broadcast " + text + "\n");
    //std::cout << "Player " << _client_num << "reads: "<< read_from << "\n";
    return (0);
}