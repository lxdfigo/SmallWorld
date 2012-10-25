#pragma once
#include "Body.h"

namespace swd{
	class Entity
	{
	public:
		Entity(SWID id = ""):simMask(NOMASK),oID(id),body(NULL){}
		virtual ~Entity(void){
			if (body != NULL) delete body;
		}
		virtual void solveCollision(Entity*obj,Collision *col) = 0;
		virtual void callbackCollision(Collision *col) = 0;
		virtual void updateCollision(Collision *col) = 0;

		virtual bool solve(Entity *obj, Collision * col){
			if (body->isCross(obj->getBody(),col)){
				solveCollision(obj,col);
				return true;
			}
			return false;
		}
		virtual bool collided(Collision *col){
			updateCollision(col);
			callbackCollision(col);
			return true;
		}
		virtual bool operator != (Entity& entity) const{
			return oID.compare(entity.getID()) != 0;
		}
		virtual void advance(Timer &timer){
			body->advance(timer);
		}

		virtual void  transform(Transform& trans){body->transform(trans);}
		virtual void  addForce(AppliedForce force) { body->addForce(force);}
		virtual bool  isMask(int mask){ return (mask & simMask) != NOMASK;} 
		virtual void  setMask(int mask){simMask |= mask;}
		virtual SWID  getID(){return oID;}
		virtual Body* getBody(){return body;}
		virtual AABB  getAABB(){return body->getAABB();}
	protected:
		SWID oID;
		int simMask;
		Body *body;
	};

}