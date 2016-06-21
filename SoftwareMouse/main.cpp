//#include "SWMWindow.h"
#include "InputSystem.h"
#include "Log.h"
#include "StdLogger.h"
#include "Binds.h"
#include "Timer.h"
#include "XInputSystem.h"

using namespace SWM;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdShow)
{
	AddLogger(new StdLogger());
	
	InputSystem inputSystem;
	XInputSystem xinput;
	xinput.Initialize(&inputSystem);
	//SWMWindow window(&inputSystem);
	Timer time;

	time.InitTimer();
	time.Start();

	Binds binds(&inputSystem);

	bool open = true;
	while (open)
	{
		float dt = time.GetElapsedTimeS();
		time.Start();
		xinput.Update();
		binds.UpdateMouse(dt);
		//open = window.Update();
		Sleep(1);
	}

	return 0;
}