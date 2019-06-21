/*
** EPITECH PROJECT, 2019
** main
** File description:
** by oriol
*/

#include "../include/Parser.hpp"
#include "../include/Client.hpp"
#include "../include/Colors/Colors.hpp"
#include "../include/Errors/ClientException.hpp"
#include "../include/Errors/GlovalException.hpp"

Client *get_client(int ac, char **av)
{
    std::unique_ptr<Parser> client_parser(new Parser(ac, av));

    return (client_parser->get_binary_info());
}

int     client_creation(int ac, char **av)
{
    Client *my_client = get_client(ac, av);
    int result;
    try {   
        if (my_client == NULL)
            return (84);    
        result = my_client->startClient(); 
    } catch ( ClientException& e) {
       e.print_exception();
    }
    return (result);
}

int main(int ac, char **av)
{
    try {   
        return (client_creation(ac, av));
    }
    catch ( GlovalException& e) {
       e.print_exception();
    }
}