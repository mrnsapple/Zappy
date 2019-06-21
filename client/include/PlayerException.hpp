/*
** EPITECH PROJECT, 2019
** my_exception
** File description:
** exception
*/

#ifndef PLAYEREXCEPTION_HPP
#define PLAYEREXCEPTION_HPP

//#include <iostream>
//#include <exception>
#include "Exception.hpp"

#include <string>

class PlayerException : public MyException
{
    public:
        PlayerException(std::string message) noexcept
        {
            _message = (message);
   
        };
};

#endif /* !exception */
