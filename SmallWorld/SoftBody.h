#pragma once
#include "Body.h"

namespace swd{
	class SoftBody :
		public Body
	{
	public:
		SoftBody(void);
		~SoftBody(void);

		bool isCollided(Body*obj,Collision &col){
			return obj->checkSoftBodyCollided(this,col);
		}

		bool checkRigidBodyCollided(Body*obj,Collision &col);
		bool checkStaticBodyCollided(Body*obj,Collision &col);
		bool checkSoftBodyCollided(Body*obj,Collision &col);
		bool checkHydroBodyCollided(Body*obj,Collision &col);
	};
}