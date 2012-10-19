#pragma once
#include "Entity.h"
#include <vector>

namespace swd{
	class EntityTree
	{
	public:
		EntityTree();
		~EntityTree(void);

		void add(Entity *obj);
		Entity *get(int i){return entitys[i];}
		Entity *get(SWID oid);

		void solve(Entity *obj);
		unsigned size(){return entitys.size();}

		void update(Timer &timer);
	private:
		std::vector<Entity *> entitys;
		CollisionPool collisionPool;
	};
}