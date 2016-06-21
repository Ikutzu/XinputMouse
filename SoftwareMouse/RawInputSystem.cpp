#include "RawInputSystem.h"
#include "Log.h"

namespace SWM{

	RawInputSystem::RawInputSystem()
		: inputSystem(NULL)
		, windowHandle(NULL)
		, rawInput(false)
		, mouseLastX(0)
		, mouseLastY(0)
	{}

	bool RawInputSystem::Initialize(InputSystem *inputSystem, void *hwnd)
	{
		this->inputSystem = inputSystem;
		this->windowHandle = (HWND)hwnd;

		InitWinKeyTable();
		
		RAWINPUTDEVICE rid[2];

		rid[0].usUsagePage = 0x01;
		rid[0].usUsage = 0x02;
		rid[0].dwFlags = 0;
		rid[0].hwndTarget = windowHandle;

		rid[1].usUsagePage = 0x01;
		rid[1].usUsage = 0x06;
		rid[1].dwFlags = RIDEV_NOLEGACY;
		rid[1].hwndTarget = windowHandle;

		if (RegisterRawInputDevices(rid, 2, sizeof(rid[0])) == FALSE)
		{
			LOG(L_WARNING, "RawInputSystem: Registering raw input devices failed");
		}
		else
			rawInput = true;

		return rawInput;
	}

	void RawInputSystem::Update()
	{
		if (!rawInput)
		{
			POINT cursorPos;
			RECT windowRect;

			GetCursorPos(&cursorPos);
			GetWindowRect(windowHandle, &windowRect);

			int x = (int)cursorPos.x - windowRect.left;
			int y = (int)cursorPos.y - windowRect.top;

			if (mouseLastX != x || mouseLastY != y)
			{
				inputSystem->AxisMove2d(MOUSE, float(x), float(y));

				mouseLastX = x;
				mouseLastX = y;
			}
		}
	}

		// Private
	void RawInputSystem::KeyDown(const MSG &msg)
	{
		inputSystem->KeyDown(WinkeyToKeyCode(msg.wParam));
	}

	void RawInputSystem::KeyUp(const MSG &msg)
	{
		inputSystem->KeyUp(WinkeyToKeyCode(msg.wParam));
	}

	KeyCode RawInputSystem::WinkeyToKeyCode(const WPARAM &param) { return winkeyConvertTable[param]; }

