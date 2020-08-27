//
// EPITECH PROJECT, 2018
// nano
// File description:
// Exception
//

#include "Exception.hpp"

NtsError::NtsError(std::string const& msg) throw()
{
	_msg = msg;
}

NtsError::NtsError() throw()
{
	_msg = "";
}

NtsError::~NtsError() throw()
{}

const char* NtsError::what() const throw()
{
	return _msg.data();
}

SyntaxError::SyntaxError(std::string const& msg) throw() : NtsError(msg)
{}

SyntaxError::SyntaxError() throw()
{}

SyntaxError::~SyntaxError() throw()
{}

FileError::FileError(std::string const& msg) throw() : NtsError(msg)
{}

FileError::FileError() throw()
{}

FileError::~FileError() throw()
{}

InputError::InputError(std::string const& msg) throw() : NtsError(msg)
{}

InputError::InputError() throw()
{}

InputError::~InputError() throw()
{}

LinkError::LinkError(std::string const& msg) throw() : NtsError(msg)
{}

LinkError::LinkError() throw()
{}

LinkError::~LinkError() throw()
{}

ChipsetError::ChipsetError(std::string const& msg) throw() : NtsError(msg)
{}

ChipsetError::ChipsetError() throw()
{}

ChipsetError::~ChipsetError() throw()
{}

PinError::PinError(std::string const& msg) throw() : ChipsetError(msg)
{}

PinError::PinError() throw()
{}

PinError::~PinError() throw()
{}
