/*
** EPITECH PROJECT, 2019
** my_exception
** File description:
** exception
*/

#ifndef CLIENTEXCEPTION_HPP
#define CLIENTEXCEPTION_HPP

//#include <iostream>
//#include <exception>
#include "AException.hpp"

#include <string>

class ClientException : public AException
{
    public:
        ClientException(std::string message) noexcept
        {
            _message = (message);
   
        };
};

#endif /* !exception */
