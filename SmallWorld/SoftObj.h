#pragma once
#include "Object.h"

namespace swd{
	class SoftObj :
		public Object
	{
	public:
		SoftObj(void);
		~SoftObj(void);
	private:
		double elasticity;
	};
}
