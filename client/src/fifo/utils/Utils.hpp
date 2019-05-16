/*
** EPITECH PROJECT, 2019
** utilz
** File description:
** bu prop
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_
#include "../../../include/list.hpp"
 #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class Utils {
	public:
		int num_charact(std::string &string, char character);
		std::string	read_from_fd(std::string fifo);
		bool	write_to_fd(std::string fifo, std::string);

		Utils();
		~Utils();    
};


#endif /* !UTILS_HPP_ */
