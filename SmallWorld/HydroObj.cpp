#include "HydroObj.h"

using namespace swd;

HydroObj::HydroObj(void)
{
	simMask =NoGravity | NoCollision | NoRubForce;
}

HydroObj::~HydroObj(void)
{
}
