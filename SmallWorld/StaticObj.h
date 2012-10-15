#pragma once
#include "Object.h"

namespace swd{
	class StaticObj :
		public Object
	{
	public:
		StaticObj(void);
		~StaticObj(void);

		virtual void addForce(AppliedForce force){}
	};
}
