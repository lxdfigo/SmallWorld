#pragma once
#include "Basic.h"
namespace swd{
	class Deactivator
	{
	public:
		Deactivator(void);
		~Deactivator(void);
		bool isDisable(){ return false;}
	};
}