#include "Enviroment.h"
using namespace swd;

Enviroment::Enviroment(void){
	gravity.Elements[1] = -9.8;
}

Enviroment::~Enviroment(void)
{
}

void Enviroment::update(Object *obj){
	if (!obj->isMask(NoGravity)){
		obj->addForce(gravity);
	}
	if (!obj->isMask(NoResistence)){
		obj->addForce(wind);
	}
}