/*
** EPITECH PROJECT, 2019
** parser
** File description:
** Info about parser 
*/

#include "../../include/list.hpp"
#include "../client/Client.hpp"
#ifndef MyParser
#define MyParser

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
