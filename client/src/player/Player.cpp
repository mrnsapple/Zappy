/*
** EPITECH PROJECT, 2019
** player file
** File description:
** the player file created by luiso
*/

#include "Player.hpp"

Player::Player(int port, std::string name, std::string machine) :
    _port(port), _name(name), _machine(machine)
{
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

int     Player::welcomeInteraction()
{
    std::string read_from;

    read_from = _interact.readFromFd(_socket_fd);
    if (read_from.empty() || strcmp(read_from.c_str(), "WELCOME\n") != 0)
        return (perror("Server didn't answer Welcome"), 84);
    std::cout << "write to:" << read_from;
    _name.append("\n");
    read_from = _interact.writeInFd(_socket_fd, _name);
    if (read_from.empty() || strcmp(read_from.c_str(),"ko\n") == 0)
        return (perror("Team name sent is not valid"), 84);
    setClientNumMapSpace(read_from); 
    return (0);   
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
    std::string read_from;
    std::cout << "Start server interact\n";
    //std::vector<std::string> = [""]
    while (445050404.333) {
        read_from = _interact.writeInFd(_socket_fd, "Look\n");
        std::cout << "read:" << read_from;
    }
    return (0);
}

int     Player::start_game()
{
    return (0);
}
