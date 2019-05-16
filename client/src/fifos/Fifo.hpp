/*
** EPITECH PROJECT, 2019
** CCP_plazza_2018
** File description:
** Fifo
*/

#ifndef FIFO_HPP_
#define FIFO_HPP_

#include <string>
#include <sys/stat.h>
#include <sys/types.h>

class Fifo {
public:
    Fifo();
    ~Fifo();
    void    set(std::string my_fifo) {
        _fifo = my_fifo;
        mkfifo(_fifo.c_str(), 0666);
    }
    std::string get() { return _fifo; }

protected:
private:
    std::string _fifo;
};

#endif /* !FIFO_HPP_ */
