#include "RigidEntity.h"
#include "BoxBody.h"
#include "PolyBody.h"

using namespace swd;

RigidEntity::RigidEntity(SWID id,VecPos pos,VecPos size):Entity(id){
	simMask = NOMASK;
	body = new BoxBody(pos,size);
	mass = 1;
	friction_coef = 0.7;
}

RigidEntity::RigidEntity(SWID id,RPolygon poly):Entity(id){
	simMask = NOMASK;
	body = new PolyBody(poly);
	mass = 1;
	friction_coef = 0.7;
}

RigidEntity::~RigidEntity(void){
}


void RigidEntity::setStep(Timer &timer) {

}
bool RigidEntity::update(){
	dirSpeed += force / mass;
	position += dirSpeed;
	return true;
}
bool RigidEntity::integrate(){

	return true;
}
void RigidEntity::addForce(AppliedForce f){
	force += f;
}
void RigidEntity::addForceOnPoint(AppliedForce f,VecPos p){
	force += f;
}