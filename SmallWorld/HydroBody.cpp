#include "HydroBody.h"
using namespace swd;

HydroBody::HydroBody(void)
{
}

HydroBody::~HydroBody(void)
{
}

bool HydroBody::checkRigidBodyCollided(Body*obj,Collision &col){

	return false;
}
bool HydroBody::checkStaticBodyCollided(Body*obj,Collision &col){
	return false;
}
bool HydroBody::checkSoftBodyCollided(Body*obj,Collision &col){

	return false;
}
bool HydroBody::checkHydroBodyCollided(Body*obj,Collision &col){

	return false;
}