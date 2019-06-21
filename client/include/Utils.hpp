/*
** EPITECH PROJECT, 2019
** utilz
** File description:
** bu prop
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unistd.h>

//Types
#include <string>
#include <list>
#include <array>
#include <map>
#include <vector>

class Utils {
	public:
		template<typename T,typename T2>

		int num_charact(T &string, T2 character);
		
		//fifo interactions
		static std::string	readFromFifo(std::string fifo);
		static bool	writeToFifo(std::string fifo, std::string);
		//file descriptor interactions
		static std::string readFromFd(int );
        static std::string writeInFd(int , std::string, bool);

		static std::vector<std::string> separeteByChar(std::string str, char character);

		static void 	printVectorMap(std::vector<std::map<std::string, int>>);
		static void    printMap(std::map<std::string, int>);


		Utils();
		~Utils();    
};


#endif /* !UTILS_HPP_ */
