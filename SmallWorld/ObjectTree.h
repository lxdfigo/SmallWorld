#pragma once
#include "Object.h"
#include <vector>

namespace swd{
	class ObjectTree
	{
	public:
		ObjectTree(void);
		~ObjectTree(void);

		void add(Object *obj);
		Object *get(int i){return objects[i];}
		unsigned size(){return objects.size();}

		void update(Time &time);
		void updateObject(int i,Time &time);
	private:
		std::vector<Object *> objects;
	};
}