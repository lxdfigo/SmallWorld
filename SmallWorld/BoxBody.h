#pragma once
#include "Body.h"

namespace swd{

	class BoxBody: public Body
	{
	public:
		BoxBody(VecPos begin,VecPos end):
		  box(begin,end){
		  }
		~BoxBody(void){}
		void transform(Transform & trans);

		bool isCross(Body * body, CollideInfo * col){
			return body->checkBoxCross(this,col);
		}

		bool checkBoxCross(Body*obj,CollideInfo *col);
		bool checkPolygonCross(Body*obj,CollideInfo *col);

		AABB getAABB() {return box;}
		void collided();

		VecPos getCenter(){return box.getCenter();}
		MomentInertia getInertia();
	private:
		AABB box;
		AABB lastBox;
	};
}