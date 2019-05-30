/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <vector>
#include <iostream>

class Parser {
public:
    Parser(int argc, char **argv);
    ~Parser();

protected:
private:
    std::vector<std::string>    _args;
    int _argc;
};

#endif /* !PARSER_HPP_ */
