#pragma once
#include "InputSystem.h"
namespace SWM {
	class Binds {
	public:
		Binds(InputSystem* input);
		void UpdateMouse(float dt);
	};
}