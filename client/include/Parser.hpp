/*
** EPITECH PROJECT, 2019
** parser
** File description:
** Info about parser 
*/

#include "Client.hpp"
#include "Exception.hpp"
#ifndef MyParser_HPP
#define MyParser_HPP

class Parser {
	public:
		Parser(int , char **);
		~Parser();
        Client *get_binary_info(void);

	protected:
	private:
		int _ac;
		char **_av;
};

#endif /* !d */
