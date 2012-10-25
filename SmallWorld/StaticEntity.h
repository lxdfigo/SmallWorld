#pragma once
#include "Entity.h"

namespace swd{
	class StaticEntity :
		public Entity
	{
	public:
		StaticEntity(SWID id,VecPos pos,VecPos size);
		StaticEntity(SWID id,RPolygon poly);
		~StaticEntity(void);

		virtual void solveCollision(Entity*obj,Collision *col);
		virtual void updateCollision(Collision *col);
		virtual void callbackCollision(Collision *col){}
		virtual void advance(Timer &timer){}
		virtual void transform(Transform& trans){}
	};
}
