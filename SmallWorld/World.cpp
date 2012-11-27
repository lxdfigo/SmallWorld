#include "World.h"

using namespace swd;


void SmallWorld::init(WorldConfig config){
	enviroment.init(config.envCfg);
	timer.init(config.tmCfg);
}
void SmallWorld::advance(){
	timer.advance();
}
void SmallWorld::update(){
	advance();
	updateEntitys();
}
bool SmallWorld::registe(Entity *obj){
	obj->addAction(enviroment.getAction());
	entityTree.add(obj);
	return true;
}

void SmallWorld::updateEntitys(){
	entityTree.update(timer);
}

Entity *SmallWorld::getEntity(SWID oid){
	return entityTree.get(oid);
}