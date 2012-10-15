#pragma once
#include "Object.h"

namespace swd{
	class SoftObj :
		public Object
	{
	public:
		SoftObj(void);
		~SoftObj(void);
		virtual void addForce(AppliedForce force){}
	private:
		double elasticity;
	};
}
