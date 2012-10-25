#include "StaticEntity.h"
#include "BoxBody.h"
#include "PolyBody.h"

using namespace swd;

StaticEntity::StaticEntity(SWID id,VecPos pos,VecPos size):Entity(id){
	simMask = STATIC;
	body = new BoxBody(pos,size,MAXNUM);

}
StaticEntity::StaticEntity(SWID id,RPolygon poly):Entity(id){
	simMask = STATIC;
	body = new PolyBody(poly,MAXNUM);
}

StaticEntity::~StaticEntity(void)
{
}

void StaticEntity::solveCollision(Entity*obj,Collision *col){
	return;
}

void StaticEntity::updateCollision(Collision *col){
	return;
}
