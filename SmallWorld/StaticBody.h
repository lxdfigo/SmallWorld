#pragma once
#include "Body.h"

namespace swd{
	class StaticBody :
		public Body
	{
	public:
		StaticBody(void);
		~StaticBody(void);

		bool isCollided(Body*obj,Collision &col){
			return obj->checkStaticBodyCollided(this,col);
		}

		bool checkRigidBodyCollided(Body*obj,Collision &col);
		bool checkStaticBodyCollided(Body*obj,Collision &col);
		bool checkSoftBodyCollided(Body*obj,Collision &col);
		bool checkHydroBodyCollided(Body*obj,Collision &col);
	};
}