#pragma once
#include "Entity.h"

namespace swd{
	class HydroEntity :
		public Entity
	{
	public:
		HydroEntity(SWID id);
		~HydroEntity();
		virtual void addForce(AppliedForce force){}
		bool isCollided(Entity*obj,Collision *col){
			return obj->checkHydroEntityCollided(this,col);
		}

		bool checkRigidEntityCollided(Entity*obj,Collision *col);
		bool checkStaticEntityCollided(Entity*obj,Collision *col);
		bool checkSoftEntityCollided(Entity*obj,Collision *col);
		bool checkHydroEntityCollided(Entity*obj,Collision *col);
	private:
		double resistance;
	};
}
