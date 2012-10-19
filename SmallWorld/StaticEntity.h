#pragma once
#include "Entity.h"

namespace swd{
	class StaticEntity :
		public Entity
	{
	public:
		StaticEntity(SWID id);
		~StaticEntity(void);

		virtual void addForce(AppliedForce force){}

		virtual void updateCollision(Collision *col);
		virtual void callbackCollision(Collision *col){}
		bool isCollided(Entity*obj,Collision *col){
			return obj->checkStaticEntityCollided(this,col);
		}

		bool checkRigidEntityCollided(Entity*obj,Collision *col);
		bool checkStaticEntityCollided(Entity*obj,Collision *col);
		bool checkSoftEntityCollided(Entity*obj,Collision *col);
		bool checkHydroEntityCollided(Entity*obj,Collision *col);
	private:
		double rubforce;
		double tenacity;
	};
}
