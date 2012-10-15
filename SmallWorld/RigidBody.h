#pragma once
#include "Body.h"

namespace swd{
	enum RigidType{
		BOX,
		SPHERE
	};
	class RigidBody : public Body{
	public:
		RigidBody(AABB aabb):type(BOX),box(aabb){}
		RigidBody(VecPos begin,VecPos end):type(BOX),box(begin,end){}
		RigidBody(VecPos center,double length):type(SPHERE),sphere(center,length){}

		~RigidBody(void);

		bool isCollided(Body*obj,Collision &col){
			return obj->checkRigidBodyCollided(this,col);
		}

		bool checkRigidBodyCollided(Body*obj,Collision &col);
		bool checkStaticBodyCollided(Body*obj,Collision &col);
		bool checkSoftBodyCollided(Body*obj,Collision &col);
		bool checkHydroBodyCollided(Body*obj,Collision &col);

		RigidType getType(){return type;}

		bool isContainVec(VecPos pos);
		virtual void move(VecPos mv);

		AABB& getAABB(){return box;}
	private:
		RigidType type;
		Sphere sphere;
		AABB box;
	};
}