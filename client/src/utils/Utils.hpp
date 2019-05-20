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
		
		//fifo interactions
		static std::string	readFromFifo(std::string fifo);
		static bool	writeToFifo(std::string fifo, std::string);
		//file descriptor interactions
		static std::string readFromFd(int );
        static std::string writeInFd(int , std::string);

		static std::vector<std::string> separeteByChar(std::string str, char character);

		static void 	printVectorMap(std::vector<std::map<std::string, int>>);
		static void    printMap(std::map<std::string, int>);


		Utils();
		~Utils();    
};


#endif /* !UTILS_HPP_ */
