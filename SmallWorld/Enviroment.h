#pragma once
#include "Entity.h"

namespace swd{
	struct EnvConfig{
		VecPos gravity;
		VecPos wind;
	};
	class Enviroment
	{
	public:
		Enviroment(void);
		~Enviroment(void);

		void init(EnvConfig config);
		void update(Entity *obj);
	private:
		AppliedForce gravity;
		AppliedForce wind;
		AppliedForce other;
	};
}