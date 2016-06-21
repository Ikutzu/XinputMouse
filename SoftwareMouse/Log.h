#pragma once

#include <string>
#include <stdio.h>
#include <stdarg.h>

/**
* Priority of debug message.
*/
enum LogLevel
{
	L_ERROR = 0,
	L_WARNING,
	L_INFO,
};

/** Size of LOG output buffer. */
#define LOG_OUTPUT_SIZE 256

/**
* Log messages to output.
*
* Log messages as errors, warning or information.
* Messages will be printed on system output(s).
*
* Usage: LOG(LogLevel, message, parameters)
* [Example] LOG(L_WARNING, "Player: %d disconnected!", player.id);
*
* @see enum LogLevel
*/
#define LOG(...) SWM::WriteToLog(__VA_ARGS__);

namespace SWM {

	/**
	* Brief class explanation. TODO: Doxygen
	*
	* Longer explanation.
	*/
	class Log
	{
	public:
		/**
		* Handles the logging of single message.
		*
		* LOG() macro calls all loggers added by AddLogger() and loggers call this function.
		*
		* @param message Message for output device to log.
		*/
		virtual void LogMessage(const std::string& message) = 0;
	};

	/**
	* Format arguments gathered from LOG macro and call LogProxy.
	*/
	void WriteToLog(LogLevel level, const char* p_message, ...);

	/**
	* Edits the message to include LogLevel and calls all loggers to print the message.
	*/
	void LogProxy(const LogLevel level, const char* message);

	/**
	* Add new logger from which to print.
	*
	* @param logger Pointer to new logger for system to use.
	*/
	void AddLogger(Log* logger);

}