//
// EPITECH PROJECT, 2018
// zappy
// File description:
// mouth
//

#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include <netdb.h>
#include <iostream>
#include "Mouth.hpp"
#include "Exception.hpp"

ai::Organs::Mouth::Mouth(ai::Parser &parser) : _parser(parser)
{
	/*_inventory = "";
	_vision = "";
	_text = "";
	_elevation = "";*/
}

ai::Organs::Mouth::~Mouth()
{
}

void ai::Organs::Mouth::init()
{
	std::string buff;
	std::list<std::string> tokens;

	_port = _parser.getPort();
	_teamName = _parser.getTeam();
	this->_tv.tv_sec = 5;
	this->_tv.tv_usec = 0;
	this->initSocket();
	FD_ZERO(&(this->_rfd));
	FD_SET(this->_sockFd, &(this->_rfd));
	while (!this->getCommand(buff));
	std::cout << buff << std::endl;
	this->sendCommand(_teamName + "\n");
	_cmdManager.addRequest(_teamName);
	while (!this->getCommand(buff));
	std::cout << "Remaining team slots: " << buff << std::endl;
	if (buff == "TEAM FULL\r")
		throw ClientError("Team full");
	while (this->getCommand(buff) == false);
	tokens = _parser.getToken(buff, " ");
	std::cout << "Map size: " << tokens.front() << ", " << tokens.back() << std::endl;
}

void ai::Organs::Mouth::initSocket()
{
	struct sockaddr_in sock;
	struct protoent *proto = getprotobyname("TCP");

	if (!proto)
		throw ClientError(PROTO_ERROR);
	_sockFd = socket(AF_INET, SOCK_STREAM, proto->p_proto);
	if (_sockFd == -1)
		throw ClientError(SOCKET_ERROR);
	sock.sin_family = AF_INET;
	sock.sin_port = htons(this->_port);
	sock.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(_sockFd, (struct sockaddr *)&sock, sizeof(sock)) == -1)
		throw ClientError(CONNECT_ERROR);
}

bool ai::Organs::Mouth::tryLvlUp()
{
	std::string cmd;
	std::string str = _cmdManager.getElevation();
	while (str == "") {
		getCommand(cmd);
		str = _cmdManager.getElevation();
	}
	str = _cmdManager.getElevation();
	while (str == "") {
		getCommand(cmd);
		str = _cmdManager.getElevation();
	}
	return (str.compare(0, 2, "ko")) ? false : true;
}

bool ai::Organs::Mouth::getInventory(std::string &cmd)
{
//	cmd = _cmdManager.getInventory();
//	if (cmd == "")
//		getCommand(cmd);
	getCommand(cmd);
	cmd = _cmdManager.getInventory();
	return (cmd != "");
}

bool ai::Organs::Mouth::getVision(std::string &cmd)
{
	//cmd = _cmdManager.getInventory();
	//if (cmd == "")
	//	getCommand(cmd);
	getCommand(cmd);
	cmd = _cmdManager.getVision();
	return (cmd != "");
}

bool ai::Organs::Mouth::queueIsEmpty()
{
	return _cmdManager.queueIsEmpty();
}

bool ai::Organs::Mouth::getCommand(std::string &cmd)
{
	std::size_t i;
	static std::string tmp = "";
	std::string str;

	if (tmp != "") {
		cmd = tmp.substr(0, tmp.find("\n"));
		_cmdManager.addResponse(cmd);
		tmp.erase(0, tmp.find("\n") + 1);
		return true;
	}

	if (select(100, &(this->_rfd), NULL, NULL, &(this->_tv)) <= 0) {
		throw ClientError(
			"No response from server since 5 sec : disconnected.\n");
	}
	this->readOnString(cmd);
	i = cmd.find("\n");
	if (i < cmd.size() - 1)
		tmp = cmd.substr(i + 1);
	if (i < cmd.size())
		cmd.erase(i, std::string::npos);
	str = cmd;
	_cmdManager.addResponse(str);
	return true;
}

bool ai::Organs::Mouth::readOnString(std::string &cmd)
{
	char buffer[1024];
	int ret = 0;

	memset(buffer, 0, 1024);
	cmd = "";
	ret = read(_sockFd, buffer, 1023);
	if (ret < 0)
		throw ClientError("Read failure\n");
	buffer[ret] = '\0';
	cmd.append(buffer);
	return (cmd != "");
}

void ai::Organs::Mouth::sendCommand(ai::Request request)
{
	//if (send(_sockFd, request.getCommand().c_str(),
//		request.getCommand().size(), MSG_NOSIGNAL) < 0)
//		throw ClientError("dead");
	std::cout << "Envoi request: " << request.getCommand() << std::endl;
	if (_cmdManager.addRequest(request))
		dprintf(_sockFd, "%s", request.getCommand().c_str());
	usleep(10000);
}

void ai::Organs::Mouth::sendCommand(std::string request)
{
	std::cout << "Envoi request: " << request << std::endl;
	if (_cmdManager.addRequest(request))
		dprintf(_sockFd, "%s", request.c_str());
	usleep(10000);
}

void ai::Organs::Mouth::addRequest(std::string str)
{
	_cmdManager.addRequest(str);
}
