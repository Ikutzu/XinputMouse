#pragma once

#include "Log.h"

#include <iostream>
#include <Windows.h>
#include <WinBase.h>

namespace SWM{

	/**
	* Brief class explanation. TODO: Doxygen
	*
	* Longer explanation.
	*/
	class StdLogger : public SWM::Log
	{
	public:
		/**
		* Usage: LOG(LogLevel, message)
		* [Example] LOG(WARNING, "Player: " << player.id << " disconnected!" << std::endl);
		*/
		void LogMessage(const std::string &message) 
		{ 
			// Log messages on Visual Studio output.
			std::wstring temp = std::wstring(message.c_str(), message.c_str() + message.length());
			LPCWSTR wStr = temp.c_str();
			OutputDebugString(wStr);

			// Logs messages on console and PS4 output.
			printf(message.c_str());
		}
	};

}