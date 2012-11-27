#include "StaticEntity.h"
#include "BoxBody.h"
#include "PolyBody.h"

using namespace swd;

StaticEntity::StaticEntity(SWID id,VecPos pos,VecPos size):
RigidEntity(id,pos,size){
	simMask = STATIC;
	mass = MAXNUM;
}

StaticEntity::StaticEntity(SWID id,RPolygon poly):
RigidEntity(id,poly){
	simMask = STATIC;
	mass = MAXNUM;
}

StaticEntity::~StaticEntity(void)
{
}

void StaticEntity::setStep(Timer &timer) {

}
bool StaticEntity::update(){

	return true;
}
bool StaticEntity::integrate(){

	return true;
}
void StaticEntity::addForce(AppliedForce force){

}
void StaticEntity::addForceOnPoint(AppliedForce force,VecPos point){

}