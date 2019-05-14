/*
** EPITECH PROJECT, 2019
** interact 
** File description:
** Info about interact
*/

#include "Interact.hpp"

Interact::Interact()
{
}

Interact::~Interact()
{
}

std::string Interact::readFromFd(int fd)
{
    std::string write_to;
    
    write_to.resize(100);
    if (read(fd, (void *)write_to.c_str(), 100) == -1) {
        (write_to.clear());
        return (write_to);
    }
    return (write_to);
}

int Interact::writeInFd(int fd, std::string message)
{
    return (write(fd, message.c_str(), message.length()));
    
}