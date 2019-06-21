/*
** EPITECH PROJECT, 2019
** utils
** File description:
** bu pripo
*/

#include "../../include/Utils.hpp"
#include "../../include/Exception.hpp"

Utils::Utils()
{
}

Utils::~Utils()
{

}

void    Utils::printMap(std::map<std::string, int> inventory)
{
    std::map<std::string, int>::iterator it = inventory.begin();
    
    std::cout << "Start printing\n";
    while(it != inventory.end()) {
        std::cout<<it->first<<" :: "<<it->second << ", ";
        it++;
    }
    std::cout << std::endl;
}

void 	Utils::printVectorMap(std::vector<std::map<std::string, int>>  _stuff_in_tiles)
{
    for(auto a: _stuff_in_tiles) {
        printMap(a);
    }

}

 bool	Utils::writeToFifo(std::string fifo, std::string to_write)
{
    int fd = open(fifo.c_str(), O_WRONLY, O_CREAT, O_TRUNC); 
    if (fd == -1) {
        throw MyException("Error opening " + fifo + "\n");
        return false;
    }
    write(fd, to_write.c_str(), to_write.size());
    close (fd);
    return true;
}


 std::string	Utils::readFromFifo(std::string fifo)
{
     char buf;
    std::string str;

    int fd = open(fifo.c_str(), O_RDONLY, O_CREAT, O_TRUNC); 
    if (fd == -1) {
        throw MyException("Error opening " + fifo + "\n");
        return "";
    }
    // Read from FIFO 
    str.clear();        
    while (read(fd, &buf, 1) > 0 && buf != '\n' && buf != '\0') {
        str += buf;
    }
    close (fd);
    return str;
}

//template <class myType>

template<typename T,typename T2>

int Utils::num_charact(T &string, T2 character)
{
    int count = 0;

    for (T2 a: string) {
        if (character == a)
            count++;
    }
    return count;
}


std::string Utils::readFromFd(int fd)
{
    std::string write_to;
    
    write_to.resize(1000);
    if (read(fd, (void *)write_to.c_str(), 1000) == -1) {
        (write_to.clear());
        return (write_to);
    }
    return (write_to);
}

std::string Utils::writeInFd(int fd, std::string message, bool read_to)
{
    std::string str;

    str.clear();
    if (write(fd, message.c_str(), message.length()) == -1)
        return (str);
    else if (read_to == true) {
        str = readFromFd(fd);
        return (str);
    }
    return ("END\n");
}

std::vector<std::string> Utils::separeteByChar(std::string str, char character)
{
    std::stringstream test(str);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(test, segment, character))
    {
        seglist.push_back(segment);
    }
    return seglist;
}