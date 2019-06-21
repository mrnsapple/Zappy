/*
** EPITECH PROJECT, 2019
** parser
** File description:
** Info about parser
*/

#include "../../include/Parser.hpp"

Parser::Parser(int ac, char **av)
{
    _ac = ac;
    _av = av;
}

Parser::~Parser()
{
}

Client *Parser::get_binary_info(void)
{
    Client *my_client = new Client();
    std::string value;
    
    if (_ac != 7 || _av == NULL)
        return NULL;
    for (int i = 0; _av[i] != NULL && _av[i + 1] != NULL; i++) {
        value = _av[i];
        if (value.compare("-n") == 0)
            my_client->setName(_av[i + 1]);
        else if (value.compare("-p") == 0 &&
                (std::string(_av[i + 1])).find_first_not_of("0123456789") == (size_t)-1)
            my_client->setPort(std::stoi(_av[i + 1]));
        else if (value.compare("-h") == 0 &&
                (std::string(_av[i + 1])).find_first_not_of("0123456789.") == (size_t)-1)
            my_client->setMachine(_av[i + 1]);

    }
    return my_client;
}