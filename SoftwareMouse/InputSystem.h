#pragma once

#include "InputCodes.h"

namespace SWM{

	/**
	* @brief InputSystem handles key binds
	* InputSystem is used to bind function pointers to specific input keys or axes
	* @ingroup Input
	*/
	class InputSystem
	{
	public:

		InputSystem();
		
		/**
		* @brief Binds a function to a KeyCode
		* Binds the given function to be called when the given key is pressed
		* @param key Key to bind the function to
		* @param (*function)(bool state) Function pointer to bind
		*/
		void BindFunctionToKey(KeyCode key, void(*function)(bool state));

		/**
		* @brief Binds a function to an AxisCode1d
		* Binds the given function to be called when the given axis is moved
		* @param axis One dimensional axis to bind the function to
		* @param (*function)(float x) Function pointer to bind
		*/
		void BindFunctionToAxis1d(AxisCode1d axis, void(*function)(float x));

		/**
		* @brief Binds a function to an AxisCode2d
		* Binds the given function to be called when the given axis is moved
		* @param axis Two dimensional axis to bind the function to
		* @param (*function)(float x, float y) Function pointer to bind
		*/
		void BindFunctionToAxis2d(AxisCode2d axis, void(*function)(float x, float y));

		/**
		* @Brief Calls the function bound to a key
		* Calls the function bound to a key with parameter "true"
		* @param key Function bound to this key will be called
		*/
		void KeyDown(KeyCode key);

		/**
		* @Brief Calls the function bound to a key
		* Calls the function bound to a key with parameter "false"
		* @param key Function bound to this key will be called
		*/
		void KeyUp(KeyCode key);

		/**
		* @Brief Calls the function bound to a one dimensional axis
		* Calls the function bound to a one dimensional axis with given parameter "x"
		* @param axis Function bound to this axis will be called
		* @param x Parameter that will be sent to the function
		*/
		void AxisMove1d(AxisCode1d axis, float x);

		/**
		* @Brief Calls the function bound to a two dimensional axis
		* Calls the function bound to a two dimensional axis with given parameters "x" and "y"
		* @param axis Function bound to this axis will be called
		* @param x Parameter that will be sent to the bound function
		* @param y Parameter that will be sent to the bound function
		*/
		void AxisMove2d(AxisCode2d axis, float x, float y);

	private:
		
		void(*inputKeyBinds[NUM_KEYS])(bool state);
		void(*inputAxis1dBinds[NUM_AXIS1D])(float x);
		void(*inputAxis2dBinds[NUM_AXIS2D])(float x, float y);
		
	};
}