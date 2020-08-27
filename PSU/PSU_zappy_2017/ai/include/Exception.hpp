//
// EPITECH PROJECT, 2018
// zappy
// File description:
// exception
//

#pragma once

#include <string>
#include <exception>

class ClientError : public std::exception
{
public:
        ClientError(std::string const& e) throw();
        ClientError() throw();
        virtual ~ClientError() throw();

        virtual const char* what() const throw();
private:
        std::string _msg;
};