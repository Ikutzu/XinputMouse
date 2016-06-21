
#include "Timer.h"

namespace SWM {

	Timer::Timer()
	{
		stopped = true;
		//TODO: initialize large integer
	}

	void Timer::InitTimer()
	{
		QueryPerformanceFrequency(&frequency);

		stopped = true;
	}

	void Timer::Start()
	{
		QueryPerformanceCounter(&startTime);
		QueryPerformanceCounter(&time);
		stopped = false;
	}
	void Timer::Stop()
	{
		stopped = true;
	}

	float Timer::GetElapsedTimeMicros()
	{
		LARGE_INTEGER ElapsedMicroseconds;

		if (!stopped)
			QueryPerformanceCounter(&endTime);

		ElapsedMicroseconds.QuadPart = endTime.QuadPart - startTime.QuadPart;
		ElapsedMicroseconds.QuadPart *= 1000000;
		float elapsedMicros = (float)(ElapsedMicroseconds.QuadPart /= frequency.QuadPart);

		return elapsedMicros;
	}

	float Timer::GetElapsedTimeMs()
	{
		float elapsedMicros = GetElapsedTimeMicros();
		float elapsedMs = elapsedMicros / 1000;
		return elapsedMs;
	}

	float Timer::GetElapsedTimeS()
	{
		float elapsedMicros = GetElapsedTimeMicros();
		float elapsedS = elapsedMicros / 1000000;
		return elapsedS;
	}

	float Timer::GetCurrentTimeS()
	{
		LARGE_INTEGER ElapsedMicroseconds;

		QueryPerformanceCounter(&currentTime);

		ElapsedMicroseconds.QuadPart = currentTime.QuadPart - time.QuadPart;
		ElapsedMicroseconds.QuadPart *= 1000000;
		float elapsedSeconds = (float)(ElapsedMicroseconds.QuadPart /= frequency.QuadPart);
		elapsedSeconds /= 1000000;
		return elapsedSeconds;
	}
}