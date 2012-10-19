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
	updateEnviroment();
	updateEntitys();
}
bool SmallWorld::registe(Entity *obj){
	entityTree.add(obj);
	return true;
}

void SmallWorld::updateEnviroment(){
	for(unsigned i = 0; i < entityTree.size(); ++i){
		enviroment.update(entityTree.get(i));
	}
}
void SmallWorld::updateEntitys(){
	entityTree.update(timer);
}

Entity *SmallWorld::getEntity(SWID oid){
	return entityTree.get(oid);
}