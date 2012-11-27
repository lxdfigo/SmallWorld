#include "EntityTree.h"
using namespace swd;

EntityTree::EntityTree(void)
{
}

EntityTree::~EntityTree(void)
{
}
void EntityTree::add(Entity *obj){
	entitys.push_back(obj);
}

void EntityTree::checkCross(Entity *obj){
	for(unsigned j = 0; j < entitys.size(); ++j){
		if ((*obj) != (*entitys[j])){
			Entity *obj2 = entitys[j];
			if (obj->getAABB().isCross(entitys[j]->getAABB())){
				Collision *col = collisionPool.current();
				col->first = obj;
				col->second = entitys[j];
				collisionPool.increase();
			}
		}
	}
}

void EntityTree::solveCross(Entity *obj){
	//for(unsigned j = 0; j < entitys.size(); ++j){
	//	if ((*obj) != (*entitys[j])){
	//		Entity *obj2 = entitys[j];
	//		if (obj->getAABB().isCross(entitys[j]->getAABB())){
	//			obj->solve(entitys[j],NULL);
	//		}
	//	}
	//}
}

void EntityTree::update(Timer &timer){
	for(unsigned i = 0; i < entitys.size(); ++i){
		entitys[i]->setStep(timer);
		entitys[i]->applyActions();
		entitys[i]->applyConstraints();
		entitys[i]->integrate();
	}
	for(unsigned i = 0; i < entitys.size(); ++i){
		checkCross(entitys[i]);
	}
}


Entity *EntityTree::get(SWID oid){
	for(unsigned i = 0; i < entitys.size(); ++i){
		if (entitys[i]->getID() == oid)
			return entitys[i];
	}
	return NULL;
}