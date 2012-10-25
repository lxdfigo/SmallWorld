#include "HydroEntity.h"

using namespace swd;

HydroEntity::HydroEntity(SWID id):Entity(id)
{
	simMask =NoGravity | NoCollision | NoRubForce;
}

HydroEntity::~HydroEntity(void)
{
}
