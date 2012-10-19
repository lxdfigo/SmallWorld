#pragma once
#include "Entity.h"
#include "Timer.h"
#include "PhyStr.h"

namespace swd{
	class Entity
	{
	public:
		Entity(SWID id = ""):simMask(NOMASK),oID(id){}
		~Entity(void){}

		virtual void addForce(AppliedForce force) = 0;
		virtual void advance(Timer &timer) = 0;

		virtual void solveCollision(Collision *col) = 0;
		virtual void callbackCollision(Collision *col) = 0;
		virtual void updateCollision(Collision *col) = 0;
		virtual AABB getAABB() = 0;
		virtual void transform(Transform& mv) = 0;

		virtual bool isCollided(Entity*obj,Collision *col) = 0;
		virtual bool checkRigidEntityCollided(Entity*obj,Collision *col) = 0;
		virtual bool checkStaticEntityCollided(Entity*obj,Collision *col) = 0;
		virtual bool checkSoftEntityCollided(Entity*obj,Collision *col) = 0;
		virtual bool checkHydroEntityCollided(Entity*obj,Collision *col) = 0;

		virtual bool solve(Entity *obj, Collision * col){
			if (isCollided(obj,col)){
				solveCollision(col);
				return true;
			}
			return false;
		}
		virtual bool checkCollision(Collision *col){
			updateCollision(col);
			callbackCollision(col);
			return true;
		}
		bool isMask(int mask){ return (mask & simMask) != NOMASK;} 
		void setMask(int mask){simMask |= mask;}
		SWID getID(){return oID;}
	protected:
		SWID oID;
		int simMask;
	};

}