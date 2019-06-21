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


class MyException// : public std::exception
{
	
    public:
        MyException(std::string message) noexcept : _message(message)
       {
       }
        //
        void    print_exception(void) {
           std::cout << "Error:" << _message << std::endl;
        };
	protected:
	private:       
       std::string _message;
    
};

#endif /* !exception */
