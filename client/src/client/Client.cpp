/*
** EPITECH PROJECT, 2019
** client
** File description:
** Info about client
*/

#include "../../include/Client.hpp"
#include "../../include/Exception.hpp"

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
    if (strcmp(machine.c_str(), "localhost") == 0)
        _machine = "127.0.0.1";
}

int     Client::startClient()
{
    std::string read_from;

    _fifo_read = createFifo("client/src/fifos/read/myfifo");
    std::cout << "The fifo read:" << _fifo_read << "\n";
    createPlayer();
    //createPlayer();

    while (23232) {
        sleep(1);
        read_from = Utils::readFromFifo(_fifo_read);
        std::cout << "Client read from player:" << read_from << "\n";
        if (strcmp(read_from.c_str(), "Create a player\n") == 0)
            createPlayer();
    }
    return (0);
}

int     Client::createPlayer()
{
    pid_t pid;
    Player *my_player = new Player(_port, _name, _machine, _fifo_read);

    _players.push_back(my_player);
    pid = fork();
    if (pid < 0) {
        delete my_player;
        throw MyException("Fork result is < 0\n");
    }
    else if (pid == 0) {
        my_player->start_game();
        delete my_player;
        throw MyException("Player died\n");
    }
    return (0);
}


std::string Client::createFifo(std::string file)
{
    if (mkfifo(file.c_str(), 0666) == -1)
        throw MyException("Mkfifo of " + file + " failed\n");
    return file;
}