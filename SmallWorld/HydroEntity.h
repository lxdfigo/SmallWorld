#pragma once
#include "Entity.h"

namespace swd{
	class HydroEntity :
		public Entity
	{
	public:
		HydroEntity(SWID id);
		~HydroEntity();
		virtual void addForce(AppliedForce force){}
	private:
		double resistance;
	};
}
