#pragma once
#include "Basic.h"

namespace swd{

	class Object;

	struct AABB
	{
		VecPos begin;
		VecPos end;

		AABB(const AABB& aabb):begin(aabb.begin),end(aabb.end){}
		AABB(VecPos b,VecPos e):begin(b),end(e){}
		AABB(){}

		bool isCross(AABB &aabb){
			if (aabb.isContain(begin) || isContain(aabb.begin)){
				return true;
			}
			return false;
		}

		bool isCross(AABB &aabb,AABB &cross){
			if (aabb.begin > begin && end > aabb.end) {
				cross.begin = (aabb.begin);
				cross.end = (aabb.end);
				return true;
			}else if (aabb.begin < begin && end < aabb.end) {
				cross.begin = (begin);
				cross.end = (end);
				return true;
			}else if (aabb.isContain(begin)){
				cross.begin = (begin);
				cross.end = (aabb.end);
				return true;
			}else if (isContain(aabb.begin)){
				cross.begin = (aabb.begin);
				cross.end = (end);
				return true;
			}
			return false;
		}

		bool isContain(VecPos pos){
			if ( pos > begin && pos < end){
				return true;
			}
			return false;
		}
	};
	struct Sphere
	{
		VecPos center;
		double length;

		Sphere(VecPos c,double l):center(c),length(l){}
		Sphere():length(0){}

		bool isContain(VecPos pos){
			if (pos.SquaredDistance(center) < length * length){
				return true;
			}
			return false;
		}
	};


	struct Collision{
		Object *first;
		Object *second;
		AABB crossAABB;
		Collision(Object *f,Object *s):first(f),second(s){}
		~Collision(){
			//if (cross != NULL) delete cross;
		}
	};
}