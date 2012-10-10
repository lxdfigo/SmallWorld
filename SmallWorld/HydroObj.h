#pragma once
#include "Object.h"

namespace swd{
	class HydroObj :
		public Object
	{
	public:
		HydroObj(void);
		~HydroObj(void);
	private:
		double resistance;
	};
}
