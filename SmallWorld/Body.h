#pragma once
#include "PhyStr.h"
#include "Timer.h"

namespace swd{
	class Body
	{
	public:
		Body():isMoved(false){}
		~Body(void){}

		virtual void advance(Timer &timer) = 0;
		virtual void transform(Transform & trans) = 0;
		virtual AABB getAABB() = 0;
		virtual void addForce(AppliedForce force) = 0;
		virtual void attack(Body *body) = 0;
		virtual DirectSpeed getSpeed() = 0;
		virtual double getMass() = 0;

		virtual bool isCross(Body * body, Collision * col) = 0;
		virtual bool solve(Body * body, Collision * col) = 0;

		virtual bool checkBoxCross(Body*obj,Collision *col) = 0;
		virtual bool checkPolygonCross(Body*obj,Collision *col) = 0;
		virtual bool solveBox(Body*obj,Collision *col) = 0;
		virtual bool solvePolygon(Body*obj,Collision *col) = 0;
	protected:
		bool isMoved;
	};
}