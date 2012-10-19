#include "StaticEntity.h"

using namespace swd;

StaticEntity::StaticEntity(SWID id):Entity(id)
{
	simMask = NoGravity;
}

StaticEntity::~StaticEntity(void)
{
}

bool StaticEntity::checkRigidEntityCollided(Entity*obj,Collision *col){

	return false;
}
bool StaticEntity::checkStaticEntityCollided(Entity*obj,Collision *col){
	return false;
}
bool StaticEntity::checkSoftEntityCollided(Entity*obj,Collision *col){

	return false;
}
bool StaticEntity::checkHydroEntityCollided(Entity*obj,Collision *col){

	return false;
}