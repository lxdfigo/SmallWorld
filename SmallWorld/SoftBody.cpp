#include "SoftBody.h"
using namespace swd;

SoftBody::SoftBody(void)
{
}

SoftBody::~SoftBody(void)
{
}

bool SoftBody::checkRigidBodyCollided(Body*obj,Collision &col){

	return false;
}
bool SoftBody::checkStaticBodyCollided(Body*obj,Collision &col){
	return false;
}
bool SoftBody::checkSoftBodyCollided(Body*obj,Collision &col){

	return false;
}
bool SoftBody::checkHydroBodyCollided(Body*obj,Collision &col){

	return false;
}