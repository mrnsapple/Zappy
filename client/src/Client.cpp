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

int     Client::startClient()
{
    _fifo_read = createFifo("fifos/read/myfifo");

    createPlayer();
    while (23232) {
    }
    //my_client->welcomeInteraction() != 0 ||
    //my_client->interactWithServer() != 0)
    return (0);
}

int     Client::createPlayer()
{
    pid_t pid;
    Player *my_player = new Player(_port, _name, _machine, _fifo_read);

    _players.push_back(my_player);
    pid = fork();
    if (pid < 0) {
        perror("Error when fork\n");
        exit(84);
    }
    else if (pid == 0) {
        my_player->start_game();
        exit(0);
    }
    return (0);
}


std::string Client::createFifo(std::string file)
{
    if (mkfifo(file.c_str(), 0666) == -1)
        return file;
    return file;
}