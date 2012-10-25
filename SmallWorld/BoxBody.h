#pragma once
#include "Body.h"

namespace swd{
	class BoxBody: public Body
	{
	public:
		BoxBody(VecPos begin,VecPos end,double ma):box(begin,end),mass(ma){}
		~BoxBody(void){}
		void advance(Timer &timer);
		void transform(Transform & trans);
		bool solve(Body * body, Collision * col){
			return body->solveBox(this,col);
		}
		bool isCross(Body * body, Collision * col){
			return body->checkBoxCross(this,col);
		}

		bool checkBoxCross(Body*obj,Collision *col);
		bool checkPolygonCross(Body*obj,Collision *col);
		bool solveBox(Body*obj,Collision *col);
		bool solvePolygon(Body*obj,Collision *col);


		virtual void addForce(AppliedForce force){ appliedForce += force; }
		double getMass(){return mass;}
		void setMass(double m){mass = m;}
		void setSpeed(DirectSpeed s){speed = s;}
		DirectSpeed getSpeed(){return speed;}
		AABB getAABB() {return box;}
		void stop(){setSpeed(VecPos());}
		VecPos sloveLineCrossAABB(AABB &aabb,Line &line,VecPos &vec);
		void attack(Body *body);
	private:
		AppliedForce appliedForce;
		AABB box;
		double mass;
		DirectSpeed speed;
		AABB lastBox;
		double rubforce;
		double tenacity;
	};
}