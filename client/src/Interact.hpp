/*
** EPITECH PROJECT, 2019
** interact
** File description:
** Info about interact
*/

#ifndef MyInteract    
#define MyInteract
#include "../include/list.hpp"

class Interact {
	public:
		Interact();
		~Interact();
        std::string readFromFd(int );
        int writeInFd(int , std::string);

	protected:
	private:
};

#endif /* !d */
