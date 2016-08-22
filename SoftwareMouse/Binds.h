#pragma once
#include "InputSystem.h"
namespace SWM {
	class Binds {
	public:
		Binds(InputSystem* input);
		bool UpdateBinds(float dt);
	};
}