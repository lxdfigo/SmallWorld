#pragma once
#include "Action.h"

namespace swd{
	class EnviForceAction :
		public Action
	{
	public:
		EnviForceAction(SWID id);
		~EnviForceAction(void);

		virtual void apply(Entity *entity);
		virtual void addForce(AppliedForce f){force += f;}
	private:
		AppliedForce force;
	};
}
