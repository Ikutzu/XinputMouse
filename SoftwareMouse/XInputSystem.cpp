#include "XInputSystem.h"
#include "InputSystem.h"
#include "Log.h"

namespace SWM {

	int stickDeadZone = 10000;

	XInputSystem::XInputSystem()
		: inputSystem(nullptr)
	{}

	bool XInputSystem::Initialize(InputSystem *inputSystem)
	{
		this->inputSystem = inputSystem;
		// Reset controller count
		for (unsigned i = 0; i < MAX_CONTROLLERS; ++i)
			controllerConnected[i] = false;

		// Find connected controllers
		XINPUT_STATE state;

		for (unsigned i = 0; i < MAX_CONTROLLERS; ++i)
		{
			ZeroMemory(&state, sizeof(XINPUT_STATE));
			
			DWORD result = XInputGetState(i, &state);

			if (result == ERROR_SUCCESS)
			{
				controllerConnected[i] = true;
				controllerState[i] = state;
			}
		}

		unsigned count = 0;
		for (unsigned i = 0; i < MAX_CONTROLLERS; ++i)
		{
			if (controllerConnected[i])
			{
				LOG(L_INFO, "[XInputSystem] Controller %d connected", i+1);
				++count;
			}
		}

		LOG(L_INFO, "[XInputSystem] Total of %d controller(s) detected!", count);

		if (count == 0)
		{
			LOG(L_INFO,"[XInputSystem] no controllers detected! Stopping XInputSystem.");
		}

		return true;
	}
	
	void XInputSystem::HandleStick(AxisCode2d stick, float X, float Y)
	{
		double magnitude = sqrt(X*X + Y*Y);

		if (magnitude > stickDeadZone)
		{
			double normalizedX = X / magnitude;
			double normalizedY = Y / magnitude;

			if (magnitude > 32767) magnitude = 32767;

			magnitude -= stickDeadZone;
			
			float normalizedMagnitude = magnitude / (32767 - stickDeadZone);

			inputSystem->AxisMove2d(stick, normalizedX*normalizedMagnitude, normalizedY*normalizedMagnitude);
		}
	}

	void XInputSystem::Update()
	{
		XINPUT_STATE state;

		for (unsigned i = 0; i < MAX_CONTROLLERS; ++i)
		{
			if (controllerConnected[i])
			{
				// Get new state and compare to old

				DWORD result = XInputGetState(i, &state);

				if (result != ERROR_SUCCESS)
				{
					LOG(L_INFO, "[XInputSystem] Error on controller state!");
					continue;
				}

				HandleStick(JOY_STICK_LEFT, controllerState[i].Gamepad.sThumbLX, controllerState[i].Gamepad.sThumbLY);
				HandleStick(JOY_STICK_RIGHT, controllerState[i].Gamepad.sThumbRX, controllerState[i].Gamepad.sThumbRY);

				/*
				// Has the button state changed from last time?
				if (state.Gamepad.wButtons == controllerState[i].Gamepad.wButtons)
				continue; // no change, next controller
				*/

				// main buttons
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_A);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_B);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_X);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_Y);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_DPAD_DOWN);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_DPAD_UP);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_DPAD_LEFT);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_DPAD_RIGHT);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_LEFT_SHOULDER);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_RIGHT_SHOULDER);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_RIGHT_THUMB);
				HandleButton(controllerState[i], state, XINPUT_GAMEPAD_LEFT_THUMB);

				// throw old state in
				controllerState[i] = state;
			}
		}
	}

	void XInputSystem::HandleButton(const XINPUT_STATE &oldState, const XINPUT_STATE &newState, const WORD &buttonCode)
	{
		if ((oldState.Gamepad.wButtons & buttonCode) != (newState.Gamepad.wButtons & buttonCode))
		{
			if (newState.Gamepad.wButtons & buttonCode)
			{
				// down
				inputSystem->KeyDown(XInputToKeyCode(buttonCode));
			}
			else
			{
				// up
				inputSystem->KeyUp(XInputToKeyCode(buttonCode));
			}

		}
	}

	KeyCode XInputSystem::XInputToKeyCode(const WORD &param)
	{
		switch (param)
		{
		case XINPUT_GAMEPAD_A:
			return BUTTON_A;
		case XINPUT_GAMEPAD_B:
			return BUTTON_B;
		case XINPUT_GAMEPAD_X:
			return BUTTON_X;
		case XINPUT_GAMEPAD_Y:
			return BUTTON_Y;
		case XINPUT_GAMEPAD_DPAD_UP:
			return BUTTON_UP;
		case XINPUT_GAMEPAD_DPAD_DOWN:
			return BUTTON_DOWN;
		case XINPUT_GAMEPAD_DPAD_LEFT:
			return BUTTON_LEFT;
		case XINPUT_GAMEPAD_DPAD_RIGHT:
			return BUTTON_RIGHT;
		case XINPUT_GAMEPAD_LEFT_SHOULDER:
			return BUTTON_LB;
		case XINPUT_GAMEPAD_RIGHT_SHOULDER:
			return BUTTON_RB;
		}

		return KEY_VOID;
	}
}