	void RawInputSystem::InitWinKeyTable()
	{
		for (unsigned i = 0; i < sizeof(winkeyConvertTable) / sizeof(winkeyConvertTable[0]); ++i)
			winkeyConvertTable[i] = KEY_VOID;
		

		winkeyConvertTable[0x01] = MOUSE_1;
		winkeyConvertTable[0x02] = MOUSE_2;
		winkeyConvertTable[0x04] = MOUSE_3;
		winkeyConvertTable[0x05] = MOUSE_4;
		winkeyConvertTable[0x06] = MOUSE_5;
										
		winkeyConvertTable[0x08] = KEY_BACKSPACE;		// 8
		winkeyConvertTable[0x09] = KEY_TAB;				// 9
											
		winkeyConvertTable[0x0D] = KEY_RETURN;			// 13
		winkeyConvertTable[0x10] = KEY_SHIFT;			// 16
		winkeyConvertTable[0x11] = KEY_CTRL;			// 17
		winkeyConvertTable[0x12] = KEY_ALT;				// 18
														
		winkeyConvertTable[0x13] = KEY_PAUSE;			// 19
		winkeyConvertTable[0x14] = KEY_CAPSLOCK;		// 20

		winkeyConvertTable[0x1B] = KEY_ESC;				// 27

		winkeyConvertTable[0x20] = KEY_SPACE;			// 32
		// winkeyConvertTable[0x21] = KEY_PAGEUP;		// 33 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x22] = KEY_PAGEDOWN;		// 34 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x23] = KEY_END;			// 35 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x24] = KEY_HOME;			// 36 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x25] = KEY_LEFT;			// 37 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x26] = KEY_UP;			// 38 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x27] = KEY_RIGHT;		// 39 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x28] = KEY_DOWN;			// 40 Not working Use RI_KEY_E0 and RI_KEY_E1 

		// winkeyConvertTable[0x2C] = KEY_PRINTSCREEN;	// 44 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x2D] = KEY_INSERT;		// 45 Not working Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0x2E] = KEY_DELETE;		// 46 Not working Use RI_KEY_E0 and RI_KEY_E1 

		winkeyConvertTable[0x30] = KEY_0;				// 48
		winkeyConvertTable[0x31] = KEY_1;				// 49
		winkeyConvertTable[0x32] = KEY_2;				// 50
		winkeyConvertTable[0x33] = KEY_3;				// 51
		winkeyConvertTable[0x34] = KEY_4;				// 52
		winkeyConvertTable[0x35] = KEY_5;				// 53
		winkeyConvertTable[0x36] = KEY_6;				// 54
		winkeyConvertTable[0x37] = KEY_7;				// 55
		winkeyConvertTable[0x38] = KEY_8;				// 56
		winkeyConvertTable[0x39] = KEY_9;				// 57

		winkeyConvertTable[0x41] = KEY_A;				// 65
		winkeyConvertTable[0x42] = KEY_B;				// 66
		winkeyConvertTable[0x43] = KEY_C;				// 67
		winkeyConvertTable[0x44] = KEY_D;				// 68
		winkeyConvertTable[0x45] = KEY_E;				// 69
		winkeyConvertTable[0x46] = KEY_F;				// 70
		winkeyConvertTable[0x47] = KEY_G;				// 71
		winkeyConvertTable[0x48] = KEY_H;				// 72
		winkeyConvertTable[0x49] = KEY_I;				// 73
		winkeyConvertTable[0x4A] = KEY_J;				// 74
		winkeyConvertTable[0x4B] = KEY_K;				// 75
		winkeyConvertTable[0x4C] = KEY_L;				// 76
		winkeyConvertTable[0x4D] = KEY_M;				// 77
		winkeyConvertTable[0x4E] = KEY_N;				// 78
		winkeyConvertTable[0x4F] = KEY_O;				// 79
		winkeyConvertTable[0x50] = KEY_P;				// 80
		winkeyConvertTable[0x51] = KEY_Q;				// 81
		winkeyConvertTable[0x52] = KEY_R;				// 82
		winkeyConvertTable[0x53] = KEY_S;				// 83
		winkeyConvertTable[0x54] = KEY_T;				// 84
		winkeyConvertTable[0x55] = KEY_U;				// 85
		winkeyConvertTable[0x56] = KEY_V;				// 86
		winkeyConvertTable[0x57] = KEY_W;				// 87
		winkeyConvertTable[0x58] = KEY_X;				// 88
		winkeyConvertTable[0x59] = KEY_Y;				// 89
		winkeyConvertTable[0x5A] = KEY_Z;				// 90
	
		winkeyConvertTable[0x60] = KEY_NUM_0;			// 96
		winkeyConvertTable[0x61] = KEY_NUM_1;			// 97
		winkeyConvertTable[0x62] = KEY_NUM_2;			// 98
		winkeyConvertTable[0x63] = KEY_NUM_3;			// 99
		winkeyConvertTable[0x64] = KEY_NUM_4;			// 100
		winkeyConvertTable[0x65] = KEY_NUM_5;			// 101
		winkeyConvertTable[0x66] = KEY_NUM_6;			// 102
		winkeyConvertTable[0x67] = KEY_NUM_7;			// 103
		winkeyConvertTable[0x68] = KEY_NUM_8;			// 104
		winkeyConvertTable[0x69] = KEY_NUM_9;			// 105
		winkeyConvertTable[0x6A] = KEY_NUM_MULT;		// 106
		winkeyConvertTable[0x6B] = KEY_NUM_PLUS;		// 107

		winkeyConvertTable[0x6D] = KEY_NUM_MINUS;		// 109
		winkeyConvertTable[0x6E] = KEY_NUM_DECIMAL;		// 110
		// winkeyConvertTable[0x6F] = KEY_NUM_DIV;		// 111 Not working
		winkeyConvertTable[0x70] = KEY_F1;				// 112
		winkeyConvertTable[0x71] = KEY_F2;				// 113
		winkeyConvertTable[0x72] = KEY_F3;				// 114
		winkeyConvertTable[0x73] = KEY_F4;				// 115
		winkeyConvertTable[0x74] = KEY_F5;				// 116
		winkeyConvertTable[0x75] = KEY_F6;				// 117
		winkeyConvertTable[0x76] = KEY_F7;				// 118
		winkeyConvertTable[0x77] = KEY_F8;				// 119
		winkeyConvertTable[0x78] = KEY_F9;				// 120
		winkeyConvertTable[0x79] = KEY_F10;				// 121
		winkeyConvertTable[0x7A] = KEY_F11;				// 122
		winkeyConvertTable[0x7B] = KEY_F12;				// 123

		winkeyConvertTable[0x90] = KEY_NUM_LOCK;		// 144
		winkeyConvertTable[0x91] = KEY_SCROLLLOCK;		// 145

		// winkeyConvertTable[0xA0] = KEY_LSIFTH;		// 160 >> 16 -
		// winkeyConvertTable[0xA1] = KEY_RSIFTH;		// 161 >> 16  |
		// winkeyConvertTable[0xA2] = KEY_LCTRL;		// 162 >> 17  |- Use RI_KEY_E0 and RI_KEY_E1 
		// winkeyConvertTable[0xA3] = KEY_RCTRL;		// 163 >> 17  |- to identify left and right 
		// winkeyConvertTable[0xA4] = KEY_LALT;			// 164 >> 18  |  also RCTRL doesn't work...
		// winkeyConvertTable[0xA5] = KEY_RALT;			// 165 >> 18 -
		
		winkeyConvertTable[0xBA] = KEY_OEM1;			// 186
		winkeyConvertTable[0xBB] = KEY_PLUS;			// 187
		winkeyConvertTable[0xBC] = KEY_COMMA;			// 188
		winkeyConvertTable[0xBD] = KEY_MINUS;			// 189
		winkeyConvertTable[0xBE] = KEY_DOT;				// 190
		winkeyConvertTable[0xBF] = KEY_OEM2;			// 191
		winkeyConvertTable[0xC0] = KEY_OEM3;			// 192
		
		winkeyConvertTable[0xDB] = KEY_OEM4;			// 219
		winkeyConvertTable[0xDC] = KEY_OEM5;			// 220
		winkeyConvertTable[0xDD] = KEY_OEM6;			// 221
		winkeyConvertTable[0xDE] = KEY_OEM7;			// 222
		
		winkeyConvertTable[0xE2] = KEY_OEM102;			// 226	
	}

