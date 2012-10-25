#include "SoftEntity.h"

using namespace swd;

SoftEntity::SoftEntity(SWID id):Entity(id)
{
	simMask = NOMASK;
}

SoftEntity::~SoftEntity(void)
{
}
