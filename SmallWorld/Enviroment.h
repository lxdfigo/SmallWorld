#pragma once
#include "Object.h"

namespace swd{
	class Enviroment
	{
	public:
		Enviroment(void);
		~Enviroment(void);

		void update(Object *obj);
	private:
		AppliedForce gravity;
		AppliedForce wind;
		AppliedForce other;
	};
}