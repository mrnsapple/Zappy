/*
** EPITECH PROJECT, 2019
** my_exception
** File description:
** exception
*/

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

//#include <iostream>
//#include <exception>
#include <string>
#include "../Colors/Colors.hpp"

class AException: public std::exception
{
	
    public:
        AException(std::string message) noexcept : _message(message)
       {
       };
       AException(){};
        //
        void    print_exception(void) {
           std::cerr << RED <<"Error:" << _message << RESET ;
        };
	protected:
       std::string _message;    
};

#endif /* !exception */
