#include "Log.h"

#include <vector>

namespace SWM {

	std::vector<Log*> loggerVector; // Vector to contain all the custom logs.

	void WriteToLog(LogLevel level, const char* p_message, ...)
	{
		char output[LOG_OUTPUT_SIZE];
		va_list args;
		va_start(args, p_message);
		vsnprintf_s(output, LOG_OUTPUT_SIZE, p_message, args);
		va_end(args);
		LogProxy(level, output);
	}

	// cppcheck-suppress unusedFunction
	void LogProxy(const LogLevel level, const char *message) 
	{
		char output[2000]; // HACK: Hard coded limit.
		
		switch (level)
		{
		case L_ERROR:
			sprintf_s(output, "[ERROR]: %s\n", message);
			break;
		case L_WARNING :
			sprintf_s(output, "[WARNING]: %s\n", message);
			break;
		case L_INFO :
			sprintf_s(output, "[INFO]: %s\n", message);
			break;
		default:
			sprintf_s(output, "[UNKNOWN]: %s\n", message);
		}

		// Call all loggers to log the message.
		for (unsigned i = 0; i < loggerVector.size(); ++i) 
		{
			// TODO: Add custom mutex start here.
			loggerVector[i]->LogMessage(output);
			// TODO: Add custom mutex end here.
		}
		
	}

	void AddLogger(Log *logger)
	{
		loggerVector.push_back(logger);
	}

}