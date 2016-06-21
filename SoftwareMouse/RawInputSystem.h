#pragma once

#include <Windows.h>

#include "InputSystem.h"
#include "InputCodes.h"

namespace SWM{

	/**
	* @brief Raw input system for Windows
	* Raw input system for Windows. Processes raw keyboard and mouse input from the application.
	* If initialization fails, window message type of input will be used instead.
	* @ingroup Input
	*/
	class RawInputSystem
	{
	public:
		RawInputSystem();

		/**
		* @brief Initializes the RawInputSystem
		* Tries to initialize keyboard and mouse raw input for the application window
		* @param *inputSystem Pointer to InputSystem to use
		* @param *hwnd Pointer to application window to listen to
		* @return true Keyboard and mouse successfully registered as raw input devices
		* @return false Raw input device registering failed, window message type of input will be used
		*/
		bool Initialize(InputSystem *inputSystem, void *hwnd);

		/**
		* @brief Processes the applications keyboard and mouse input
		*/
		void Update();

		void KeyDown(const MSG &msg);
		void KeyUp(const MSG &msg);
		void HandleRawInput(const MSG &msg);
	private:

		KeyCode WinkeyToKeyCode(const WPARAM &param);
		
		void InitWinKeyTable();
		

		KeyCode winkeyConvertTable[255];

		HWND windowHandle;

		bool rawInput;

		InputSystem *inputSystem;
		int mouseLastX, mouseLastY;
		
	};
}