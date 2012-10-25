#pragma once
#include "Body.h"

namespace swd{
	class PolyBody: public Body
	{
	public:
		PolyBody(RPolygon poly,double ma):polygon(poly),mass(ma){}
		~PolyBody(void){}

		void advance(Timer &timer);
		void transform(Transform & trans);
		void addForce(AppliedForce force){ appliedForce += force; }

		AABB getAABB(){return polygon.getAABB();}

		double getMass(){ return mass;}
		DirectSpeed getSpeed(){return DirectSpeed();}
		void attack(Body *body){}

		bool solve(Body * body, Collision * col){
			return body->solvePolygon(this,col);
		}
		bool isCross(Body * body, Collision * col){
			return body->checkPolygonCross(this,col);
		}

		bool checkBoxCross(Body*obj,Collision *col);
		bool checkPolygonCross(Body*obj,Collision *col);
		bool solveBox(Body*obj,Collision *col);
		bool solvePolygon(Body*obj,Collision *col);
	private:
		AppliedForce appliedForce;
		RPolygon polygon;
		double mass;
	};
}