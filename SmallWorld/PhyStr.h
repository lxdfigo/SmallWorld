#pragma once
#include "Basic.h"

namespace swd{

	class Entity;

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

			if (isContain(aabb.end)){
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
	struct RSphere
	{
		VecPos center;
		double length;

		RSphere(VecPos c,double l):center(c),length(l){}
		RSphere():length(0){}

		bool isContain(VecPos pos){
			if (pos.SquaredDistance(center) < length * length){
				return true;
			}
			return false;
		}
	};

	struct RPolygon{
		std::vector<VecPos> vexs;
		RPolygon(){}
		RPolygon(const AABB &aabb){
		}
		RPolygon(RPolygon &poly){
			vexs.resize(poly.vexs.size());
			for(unsigned i = 0; i < poly.vexs.size(); ++i){
				vexs[i] = poly.vexs[i];
			}
		}


		~RPolygon(){}

		void add(VecPos pos){vexs.push_back(pos);}
		void clear(){vexs.clear();}
		inline double getTriangleArea(VecPos v1,VecPos v2){
			return v1.Elements[0] * v2.Elements[1] - v2.Elements[0] * v1.Elements[1];
		}
		inline double getTriangleArea(VecPos v1,VecPos v2,VecPos p){
			double result = abs(
				p.Elements[0] * v1.Elements[1] -
				p.Elements[0] * v2.Elements[1] -
				v1.Elements[0] * p.Elements[1] +
				v1.Elements[0] * v2.Elements[1] +
				v2.Elements[0] * p.Elements[1] -
				v2.Elements[0] * v1.Elements[1]
				);
			return result;
		}
		bool isContain(VecPos pos){
			bool inside = false;
			double polygon_area = 0;
			double trigon_area = 0;

			for (unsigned i = 0, j = vexs.size() - 1;i < vexs.size();j = i++){
				polygon_area += getTriangleArea(vexs[i],vexs[j]);
				trigon_area += getTriangleArea(vexs[i],vexs[j],pos);
			}

			trigon_area *= 0.5;
			polygon_area = abs(polygon_area * 0.5);
			if ( fabs(trigon_area - polygon_area) < 1e-7 )
				inside = true;
			return inside;
		}
		bool isCross(RPolygon &poly,RPolygon &cross){
			for(unsigned i = 0; i < vexs.size(); ++i){
				if (poly.isContain(vexs[i]))
					return true;
			}
			for(unsigned i = 0; i < poly.vexs.size(); ++i){
				if (isContain(poly.vexs[i]))
					return true;
			}
			return false;
		}

		AABB getAABB(){
			VecPos b(MAXNUM),e(MINNUM);
			for(unsigned i = 0; i < DIMENSION; ++i){
				for(unsigned j = 0; j < vexs.size(); ++j){
					if (b.Elements[i] > vexs[j].Elements[i]) b.Elements[i] = vexs[j].Elements[i];
					if (e.Elements[i] < vexs[j].Elements[i]) e.Elements[i] = vexs[j].Elements[i];
				}
			}
			return AABB(b,e);
		}

		void generateByBox(VecPos p1,VecPos p2){
			VecPos vex;
			generateVex(p1,p2,vex,DIMENSION-1);
		}
	private:
		void generateVex(VecPos p1,VecPos p2,VecPos &vex,int loop){
			if (loop < 0){	add(vex);	return;	}
			vex.Elements[loop] = p1.Elements[loop];
			generateVex(p1,p2,vex,loop-1);
			vex.Elements[loop] = p2.Elements[loop];
			generateVex(p1,p2,vex,loop-1);
		}
	};

	struct Collision{
	public:
		Entity *first;
		Entity *second;
		RPolygon crossArea;
		bool isCollide;
		Collision():isCollide(false),first(NULL),second(NULL){}

		Collision(const Collision & col){
			first = col.first;
			second = col.second;
			crossArea = col.crossArea;
			isCollide = col.isCollide;
		}

		Collision(Entity *f,Entity *s):isCollide(false),first(f),second(s){}
		~Collision(){
		}
		void reset(){
			first = NULL;
			second = NULL;
			isCollide = false;
		}
	};

	class CollisionPool{
	private:
		std::vector<Collision> collisions;
		unsigned int _size;
		unsigned int _cur;
	public:
		CollisionPool(unsigned int s = 100):_size(s),_cur(0){
			collisions.resize(_size);
		}
		unsigned size(){return _cur;}

		Collision * current(){
			if (_cur >= _size){
				_size = _size<<1;
				collisions.reserve(_size);
			}
			return &collisions[_cur];
		}
		void increase(){_cur++;}
		Collision * get(unsigned i){
			return &collisions[i];
		}
		void clear(){
			_cur = 0;
		}
		Collision * operator[](unsigned i){
			return get(i);
		}
	};
}