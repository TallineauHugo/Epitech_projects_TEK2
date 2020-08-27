//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Error handling
//

#ifndef _ARCADEERROR_
#define _ARCADEERROR_

#include <stdexcept>

class ArcadeError : public std::exception
{
private:
	std::string	_msg;

public:
	ArcadeError(std::string msg) : _msg(msg) {};
	const char	*what() const throw(){
		return this->_msg.c_str();
	}
};

#endif // _ARCADEERROR
