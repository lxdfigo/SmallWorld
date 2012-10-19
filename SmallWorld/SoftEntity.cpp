#include "SoftEntity.h"

using namespace swd;

SoftEntity::SoftEntity(SWID id):Entity(id)
{
	simMask = NOMASK;
}

SoftEntity::~SoftEntity(void)
{
}

bool SoftEntity::checkRigidEntityCollided(Entity*obj,Collision *col){

	return false;
}
bool SoftEntity::checkStaticEntityCollided(Entity*obj,Collision *col){
	return false;
}
bool SoftEntity::checkSoftEntityCollided(Entity*obj,Collision *col){

	return false;
}
bool SoftEntity::checkHydroEntityCollided(Entity*obj,Collision *col){

	return false;
}