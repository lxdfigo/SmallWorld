#include "ComEntity.h"
using namespace swd;

ComEntity::ComEntity(void)
{
}

ComEntity::~ComEntity(void)
{
}

bool ComEntity::isCross(Entity *entity,CollideInfo *col){
	bool result = false;
	for(unsigned int i = 0; i < entitys.size(); ++i){
		result |= entity->isCrossSingleEntity(entitys[i],col);
	}
	return result;
}
bool ComEntity::isCrossSingleEntity(Entity *entity,CollideInfo *col){ 
	bool result = false;
	for(unsigned int i = 0; i < entitys.size(); ++i){
		result |= entitys[i]->getBody()->isCross(entity->getBody(),col);
	}
	return result;
}
void ComEntity::setStep(Timer &timer){
	for(unsigned int i = 0; i < entitys.size(); ++i){
		entitys[i]->setStep(timer);
	}
}
bool ComEntity::update(){
	bool result = false;
	for(unsigned int i = 0; i < entitys.size(); ++i){
		result |= entitys[i]->update();
	}
	return result;
}
bool ComEntity::integrate(){
	bool result = false;
	for(unsigned int i = 0; i < entitys.size(); ++i){
		result |= entitys[i]->integrate();
	}
	return result;
}
void  ComEntity::transform(Transform& trans){
	for(unsigned int i = 0; i < entitys.size(); ++i){
		entitys[i]->transform(trans);
	}
}

//private function;
void ComEntity::computeMassAndCentroid(){
	mass = 0;
	VecPos cen;
	bool result = false;
	for(unsigned int i = 0; i < entitys.size(); ++i){
		cen += entitys[i]->getCentroid() * entitys[i]->getMass();
		mass += entitys[i]->getMass();
	}
	centroid = cen / mass;
}
void ComEntity::computeAABB(){
	VecPos vmax,vmin;
	vmax.setAll(MINNUM);
	vmin.setAll(MAXNUM);
	for(unsigned k = 0; k < entitys.size(); ++k){
		AABB &tab = entitys[k]->getAABB();
		for(unsigned i = 0; i < DIMENSION; ++i){
			if (vmax[i] < tab.end[i]) vmax[i] = tab.end[i];
			if (vmin[i] > tab.begin[i]) vmin[i] =tab.begin[i];
		}
	}
	aabb.reset(vmin,vmax);

}
MomentInertia ComEntity::getDisInertia(VecPos len){
	MomentInertia inert;

	inert[0][0] = (len[1] * len[1] + len[2] * len[2]);
	inert[1][1] = (len[0] * len[0] + len[2] * len[2]);
	inert[2][2] = (len[1] * len[1] + len[0] * len[0]);

	inert[0][1] = - len[0] * len[1];
	inert[2][1] = - len[2] * len[1];
	inert[0][2] = - len[0] * len[2];
	return inert;
}
void ComEntity::computeInertia(){
	for(unsigned int i = 0; i < entitys.size(); ++i){
		VecPos len = entitys[i]->getCentroid() - centroid;
		double m = entitys[i]->getMass();
		inertia += entitys[i]->getMomentInertia() + getDisInertia(len) * m;
	}
}