#include "SWMWindow.h"


namespace SWM {

	bool SWMWindow::open = false;

	SWMWindow::SWMWindow(InputSystem* inputSystem)
	:	wHandle(0)
	{
		WNDCLASS wc = {};

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = L"SoftwareMouse window";

		RegisterClass(&wc);

		// Create the window.

		wHandle = CreateWindowEx(
			0,                              // Optional window styles.
			L"SoftwareMouse window",                     // Window class
			L"SoftwareMouse",    // Window text
			WS_OVERLAPPEDWINDOW,            // Window style

											// Size and position
			128, 128, 256, 128,

			NULL,       // Parent window    
			NULL,       // Menu
			wc.hInstance,  // Instance handle
			NULL        // Additional application data
			);

		if (wHandle == NULL)
		{
			return;
		}

		ShowWindow(wHandle, 1);
		open = true;

		rawInput.Initialize(inputSystem, &wHandle);
		xInput.Initialize(inputSystem);

	}

	int SWMWindow::Update()
	{
		// Run the message loop.
		MSG msg = {};
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		
			switch (msg.message)
			{
			case WM_INPUT:
				rawInput.HandleRawInput(msg);
				break;
			case WM_KEYDOWN:
				if (!(msg.lParam & 0x40000000))
					rawInput.KeyDown(msg);
				break;
			case WM_KEYUP:
				rawInput.KeyUp(msg);
				break;
			}
		}

		rawInput.Update();
		xInput.Update();
		
		return open;
	}

	LRESULT CALLBACK SWMWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			open = false;
			break;
		
		default:	
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		
		return 0;
	}
}