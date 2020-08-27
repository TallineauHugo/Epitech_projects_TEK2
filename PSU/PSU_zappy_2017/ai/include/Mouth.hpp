//
// EPITECH PROJECT, 2018
// zappy
// File description:
// mouth
//

#pragma once

#include <string>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include "Request.hpp"
#include "Parser.hpp"
#include "CommandManager.hpp"

#define SOCKET_ERROR "Unable to build socket"
#define CONNECT_ERROR "Unable to establish connection with the server"
#define PROTO_ERROR "Unable to build protocol"

namespace ai
{
	namespace Organs {
		class Mouth
		{
		public:
			Mouth(ai::Parser &parser);
			~Mouth();
		public:
			void init();

			bool getCommand(std::string &cmd);
			bool getInventory(std::string &cmd);
			bool getVision(std::string &cmd);
			bool tryLvlUp();
			bool queueIsEmpty();
			void sendCommand(Request request);
			void sendCommand(std::string request);
			void addRequest(std::string str);
		private:
			void initSocket();
			bool readOnString(std::string &cmd);
			void waitServ();
		private:
			CommandManager _cmdManager;
			struct timeval _tv;
			int _sockFd;
			fd_set _rfd;
			std::size_t _port;

			std::string _teamName;
			ai::Parser &_parser;

			/*std::string _inventory;
			std::string _vision;
			std::string _text;
			std::string _elevation;*/ //transfered
		};
	}
}
