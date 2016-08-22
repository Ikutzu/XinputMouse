#include "Binds.h"
#include "Log.h"

#include <Windows.h>

namespace SWM {

	float cursorSpeed = 2000.0f;
	float movement[2] = { 0.0f, 0.0f };
	float asd = 0.0f;

	void MoveMouse(float x, float y)
	{
		movement[0] += x * asd * cursorSpeed;
		movement[1] += -y * asd* cursorSpeed;
	}

	void MoveMouse2(float x, float y)
	{
		movement[0] += x * 0.25f * asd* cursorSpeed;
		movement[1] += -y * 0.25f * asd* cursorSpeed;
	}

	void MouseLeft(bool state)
	{
		INPUT    Input = { 0 };
		// left down 
		if (state)
		{
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// left up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	void MouseRight(bool state)
	{
		INPUT    Input = { 0 };
		// right down 
		if (state)
		{
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// right up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}
	
	void MouseMiddle(bool state)
	{
		INPUT    Input = { 0 };
		// right down 
		if (state)
		{
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// right up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	void MouseBack(bool state)
	{
		INPUT    Input = { 0 };
		// right down 
		if (state)
		{
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_XDOWN;
			Input.mi.mouseData = XBUTTON1;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// right up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_XUP;
			Input.mi.mouseData = XBUTTON1;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}
	
	void MouseForward(bool state)
	{
		INPUT    Input = { 0 };
		// right down 
		if (state)
		{
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_XDOWN;
			Input.mi.mouseData = XBUTTON2;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// right up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_XUP;
			Input.mi.mouseData = XBUTTON2;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	void LeftArrow(bool state)
	{
		INPUT    Input = { 0 };
		// LeftArrow down 
		if (state)
		{
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_LEFT;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// LeftArrow up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_LEFT;
			Input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	void UpArrow(bool state)
	{
		INPUT    Input = { 0 };
		// UpArrow down 
		if (state)
		{
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_UP;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// UpArrow up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_UP;
			Input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	void DownArrow(bool state)
	{
		INPUT    Input = { 0 };
		// DownArrow down 
		if (state)
		{
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_DOWN;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// DownArrow up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_DOWN;
			Input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	void RightArrow(bool state)
	{
		INPUT    Input = { 0 };
		// RightArrow down 
		if (state)
		{
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_RIGHT;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// RightArrow up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_KEYBOARD;
			Input.ki.wVk = VK_RIGHT;
			Input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	bool CLOSESTART = false;
	bool CLOSEBACK = false;

	void Start(bool state)
	{
		CLOSESTART = state;
	}

	void Back(bool state)
	{
		CLOSEBACK = state;
	}

	Binds::Binds(InputSystem* input)
	{
		input->BindFunctionToAxis2d(JOY_STICK_LEFT, MoveMouse);
		input->BindFunctionToAxis2d(JOY_STICK_RIGHT, MoveMouse2);

		input->BindFunctionToKey(BUTTON_A, MouseLeft);
		input->BindFunctionToKey(BUTTON_B, MouseRight);
		input->BindFunctionToKey(BUTTON_RTHUMB, MouseMiddle);
		input->BindFunctionToKey(BUTTON_LB, MouseBack);
		input->BindFunctionToKey(BUTTON_RB, MouseForward);

		input->BindFunctionToKey(BUTTON_LEFT, LeftArrow);
		input->BindFunctionToKey(BUTTON_UP, UpArrow);
		input->BindFunctionToKey(BUTTON_DOWN, DownArrow);
		input->BindFunctionToKey(BUTTON_RIGHT, RightArrow);

		input->BindFunctionToKey(BUTTON_START, Start);
		input->BindFunctionToKey(BUTTON_BACK, Back);
	}

	bool Binds::UpdateBinds(float dt)
	{
		asd = dt;
		if (movement[0] > 1.0f || movement[0] < -1.0f || movement[1] > 1.0f || movement[1] < -1.0f)
		{
			POINT temp;
			GetCursorPos(&temp);

			bool x = false;
			bool y = false;

			if (movement[0] > 1.0f)
			{
				temp.x += 1;
				x = true;
			}
			else if (movement[0] < -1.0f)
			{
				temp.x -= 1;
				x = true;
			}

			if (movement[1] > 1.0f)
			{
				temp.y += 1;
				y = true;
			}
			else if (movement[1] < -1.0f)
			{
				temp.y -= 1;
				y = true;
			}

			SetCursorPos(temp.x, temp.y);

			if (x)
				movement[0] = 0.0f;

			if (y)
				movement[1] = 0.0f;
		}

		if (CLOSESTART && CLOSEBACK)
			return false;
		else
			return true;
	}
}