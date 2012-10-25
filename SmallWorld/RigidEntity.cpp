#include "RigidEntity.h"
#include "BoxBody.h"
#include "PolyBody.h"

using namespace swd;

RigidEntity::RigidEntity(SWID id,VecPos pos,VecPos size,double ma):Entity(id){
	simMask = NOMASK;
	body = new BoxBody(pos,size,ma);

}
RigidEntity::RigidEntity(SWID id,RPolygon poly, double ma):Entity(id){
	simMask = NOMASK;
	body = new PolyBody(poly,ma);
}

RigidEntity::~RigidEntity(void){
}


void RigidEntity::solveCollision(Entity*obj,Collision *col){
	body->solve(obj->getBody(),col);
}
void RigidEntity::updateCollision(Collision *col){
	getBody()->attack(col->second->getBody());
}
