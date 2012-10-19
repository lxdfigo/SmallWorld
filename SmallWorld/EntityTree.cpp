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

void EntityTree::solve(Entity *obj){
	for(unsigned j = 0; j < entitys.size(); ++j){
		Collision *col = collisionPool.current();
		col->first = obj;
		col->second = entitys[j];
		if (obj->solve(entitys[j],col)){
			collisionPool.increase();
		}
	}
}

void EntityTree::update(Timer &timer){
	for(unsigned i = 0; i < entitys.size(); ++i){
		entitys[i]->advance(timer);
	}

	for(unsigned i = 0; i < entitys.size(); ++i){
		solve(entitys[i]);
	}

	for(unsigned i = 0; i < collisionPool.size(); ++i){
		collisionPool[i]->first->checkCollision(collisionPool[i]);
	}
	collisionPool.clear();
}


Entity *EntityTree::get(SWID oid){
	for(unsigned i = 0; i < entitys.size(); ++i){
		if (entitys[i]->getID() == oid)
			return entitys[i];
	}
	return NULL;
}