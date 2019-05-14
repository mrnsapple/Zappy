/*
** EPITECH PROJECT, 2019
** client
** File description:
** Info about client
*/

#include "Client.hpp"

Client::Client()
{
    _machine = "localhost";
}

Client::~Client()
{
}


void    Client::setName(std::string name)
{
    _name = name;
}

void    Client::setPort(int port)
{
    _port = port;
}

void    Client::setMachine(std::string machine)
{
    _machine = machine;
}

int    Client::createSocket()
{
    struct sockaddr_in addr;

    std::cout << _machine << ", name: "<< _name << ", port:" <<_port;
    _socket_fd = socket(AF_INET, SOCK_STREAM, 0);
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

int     Client::interactWithServer()
{
    std::string write_to;
    
    write_to = _interact.readFromFd(_socket_fd);
    if (write_to.empty() || write_to.compare("WELCOME\n") < 0)
        return (84);
    std::cout << "write to:" << write_to;
    _name.append("\n");
    if (_interact.writeInFd(_socket_fd, _name) == -1)
        return (84);
    write_to = _interact.readFromFd(_socket_fd);
    if (write_to.empty())
        return (84);
    std::cout << "write to:" << write_to;
    return (0);
}
