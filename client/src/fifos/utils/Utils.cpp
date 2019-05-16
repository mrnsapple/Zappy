/*
** EPITECH PROJECT, 2019
** utils
** File description:
** bu pripo
*/

#include "Utils.hpp"
#include "../../../include/list.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{

}


bool	Utils::write_to_fd(std::string fifo, std::string to_write)
{
    int fd = open(fifo.c_str(), O_WRONLY, O_CREAT, O_TRUNC); 
    if (fd == -1) {
        std::cout << "error opening " << fifo << "\n";
        return false;
    }
    write(fd, to_write.c_str(), to_write.size());
    close (fd);
    return true;
}


std::string	Utils::read_from_fd(std::string fifo)
{
     char buf;
    std::string str;

    int fd = open(fifo.c_str(), O_RDONLY, O_CREAT, O_TRUNC); 
    if (fd == -1) {
        std::cout << "error opening " << fifo << "\n";
        return "";
    }
    // Read from FIFO 
    str.clear();        
    while (read(fd, &buf, 1) > 0 && buf != '\n' && buf != '\0') {
        str += buf;
        std::cout << "the strin:" << str;
    }
    close (fd);
    return str;
}

//template <class myType>

int Utils::num_charact(std::string &string, char character)
{
    int count = 0;

    for (auto a: string) {
        if (character == a)
            count++;
    }
    return count;
}
