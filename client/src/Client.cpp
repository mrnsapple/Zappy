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
    std::string str;

    _fifo_read = createFifo("client/src/fifos/read/myfifo");
    std::cout << "The fifo read:" << _fifo_read << "\n";
    createPlayer();
    while (23232) {
        str = _utils.read_from_fd(_fifo_read);
        std::cout << "the str:" << str << "\n";
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