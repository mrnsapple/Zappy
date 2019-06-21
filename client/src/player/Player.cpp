/*
** EPITECH PROJECT, 2019
** player file
** File description:
** the player file created by luiso
*/

#include "../../include/Player.hpp"
#include "../../include/Exception.hpp"

Player::Player(int port, std::string name, std::string machine, std::string fifo_read) :
    _port(port), _name(name), _machine(machine), _fifo_read(fifo_read), _lvl(0)
{
    _gems_finding = { 
        {"dareumere", 0},
        {"linemate", 1},
        {"sibur", 0},
        {"mediane", 0},
        {"phiras", 0},
        {"thystame", 0},
    };
    _inventory = _gems_finding;
    _inventory.insert(std::make_pair("food", 0));
    //_stuff_in_tiles = _inventory;
    //_stuff_in_tiles.insert(std::make_pair("player", 0));
}


Player::~Player()
{
}


std::vector<std::string> Player::separate_string(std::string str, char character)
{
    std::stringstream test(str);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(test, segment, character)) {
        seglist.push_back(segment);
    }
    return seglist;
}

int    Player::createSocket()
{
    struct sockaddr_in addr;
    int nm = 1;

    std::cout << _machine << ", name: "<< _name << ", port:" <<_port;
    _socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket_fd == -1)
        throw MyException("Error creating socket\n");
    if (setsockopt(_socket_fd, SOL_SOCKET, SO_REUSEADDR, &nm, sizeof(nm)) < 0)
        throw MyException("Error settting sockopt\n");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(_port);
    addr.sin_addr.s_addr = inet_addr(_machine.c_str());
    int c = connect(_socket_fd, (const struct sockaddr *)&addr, sizeof(addr));
    if (c == -1) {
      std::cerr << "Error on connect" << std::endl;
      return (-1);
    }
    return (0);
}

int     Player::welcomeInteraction()
{
    std::string read_from;

    std::cout <<"Start reading form server\n";
    read_from = Utils::readFromFd(_socket_fd);
    std::cout << read_from << "\n"; 
    if (read_from.empty() || strcmp(read_from.c_str(), "WELCOME\n") != 0)
        return (perror("Server didn't answer Welcome"), 84);
    std::cout << "write to:" << read_from;
    _name.append("\n");
    read_from = Utils::writeInFd(_socket_fd, _name, true);
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Team name sent is not valid"), 84);
    setClientNumMapSpace(read_from); 
    return (0);   
}

void     Player::createCommands()
{
    _commands = new Commands(_socket_fd, &_inventory, &_gems_finding, &_stuff_in_tiles, _fifo_read);
}

void     Player::createAi()
{
    _ai = new Ai(&_inventory, &_stuff_in_tiles, &_gems_finding);
}


int    Player::setClientNumMapSpace(std::string read_from)
{
    std::vector<std::string> vect;
    
    vect = separate_string(read_from, '\n');
    //for (std::string a : vect)
    //    std::cout << "a:" << a << ":\n";
    _client_num = std::stoi(vect[0]);
    vect = separate_string(vect[1], ' ');
    _y = std::stoi(vect[1]);
    std::cout << "write to:" << read_from;
    return (0);

}

int     Player::interactWithServer()
{
    std::cout << "Start server interact:" << _socket_fd << "\n";
    _connect_nbr = _commands->getConnectNbr();
    for (int val = 0; val == 0; val = 0) {        
        //sleep(0.7);
        _commands->getInventory();
        std::cout  << "\nPrint Inventory:\n";
        Utils::printMap(_inventory);
        _commands->getLookArround();
        std::cout << "\n\nConnect nbr:" << _connect_nbr <<"," << _socket_fd<< "\n";
        Utils::printVectorMap(_stuff_in_tiles);
        //_inventory["food"]--;
    
        _ai_result = _ai->get_what_to_do();
        _commands->sendCommands(_ai_result);
        Utils::printMap(_commands->getInventory());
        
    }
    return (0);
}

int     Player::start_game()
{
    std::string read_from;

    std::cout << "Start game\n";
    createSocket();
    welcomeInteraction();
    createCommands();
    createAi();
    interactWithServer();
    return (0);
}