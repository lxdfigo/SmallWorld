#include "RigidEntity.h"

using namespace swd;

RigidEntity::RigidEntity(SWID id,VecPos pos,VecPos size,double ma):mass(ma),Entity(id){
	simMask = NOMASK;
	polygon.generateByBox(pos,pos+size);

}
RigidEntity::RigidEntity(SWID id,RPolygon poly, double mass):polygon(poly){
	simMask = NOMASK;
}

RigidEntity::~RigidEntity(void){
}

void RigidEntity::advance(Timer &timer){
	VecPos mv = speed * timer.step();
	transform(Transform(mv));
	speed += appliedForce / mass * timer.step();
	appliedForce.zero();
}

void RigidEntity::transform(Transform& trans){
	if (isMask(STATIC)) return;
	for(unsigned i = 0; i < polygon.vexs.size(); ++i){
		polygon.vexs[i] = trans.trans(polygon.vexs[i]);
	}
}

void RigidEntity::solveCollision(Collision *col){

	if (!(col->second->isMask(NoCollision) || isMask(NoCollision))){
		/// Reset the position of the Collision Entity
		AABB& aabb = col->crossArea.getAABB();
		VecPos l = (aabb.end - aabb.begin) / speed;
		VecPos mv = -1 * l.minElement() * speed;
		transform(Transform(mv));
	}
}
void RigidEntity::updateCollision(Collision *col){
	if (!(col->second->isMask(NoCollision) || isMask(NoCollision))){

		/// Update Speed of the two Collision Entitys
		RigidEntity *fir = dynamic_cast<RigidEntity*>(col->first);
		RigidEntity *sec = dynamic_cast<RigidEntity*>(col->second);
		DirectSpeed &v1 = fir->getSpeed();
		DirectSpeed &v2 = sec->getSpeed();
		double m1 = fir->getMass();
		double m2 = sec->getMass();
		fir->setSpeed((v1 * (m1 - m2) + 2 * m2 * v2) / m1 + m2);
		sec->setSpeed((v2 * (m2 - m1) + 2 * m1 * v1) / m1 + m2);
		
	}
}

bool RigidEntity::checkRigidEntityCollided(Entity*obj,Collision *col){
	RigidEntity *rbody = dynamic_cast<RigidEntity*>(obj);
	if (polygon.isCross(rbody->getPolygon(),col->crossArea)){
		return true;
	}
	return false;
}
bool RigidEntity::checkStaticEntityCollided(Entity*obj,Collision *col){
	return false;
}
bool RigidEntity::checkSoftEntityCollided(Entity*obj,Collision *col){
	return false;
}
bool RigidEntity::checkHydroEntityCollided(Entity*obj,Collision *col){

	return false;
}