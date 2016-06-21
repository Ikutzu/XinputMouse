#pragma once

namespace SWM {

	/** 
	* @brief Input key codes
	* Bind functions to a key with InputSystem::BindFunctionToKey(...)
	* @ingroup Input
	*/
	enum KeyCode 
	{
		/** INVALID KEY */
		KEY_VOID = 0,

		KEY_A,
		KEY_B,
		KEY_C,
		KEY_D,
		KEY_E,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_I,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_M,
		KEY_N,
		KEY_O,
		KEY_P,
		KEY_Q,
		KEY_R,
		KEY_S,
		KEY_T,
		KEY_U,
		KEY_V,
		KEY_W,
		KEY_X,
		KEY_Y,
		KEY_Z,

		KEY_DOT,
		KEY_COMMA,
		KEY_TILDE,
		KEY_PLUS,
		KEY_MINUS,

		KEY_LEFT,
		KEY_UP,
		KEY_RIGHT,
		KEY_DOWN,
		
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,

		KEY_SPACE,
		KEY_TAB,
		KEY_CAPSLOCK,
		KEY_SHIFT,
		KEY_LSIFTH,
		KEY_RSIFTH,
		KEY_CTRL,
		KEY_LCTRL,
		KEY_RCTRL,
		KEY_ALT,
		KEY_LALT,
		KEY_RALT,
		KEY_BACKSPACE,
		KEY_RETURN,
		KEY_ESC,

		KEY_F1,
		KEY_F2,
		KEY_F3,
		KEY_F4,
		KEY_F5,
		KEY_F6,
		KEY_F7,
		KEY_F8,
		KEY_F9,
		KEY_F10,
		KEY_F11,
		KEY_F12,

		KEY_INSERT,
		KEY_HOME,
		KEY_DELETE,
		KEY_END,
		KEY_PAGEUP,
		KEY_PAGEDOWN,
		KEY_PRINTSCREEN,
		KEY_SCROLLLOCK,
		KEY_PAUSE,

		KEY_NUM_LOCK,
		KEY_NUM_PLUS,
		KEY_NUM_MINUS,
		KEY_NUM_MULT,
		KEY_NUM_DIV,
		KEY_NUM_0,
		KEY_NUM_1,
		KEY_NUM_2,
		KEY_NUM_3,
		KEY_NUM_4,
		KEY_NUM_5,
		KEY_NUM_6,
		KEY_NUM_7,
		KEY_NUM_8,
		KEY_NUM_9,
		KEY_NUM_ENTER,
		KEY_NUM_DECIMAL,

		// ~^¨ or ;: for US
		KEY_OEM1,
		// '* or /? for US
		KEY_OEM2,
		// Ö or `~ for US
		KEY_OEM3,	
		// ´` or [{ for US
		KEY_OEM4,	
		// § or \| for US
		KEY_OEM5,
		// Å or ]} for US
		KEY_OEM6,
		// Ä or '" for US
		KEY_OEM7,
		// <>| or \| on RT 102-key kbd
		KEY_OEM102,
		
		/** Controller left stick button */
		BUTTON_L3,
		/** Controller right stick button */
		BUTTON_R3,
		/** Controller start button (options on DUALSHOCK4) */
		BUTTON_OPTIONS,
		/** Controller D-pad up button */
		BUTTON_UP,
		/** Controller D-pad right button */
		BUTTON_RIGHT,
		/** Controller D-pad down button */
		BUTTON_DOWN,
		/** Controller D-pad left button */
		BUTTON_LEFT,
		/** Controller left trigger */
		BUTTON_L2,
		/** Controller right trigger */
		BUTTON_R2,
		/** Controller left shoulder button */
		BUTTON_L1,
		/** Controller right shoulder button */
		BUTTON_R1,
		/** Controller triangle button */
		BUTTON_TRIANGLE,
		/** Controller circle button */
		BUTTON_CIRCLE,
		/** Controller cross button */
		BUTTON_CROSS,
		/** Controller square button */
		BUTTON_SQUARE,
		/** DUALSHOCK4 touchpad button */
		BUTTON_TOUCHPAD,

		/** Mouse left button */
		MOUSE_1,
		/** Mouse right button */
		MOUSE_2,
		/** Mouse middle button */
		MOUSE_3,
		/** Mouse 4th button */
		MOUSE_4,
		/** Mouse 5th button */
		MOUSE_5,

		/** INVALID KEY */
		NUM_KEYS,
	};
	
#define BUTTON_LTHUMB BUTTON_L3
#define BUTTON_RTHUMB BUTTON_R3
#define BUTTON_START BUTTON_OPTIONS
#define BUTTON_BACK BUTTON_TOUCHPAD
#define BUTTON_LT BUTTON_L2
#define BUTTON_RT BUTTON_R2
#define BUTTON_LB BUTTON_L1
#define BUTTON_RB BUTTON_R1
#define BUTTON_Y BUTTON_TRIANGLE
#define BUTTON_B BUTTON_CIRCLE
#define BUTTON_A BUTTON_CROSS
#define BUTTON_X BUTTON_SQUARE

	/**
	* @brief One dimensional input axis codes
	* Bind functions to a one dimensional axis with InputSystem::BindFunctionToAxis1d(...)
	* @ingroup Input
	*/
	enum AxisCode1d
	{
		/** INVALID AXIS */
		AXIS1D_VOID = 0,
		
		MOUSE_WHEEL,

		/** Controller left trigger analog input */
		TRIGGER_LEFT,
		/** Controller right trigger analog input */
		TRIGGER_RIGHT,
		
		/** INVALID AXIS */
		NUM_AXIS1D
	};
	
	/**
	* @brief Two dimensional input axis codes
	* Bind functions to a two dimensional axis with InputSystem::BindFunctionToAxis2d(...)
	* @ingroup Input
	*/
	enum AxisCode2d
	{
		/** INVALID AXIS */
		AXIS2D_VOID = 0,

		/** Mouse position */
		MOUSE,
		/** Mouse movement */
		MOUSE_DELTA,

		/** DUALSHOCK4 touchpad movement */
		TOUCH_DELTA,
		/** Controller left stick position */
		JOY_STICK_LEFT,
		/** Controller right stick position */
		JOY_STICK_RIGHT,
		
		/** INVALID AXIS */
		NUM_AXIS2D
	};
}