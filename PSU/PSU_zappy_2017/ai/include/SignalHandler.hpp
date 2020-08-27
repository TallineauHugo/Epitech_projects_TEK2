//
// EPITECH PROJECT, 2018
// zappy
// File description:
// signal handler class declaration
//

#pragma once

namespace ai
{
	class SignalHandler
	{
	public:
		SignalHandler() = default;
		~SignalHandler() = default;

		static bool gotExitSignal();
		void setupSignalHandler();

		static void exitSignalHandler(int ignored);

	protected:
		static bool _exitSignal;
	};
}