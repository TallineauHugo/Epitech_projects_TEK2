//
// EPITECH PROJECT, 2018
// nano
// File description:
// exception
//

#pragma once

#include <string>
#include <exception>
#include "ExceptionMacro.hpp"

class NtsError : public std::exception
{
public:
	NtsError(std::string const& e) throw();
	NtsError() throw();
	virtual ~NtsError() throw();

	virtual const char* what() const throw();
private:
	std::string _msg;
};

class SyntaxError : public NtsError
{
public:
	SyntaxError(const std::string &msg) throw();
	SyntaxError() throw();
	~SyntaxError() throw();
};

class FileError : public NtsError
{
public:
	FileError(const std::string &msg) throw();
	FileError() throw();
	~FileError() throw();
};

class InputError : public NtsError
{
public:
	InputError(const std::string &msg) throw();
	InputError() throw();
	~InputError() throw();
};

class LinkError : public NtsError
{
public:
	LinkError(const std::string &msg) throw();
	LinkError() throw();
	~LinkError() throw();
};

class ChipsetError : public NtsError
{
public:
	ChipsetError(const std::string &msg) throw();
	ChipsetError() throw();
	~ChipsetError() throw();
};

class PinError : public ChipsetError
{
public:
	PinError(std::string const& msg) throw();
	PinError() throw();
	virtual ~PinError() throw();
};
