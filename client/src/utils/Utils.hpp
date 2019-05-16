/*
** EPITECH PROJECT, 2019
** utilz
** File description:
** bu prop
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_
#include "../../include/list.hpp"
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class Utils {
	public:
		int num_charact(std::string &string, char character);
		static std::string	readFromFifo(std::string fifo);
		static bool	writeToFifo(std::string fifo, std::string);

		static std::string readFromFd(int );
        static std::string writeInFd(int , std::string);
		Utils();
		~Utils();    
};


#endif /* !UTILS_HPP_ */
