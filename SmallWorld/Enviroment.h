#pragma once
#include "Entity.h"
#include "EnviForceAction.h"

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
		Action * getAction(){return action;}
	private:
		EnviForceAction * action;
	};
}