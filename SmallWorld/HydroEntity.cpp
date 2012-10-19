#include "HydroEntity.h"

using namespace swd;

HydroEntity::HydroEntity(SWID id):Entity(id)
{
	simMask =NoGravity | NoCollision | NoRubForce;
}

HydroEntity::~HydroEntity(void)
{
}

bool HydroEntity::checkRigidEntityCollided(Entity*obj,Collision *col){

	return false;
}
bool HydroEntity::checkStaticEntityCollided(Entity*obj,Collision *col){
	return false;
}
bool HydroEntity::checkSoftEntityCollided(Entity*obj,Collision *col){

	return false;
}
bool HydroEntity::checkHydroEntityCollided(Entity*obj,Collision *col){

	return false;
}