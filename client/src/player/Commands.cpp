/*
** EPITECH PROJECT, 2019
** commands
** File description:
** by oriol
*/

#include "../../include/Commands.hpp"
#include "../../include/Errors/UtilsException.hpp"
Commands::Commands(int socket_fd,
    std::map<std::string, int> *inventory, 
 std::map<std::string, int> *gems_finding,
 std::vector<std::map<std::string, int>> *stuff_in_tiles,
 std::string fifo_read) :
  _socket_fd(socket_fd), _fifo_read(fifo_read)
{
    _inventory = inventory;
    _gems_finding = gems_finding;
    _stuff_in_tiles = stuff_in_tiles;
    _stuff_in_tile = *_inventory;
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
    (*_stuff_in_tiles).clear();
    //Retrieve info

    read_from = Utils::writeInFd(_socket_fd, "Look\n", true);
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("look not recieved\n"), *_stuff_in_tiles);
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
            if(it != (_stuff_in_tile).end())
                my_map[b] = my_map[b] + 1;
        }
        (*_stuff_in_tiles).push_back(my_map);
    }    
    //std::cout << "read look:" << read_from << "\n";
    return (*_stuff_in_tiles);
}

int Commands::getConnectNbr()
{
    std::string read_from;

    //Retrieve info
    read_from = Utils::writeInFd(_socket_fd, "Connect_nbr\n", true);
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Connect nbr not recieved\n"), -1);
    Utils::printMessage(GREEN, "COMMANDS", "The ConnectNbr retrieved is " + read_from);
    return (std::stoi(read_from));
}

std::map<std::string, int>  Commands::getInventory()
{
    std::string read_from;
    std::vector<std::string> vect_str;
    std::vector<std::string> vect_ptr;

    //Retrieve info
    read_from = Utils::writeInFd(_socket_fd, "Inventory\n", true);
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Inventory not recieved\n"), *_inventory);
    // Parse result string
    Utils::printMessage(GREEN, "COMMANDS", "The Inventory retrieved is " + read_from);
    read_from.erase(std::remove(read_from.begin(), read_from.end(), '['), read_from.end());
    read_from.erase(std::remove(read_from.begin(), read_from.end(), ']'), read_from.end());
    //std::cout << _socket_fd << " reads: "<< read_from << "\n";
    // Allocate in _inventory variable
    vect_str = Utils::separeteByChar(read_from, ',');
    for(std::string a: vect_str) {
        vect_ptr = Utils::separeteByChar(a, ' ');
        if (vect_ptr.size() == 3)
            (*_inventory)[vect_ptr[1]] = std::stoi(vect_ptr[2]);
        //for(std::string b: vect_ptr)
        //    std::cout << ":" << b << ":\n";         
    }    
    return (*_inventory);
}

int Commands::sendCommands(std::vector<std::string> message_vector)
{   
    std::string read_from;
    
    //Retrieve info
    for (auto message : message_vector) {
        if (strcmp(message.c_str(), "Fork\n") == 0) {
            try {
                Utils::writeToFifo(_fifo_read, "Create a player\n");
            } catch ( UtilsException &e) {
                 e.print_exception();
            }
        }
        Utils::printMessage(GREEN, "COMMANDS", "Message sent to server is :" + message);
        read_from = Utils::writeInFd(_socket_fd, message, true);
        Utils::printMessage(GREEN, "COMMANDS", "Message recieved from server is " + read_from);
    }
    return (0);
}

int    Commands::sendBroadcastText( std::string text)
{
    std::string read_from;
    read_from = Utils::writeInFd(_socket_fd, "Broadcast " + text + "\n", true);
    return (0);
}