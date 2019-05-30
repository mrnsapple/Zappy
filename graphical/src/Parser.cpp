/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Parser
*/

#include "../include/Parser.hpp"

Parser::Parser(int argc, char **argv)
{
    _argc = argc;
    _args = std::vector<std::string>(argv, argv + argc);

    for (auto a : _args)
        std::cout << a << std::endl;
}

Parser::~Parser()
{
}
