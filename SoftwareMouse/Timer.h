#pragma once 
#include <Windows.h>

namespace SWM
{
	/**
	* Timer class
	*
	* Timer used to get the elapsed time between two points in time
	*
	* @ingroup Timer
	*/
	class Timer
	{

	public:
		/**
		* Default constructor
		*
		* sets timer to stopped
		*/
		Timer();

		/**
		* Initializes Timer
		*
		* Does something only on win
		* Should still be called
		*/
		void InitTimer();

		/**
		* Starts Timer
		*
		* If already running resets timer
		*
		* sets stopped to false
		*/
		void Start();

		/**
		* Stops Timer
		*
		* sets stopped to true
		*/
		void Stop();

		/**
		* Get time in µs
		*
		* @return float time in microseconds
		*/
		float GetElapsedTimeMicros();

		/**
		* Get time in ms
		*
		* @return float time in milliseconds
		*/
		float GetElapsedTimeMs();

		/**
		* Get time in seconds
		*
		* @return float time in seconds
		*/
		float GetElapsedTimeS();

		/**
		* Get current time in seconds
		*
		* Starts from InitTimer that should be called on aplication start
		* @return double time in seconds
		*/
		float GetCurrentTimeS();

	private:

		bool stopped;

		//Timer
		LARGE_INTEGER startTime;
		LARGE_INTEGER endTime;
		LARGE_INTEGER frequency;

		//Time stamper
		LARGE_INTEGER time;
		LARGE_INTEGER currentTime;
	};
}