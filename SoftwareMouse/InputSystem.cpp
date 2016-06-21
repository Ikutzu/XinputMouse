#include "InputSystem.h"
#include "Log.h"

namespace SWM{
	
	InputSystem::InputSystem()
	{
		for (int i = 0; i < NUM_KEYS; i++)
			inputKeyBinds[i] = 0;

		for (int i = 0; i < NUM_AXIS1D; i++)
			inputAxis1dBinds[i] = 0;

		for (int i = 0; i < NUM_AXIS2D; i++)
			inputAxis2dBinds[i] = 0;
	}

	void InputSystem::BindFunctionToKey(KeyCode key, void(*function)(bool state))
	{
		if (key == KEY_VOID)
		{
			LOG(L_WARNING, "InputSystem: Invalid key to bind: %d", key);
			return;
		}

		inputKeyBinds[key] = function;
	}

	void InputSystem::BindFunctionToAxis1d(AxisCode1d axis, void(*function)(float x))
	{
		if (axis == AXIS1D_VOID)
		{
			LOG(L_WARNING, "InputSystem: Invalid axis to bind: %d", axis);
			return;
		}

		inputAxis1dBinds[axis] = function;
	}

	void InputSystem::BindFunctionToAxis2d(AxisCode2d axis, void(*function)(float x, float y))
	{
		if (axis == AXIS2D_VOID)
		{
			LOG(L_WARNING, "InputSystem: Invalid axis to bind: %d", axis);
			return;
		}

		inputAxis2dBinds[axis] = function;
	}

	void InputSystem::KeyDown(KeyCode key)
	{
		if (key == KEY_VOID)
			return;
		
		if (inputKeyBinds[key] == 0)
			return;
		
		inputKeyBinds[key](true);
	}

	void InputSystem::KeyUp(KeyCode key)
	{
		if (key == KEY_VOID)
			return;

		if (inputKeyBinds[key] == 0)
			return;

		inputKeyBinds[key](false);
	}

	void InputSystem::AxisMove1d(AxisCode1d axis, float x)
	{
		if (axis == AXIS1D_VOID)
			return;

		if (inputAxis1dBinds[axis] == 0)
			return;

		inputAxis1dBinds[axis](x);
	}

	void InputSystem::AxisMove2d(AxisCode2d axis, float x, float y)
	{
		if (axis == AXIS2D_VOID)
			return;

		if (inputAxis2dBinds[axis] == 0)
			return;

		inputAxis2dBinds[axis](x, y);
	}
}