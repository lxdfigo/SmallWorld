#pragma once
#include "Body.h"

namespace swd{
	class PolyBody: public Body
	{
	public:
		PolyBody(RPolygon poly):polygon(poly){}
		~PolyBody(void){}

		void transform(Transform & trans);

		AABB getAABB(){return polygon.getAABB();}

		bool isCross(Body * body, CollideInfo * col){
			return body->checkPolygonCross(this,col);
		}

		bool checkBoxCross(Body*obj,CollideInfo *col);
		bool checkPolygonCross(Body*obj,CollideInfo *col);

		VecPos getCenter(){return polygon.getCenter();}
		MomentInertia getInertia() { return MomentInertia();}
	private:
		RPolygon polygon;
	};
}