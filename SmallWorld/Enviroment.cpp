#include "Enviroment.h"
using namespace swd;

Enviroment::Enviroment(void){
}

Enviroment::~Enviroment(void)
{
}

void Enviroment::init(EnvConfig config){
	gravity = config.gravity;
	wind = config.wind;
}
void Enviroment::update(Entity *obj){
	if (!obj->isMask(NoGravity)){
		obj->addForce(gravity);
	}
	if (!obj->isMask(NoResistence)){
		obj->addForce(wind);
	}
}