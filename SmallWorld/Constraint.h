#pragma once
#include "Basic.h"

namespace swd{
	class Constraint
	{
	public:
		Constraint(SWID id);
		~Constraint(void);
		SWID getID(){return cid;}
	private:
		SWID cid;
	};
}