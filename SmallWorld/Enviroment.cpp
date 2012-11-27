#include "Enviroment.h"
using namespace swd;

Enviroment::Enviroment(void){
	action = new EnviForceAction("environment");
}

Enviroment::~Enviroment(void){
	delete action;
}

void Enviroment::init(EnvConfig config){
	action->addForce(config.gravity);
	action->addForce(config.wind);
}
void Enviroment::update(Entity *obj){

}