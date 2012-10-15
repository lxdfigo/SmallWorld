#include "RigidObj.h"
#include "RigidBody.h"

using namespace swd;

RigidObj::RigidObj(VecPos pos,double radius){
	simMask = NOMASK;
	body = new RigidBody(pos,radius);
}
RigidObj::RigidObj(VecPos pos,VecPos size){
	simMask = NOMASK;
	size /= 2;
	body = new RigidBody(pos - size,pos + size);
}

RigidObj::~RigidObj(void){
	delete body;
}

void RigidObj::advance(Time &time){
	VecPos mv = speed * time.step();
	move(mv);
	speed += appliedForce / mass * time.step();
	appliedForce.zero();
}

void RigidObj::move(VecPos mv){
	position += mv;
	body->move(mv);
}
void RigidObj::updateCollision(Collision *col){
	if (!(col->second->isMask(NoCollision) || isMask(NoCollision))){
		RigidObj *fir = dynamic_cast<RigidObj*>(col->first);
		RigidObj *sec = dynamic_cast<RigidObj*>(col->second);

		/// Reset the position of the Collision Object
		AABB& aabb = col->crossAABB;
		VecPos l = (aabb.end - aabb.begin) / speed;
		VecPos mv = -1 * l.minElement() * speed;
		move(mv);

		/// Update Speed of the two Collision Objects
		DirectSpeed &v1 = fir->getSpeed();
		DirectSpeed &v2 = sec->getSpeed();
		double m1 = fir->getMass();
		double m2 = sec->getMass();
		fir->setSpeed((v1 * (m1 - m2) + 2 * m2 * v2) / m1 + m2);
		sec->setSpeed((v2 * (m2 - m1) + 2 * m1 * v1) / m1 + m2);
	}
}
