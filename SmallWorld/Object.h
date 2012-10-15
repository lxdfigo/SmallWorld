#pragma once
#include "Body.h"
#include "Time.h"

namespace swd{
	class Object
	{
	public:
		Object(void);
		~Object(void);

		virtual void addForce(AppliedForce force) = 0;
		virtual void advance(Time &time) = 0;

		Body* getBody(){return body;}

		bool isMask(enum SimMask mask){ return (mask & simMask) == NOMASK;} 

		virtual void callbackCollision(Collision *col) = 0;
		virtual void updateCollision(Collision *col) = 0;
		virtual bool checkCollision(Object *obj){
			Collision col(this,obj);
			if (body->isCollided(obj->getBody(),col)){
				updateCollision(&col);
				callbackCollision(&col);
				return true;
			}
			return false;
		}
	protected:
		int id;
		int simMask;
		Body *body;
	};

}