#pragma once
#include "PhyStr.h"

namespace swd{

	class Body
	{
	public:
		Body(void);
		virtual ~Body(void);

		virtual void move(VecPos mv) = 0;

		virtual bool isCollided(Body*obj,Collision &col) = 0;

		virtual bool checkRigidBodyCollided(Body*obj,Collision &col) = 0;
		virtual bool checkStaticBodyCollided(Body*obj,Collision &col) = 0;
		virtual bool checkSoftBodyCollided(Body*obj,Collision &col) = 0;
		virtual bool checkHydroBodyCollided(Body*obj,Collision &col) = 0;

		virtual AABB& getAABB() = 0;
	};
}