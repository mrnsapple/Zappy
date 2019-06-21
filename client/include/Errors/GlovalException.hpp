/*
** EPITECH PROJECT, 2019
** my_exception
** File description:
** exception
*/

#ifndef GLOVALEXCEPTION_HPP
#define GLOVALEXCEPTION_HPP

//#include <iostream>
//#include <exception>
#include "AException.hpp"

#include <string>

class GlovalException : public AException
{
    public:
        GlovalException(std::string message) noexcept
        {
            _message = (message);
   
        };
};

#endif /* !exception */
