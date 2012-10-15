#pragma once
#include "Body.h"

namespace swd{
	class HydroBody :
		public Body
	{
	public:
		HydroBody(void);
		~HydroBody(void);

		bool isCollided(Body*obj,Collision &col){
			return obj->checkHydroBodyCollided(this,col);
		}

		bool checkRigidBodyCollided(Body*obj,Collision &col);
		bool checkStaticBodyCollided(Body*obj,Collision &col);
		bool checkSoftBodyCollided(Body*obj,Collision &col);
		bool checkHydroBodyCollided(Body*obj,Collision &col);
	};
}