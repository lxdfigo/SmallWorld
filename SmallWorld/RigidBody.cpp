#include "RigidBody.h"
using namespace swd;



RigidBody::~RigidBody(void)
{
}

void RigidBody::move(VecPos mv){
	switch(type){
		case BOX:
			box.begin += mv;
			box.end += mv;
			break;
		case SPHERE:
			sphere.center += mv;
			break;
	}
}
bool RigidBody::isContainVec(VecPos pos){
	switch(type){
		case BOX:
			return box.isContain(pos);
		case SPHERE:
			return sphere.isContain(pos);
	}
	return false;
}
bool RigidBody::checkRigidBodyCollided(Body*obj,Collision &col){
	RigidBody *rbody = dynamic_cast<RigidBody*>(obj);
	if (rbody->getType() == BOX && type == BOX){
		if (box.isCross(rbody->getAABB(),col.crossAABB)){
			return true;
		}
	}else if (rbody->getType() == SPHERE && type == BOX){ 
		
	}
	return false;
}
bool RigidBody::checkStaticBodyCollided(Body*obj,Collision &col){
	return false;
}
bool RigidBody::checkSoftBodyCollided(Body*obj,Collision &col){

	return false;
}
bool RigidBody::checkHydroBodyCollided(Body*obj,Collision &col){

	return false;
}