#pragma once
#include "object.h"

namespace swd{
	class RigidObj :
		public Object
	{
	public:
		RigidObj(VecPos pos,double radius);
		RigidObj(VecPos pos,VecPos size);
		~RigidObj(void);
		virtual void addForce(AppliedForce force){ appliedForce += force; }

		virtual void advance(Time &time);

		virtual void updateCollision(Collision *col);

		virtual void move(VecPos mv);

		double getMass(){return mass;}
		void setMass(double m){mass = m;}
		void setSpeed(DirectSpeed s){speed = s;}
		DirectSpeed getSpeed(){return speed;}
	private:
		double mass;
		AppliedForce appliedForce;
		DirectSpeed speed;
		double rubforce;
		VecPos position;
		double tenacity;
	};
}