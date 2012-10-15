#include "StaticBody.h"
using namespace swd;

StaticBody::StaticBody(void)
{
}

StaticBody::~StaticBody(void)
{
}

bool StaticBody::checkRigidBodyCollided(Body*obj,Collision &col){

	return false;
}
bool StaticBody::checkStaticBodyCollided(Body*obj,Collision &col){
	return false;
}
bool StaticBody::checkSoftBodyCollided(Body*obj,Collision &col){

	return false;
}
bool StaticBody::checkHydroBodyCollided(Body*obj,Collision &col){

	return false;
}