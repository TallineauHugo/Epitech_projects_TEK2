//
// EPITECH PROJECT, 2018
// zappy
// File description:
// exception
//

#include "Exception.hpp"

ClientError::ClientError(std::string const& msg) throw()
{
        _msg = msg;
}

ClientError::ClientError() throw()
{
        _msg = "";
}

ClientError::~ClientError() throw()
{}

const char* ClientError::what() const throw()
{
        return _msg.data();
}