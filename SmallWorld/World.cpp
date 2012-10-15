#include "World.h"

using namespace swd;

SmallWorld::SmallWorld(void)
{
}

SmallWorld::~SmallWorld(void)
{
}

void SmallWorld::advance(){
	time.advance();

	updateEnviroment();
	objectTree.update(time);
	updateObjects();
}
bool SmallWorld::registe(Object *obj){
	objectTree.add(obj);
	return true;
}

void SmallWorld::updateEnviroment(){
	for(unsigned i = 0; i < objectTree.size(); ++i){
		enviroment.update(objectTree.get(i));
	}
}
void SmallWorld::updateObjects(){
	objectTree.update(time);
}