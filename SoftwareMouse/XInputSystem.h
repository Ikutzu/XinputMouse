#include "InputCodes.h"
#include "InputSystem.h"

#include <Windows.h>
#include <Xinput.h>

namespace SWM {

	static const unsigned MAX_CONTROLLERS = 4;

	class XInputSystem
	{
	public:
		XInputSystem();

		bool Initialize(InputSystem *inputSystem);
		void Update();

	private:
		InputSystem *inputSystem;

		bool controllerConnected[MAX_CONTROLLERS];
		XINPUT_STATE controllerState[MAX_CONTROLLERS];

		KeyCode XInputToKeyCode(const WORD &param);

		void HandleButton(const XINPUT_STATE &oldState, const XINPUT_STATE &newState, const WORD &buttonCode);

		void XInputSystem::HandleStick(AxisCode2d stick, float X, float Y);


	};
}