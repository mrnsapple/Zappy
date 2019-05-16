/*
** EPITECH PROJECT, 2019
** main
** File description:
** by oriol
*/

#include "Parser.hpp"

Client *get_client(int ac, char **av)
{
    Parser *client_parser = new Parser(ac, av);

    return (client_parser->get_binary_info());
}

int     client_creation(int ac, char **av)
{
    Client *my_client = get_client(ac, av);

    if (my_client == NULL)
        return (84);
    return (my_client->startClient());
}

int main(int ac, char **av)
{
    try {
        return (client_creation(ac, av));
    }
    catch ( int e ) {
        std::cout << "Error:" << e << "\n";
    }
}