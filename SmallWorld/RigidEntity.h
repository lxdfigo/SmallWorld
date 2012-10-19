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

		virtual void addForce(AppliedForce force){ appliedForce += force; }
		virtual void advance(Timer &timer);
		virtual void transform(Transform& trans);
		double getMass(){return mass;}
		void setMass(double m){mass = m;}
		void setSpeed(DirectSpeed s){speed = s;}
		DirectSpeed getSpeed(){return speed;}

		virtual void solveCollision(Collision *col);
		virtual void updateCollision(Collision *col);
		virtual void callbackCollision(Collision *col){}


		bool isCollided(Entity*obj,Collision *col){
			return obj->checkRigidEntityCollided(this,col);
		}

		bool checkRigidEntityCollided(Entity*obj,Collision *col);
		bool checkStaticEntityCollided(Entity*obj,Collision *col);
		bool checkSoftEntityCollided(Entity*obj,Collision *col);
		bool checkHydroEntityCollided(Entity*obj,Collision *col);

		AABB getAABB(){return polygon.getAABB();}
		RPolygon& getPolygon(){return polygon;}
	private:
		RPolygon polygon;
		double mass;
		AppliedForce appliedForce;
		DirectSpeed speed;
		double rubforce;
		double tenacity;
	};
}