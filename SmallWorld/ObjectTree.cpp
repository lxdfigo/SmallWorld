#include "ObjectTree.h"
using namespace swd;

ObjectTree::ObjectTree(void)
{
}

ObjectTree::~ObjectTree(void)
{
}
void ObjectTree::add(Object *obj){
	objects.push_back(obj);
}

void ObjectTree::update(Time &time){
	for(unsigned i = 0; i < objects.size(); ++i){
		updateObject(i,time);
	}
}

void ObjectTree::updateObject(int index,Time &time){
	bool isCollision = false;
	Object * obj = objects[index];
	obj->advance(time);
	for(unsigned i = index + 1; i < objects.size(); ++i){
		if (objects[i] != obj)
			objects[i]->checkCollision(obj);
	}

}