#pragma once
#include "Entity.h"

namespace swd{
	class SoftEntity :
		public Entity
	{
	public:
		SoftEntity(SWID id);
		~SoftEntity(void);
		virtual void addForce(AppliedForce force){}
		bool isCollided(Entity*obj,Collision *col){
			return obj->checkSoftEntityCollided(this,col);
		}

		bool checkRigidEntityCollided(Entity*obj,Collision *col);
		bool checkStaticEntityCollided(Entity*obj,Collision *col);
		bool checkSoftEntityCollided(Entity*obj,Collision *col);
		bool checkHydroEntityCollided(Entity*obj,Collision *col);
	private:
		double elasticity;
	};
}
