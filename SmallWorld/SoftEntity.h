#pragma once
#include "Entity.h"

namespace swd{
	class SoftEntity :
		public Entity
	{
	public:
		SoftEntity(SWID id);
		~SoftEntity(void);
		virtual void addForce(AppliedForce force){}
	private:
		double elasticity;
	};
}
