#pragma once

#include "RawInputSystem.h"
#include "XInputSystem.h"
#include "Binds.h"
#include <Windows.h>

namespace SWM {
	class SWMWindow
	{
	public:
		SWMWindow(InputSystem *inputSystem);

		int Update();
		
	private:
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		bool static open;

		HWND wHandle;
		
		RawInputSystem rawInput;
		XInputSystem xInput;
	};
}