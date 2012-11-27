#pragma once
#include "PhyStr.h"
#include "Timer.h"

namespace swd{

	struct CollideInfo{

	};

	class Body
	{
	public:
		Body(){}
		~Body(void){}

		virtual void transform(Transform & trans) = 0;
		virtual AABB getAABB() = 0;

		virtual bool isCross(Body * body, CollideInfo * col) = 0;

		virtual bool checkBoxCross(Body*obj,CollideInfo *col) = 0;
		virtual bool checkPolygonCross(Body*obj,CollideInfo *col) = 0;

		virtual VecPos getCenter() = 0;
		virtual MomentInertia getInertia() = 0;
	};
}