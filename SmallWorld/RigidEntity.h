#pragma once
#include "Entity.h"

namespace swd{
	class RigidEntity :
		public Entity
	{
	public:
		RigidEntity(SWID id,VecPos pos,VecPos size, double mass);
		RigidEntity(SWID id,RPolygon poly, double mass);
		~RigidEntity(void);


		virtual void solveCollision(Entity*obj,Collision *col);
		virtual void updateCollision(Collision *col);
		virtual void callbackCollision(Collision *col){}

	};
}