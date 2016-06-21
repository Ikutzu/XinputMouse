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
		// left down 
		if (state)
		{
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
			SendInput(1, &Input, sizeof(INPUT));
		}
		else
		{	// left up
			ZeroMemory(&Input, sizeof(INPUT));
			Input.type = INPUT_MOUSE;
			Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			SendInput(1, &Input, sizeof(INPUT));
		}
	}

	Binds::Binds(InputSystem* input)
	{
		input->BindFunctionToAxis2d(JOY_STICK_LEFT, MoveMouse);
		input->BindFunctionToAxis2d(JOY_STICK_RIGHT, MoveMouse2);
		input->BindFunctionToKey(BUTTON_A, MouseLeft);
		input->BindFunctionToKey(BUTTON_B, MouseRight);
	}

	void Binds::UpdateMouse(float dt)
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
	}
}