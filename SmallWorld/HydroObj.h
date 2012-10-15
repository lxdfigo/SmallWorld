#pragma once
#include "Object.h"

namespace swd{
	class HydroObj :
		public Object
	{
	public:
		HydroObj(void);
		~HydroObj(void);
		virtual void addForce(AppliedForce force){}
	private:
		double resistance;
	};
}