	void RawInputSystem::HandleRawInput(const MSG &msg)
	{
		size_t size;

		GetRawInputData(reinterpret_cast<HRAWINPUT>(msg.lParam), RID_INPUT,NULL, &size, sizeof(RAWINPUTHEADER));
		char* buffer = (char*)malloc(size);

		if (GetRawInputData(reinterpret_cast<HRAWINPUT>(msg.lParam), RID_INPUT, buffer, &size, sizeof(RAWINPUTHEADER)) != size)
		{
			LOG(L_WARNING, "GetRawInputData doesn't return correct size!");
		}

		// extract keyboard raw input data
		RAWINPUT* raw = reinterpret_cast<RAWINPUT*>(buffer);
		if (raw->header.dwType == RIM_TYPEKEYBOARD)
		{
			RAWKEYBOARD& rawKB = raw->data.keyboard;

			if (rawKB.Flags == RI_KEY_MAKE)
				inputSystem->KeyDown(WinkeyToKeyCode(rawKB.VKey));
			
			if (rawKB.Flags == RI_KEY_BREAK)
				inputSystem->KeyUp(WinkeyToKeyCode(rawKB.VKey));
		}

		if (raw->header.dwType == RIM_TYPEMOUSE)
		{
			const RAWMOUSE &rawMouse = raw->data.mouse;

			inputSystem->AxisMove2d(MOUSE, float(rawMouse.lLastX), float(rawMouse.lLastY));

			if (rawMouse.usButtonFlags == RI_MOUSE_WHEEL)
				inputSystem->AxisMove1d(MOUSE_WHEEL, float(rawMouse.usButtonData));

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_1_DOWN)
				inputSystem->KeyDown(MOUSE_1);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_1_UP)
				inputSystem->KeyUp(MOUSE_1);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_2_DOWN)
				inputSystem->KeyDown(MOUSE_2);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_2_UP)
				inputSystem->KeyUp(MOUSE_2);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_3_DOWN)
				inputSystem->KeyDown(MOUSE_3);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_3_UP)
				inputSystem->KeyUp(MOUSE_3);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_4_DOWN)
				inputSystem->KeyDown(MOUSE_4);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_4_UP)
				inputSystem->KeyUp(MOUSE_4);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_5_DOWN)
				inputSystem->KeyDown(MOUSE_5);

			if (rawMouse.ulButtons == RI_MOUSE_BUTTON_5_UP)
				inputSystem->KeyUp(MOUSE_5);
		}
		
		free((void*)buffer);
	}
}