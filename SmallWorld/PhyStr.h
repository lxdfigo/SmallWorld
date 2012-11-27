#pragma once
#include "Basic.h"

namespace swd{

	class Entity;

	struct Shape{
	protected:
		VecPos center;
	public:
		VecPos getCenter(){return center;}
	};


	struct Line : public Shape{
	public:
		VecPos begin;
		VecPos end;

	public:
		Line(const Line& line):begin(line.begin),end(line.end){	}
		Line(VecPos b,VecPos e):begin(b),end(e){}
		Line(){}

		bool isCrossPlan(int d,double v){
			double len = abs(end[d] - begin[d]);
			double l = v - (end[d] > begin[d] ? begin[d] : end[d]);
			if (l > 0 && l < len)  return true;
			return false;
		}
		bool isCross(Line & line){
			return false;
		}
		bool getPos(int d,double v,VecPos &result){
			if (!isCrossPlan(d,v)) return false;
			result[d] = v;
#ifdef TWO_DIMENSION_PHYSICAL_ENGINE
			for(int i = 0; i < DIMENSION; ++i){
				if (d != i){
					result[i] = (end[i] - begin[i]) * (result[d] - begin[d]) / (end[d] - begin[d]) + begin[i];
				}
			}
#else

#endif
			return true;
		}
		int PointAtLineLeftRight(VecPos ptTest){
			VecPos v1, v2;
			v1 = begin - ptTest;
			v2 = end - ptTest;
			
			//problem 2D
			double nRet = begin[0] * end[1] - begin[1] * end[0];
			if (nRet == 0)
				return 0;
			else if (nRet > 0)
				return 1;
			else if (nRet < 0)
				return -1;

			return 0;
		}
		VecPos getVec(){
			return begin - end;
		}
		VecPos getReverseVec(){
			return end - begin;
		}
		double Length(){
			return begin.Distance(end);
		}
		double Length2(){
			return begin.SquaredDistance(end);
		}
		int LongestDimension(){
			VecPos pos = getVec();
			double dis = -1;
			int dim = 0;
			for(int i = 0; i < DIMENSION; i++){
				double tmp = fabs(end[i] - begin[i]);
				if (tmp > dis){
					dis = tmp;
					dim = i;
				}
			}
			return dim;
		}
	};


	struct Triangle : public Shape{
	private:
		VecPos v1,v2,v3;
	public:
		Triangle(const Triangle& tri):v1(tri.v1),v2(tri.v2),v3(tri.v3){}
		Triangle(VecPos p1,VecPos p2,VecPos p3):v1(p1),v2(p2),v3(p3){}
	};

	struct AABB : public Shape
	{
	private:
		VecPos half_dimension;
	public:
		VecPos begin;
		VecPos end;
		AABB(const AABB& aabb):begin(aabb.begin),end(aabb.end){
			standardizate();
		}
		AABB(VecPos b,VecPos e):begin(b),end(e){
			standardizate();
		}
		AABB(){}

		void reset(const VecPos& b,const VecPos& e){
			begin = b; end = e;
			standardizate();
		}
		void standardizate(){
			for(int i = 0; i <DIMENSION; ++i){
				if (end[i] < begin[i]){
					double tmp = begin[i];
					begin[i] = end[i];
					end[i] = tmp;
				}
			}
			center = (begin + end) * 0.5;
			half_dimension = (end - begin) * 0.5;
	
		}
		bool isCross(AABB &aabb){
			for(int i = 0; i < DIMENSION; i++){
				if (fabs(aabb.center[i] - center[i]) > aabb.half_dimension[i] + half_dimension[i])
					return false;
			}
			return true;
		}
		int getCrossPlan(AABB &aabb){
			double dis = MINNUM;
			int plan = -1;
			for(int i = 0; i < DIMENSION; i++){
				double tmp = fabs(aabb.center[i] - center[i]);
				if (tmp < aabb.half_dimension[i] + half_dimension[i] && tmp > dis){
					plan = i;
					dis = tmp;
				}
			}
			return plan;
		}
		bool isContain(VecPos& pos){
			if (pos < begin || pos > end){
				return false;
			}
			return true;
		}
		//Solve the force line cross the AABB and return the longest force. from begin to end pos.
		bool solveLine(Line &line){
			if (isContain(line.begin) && isContain(line.end))
				return true;

			double dis = 0;
			bool sign = false;
			for(int i = 0; i < DIMENSION; ++i){
				VecPos v1;
				if (line.getPos(i,begin[i],v1)){
					double tmp = line.begin.SquaredDistance(v1);
					if (tmp > dis){
						line.end = v1;
						dis = tmp;
						sign = true;
					}
				}
				if (line.getPos(i,end[i],v1)){
					double tmp = line.begin.SquaredDistance(v1);
					if (tmp > dis){
						line.end = v1;
						dis = tmp;
						sign = true;
					}
				}
			}
			return sign;
		}

		//problem 2D only
		void getVexs(VecPos* vexs){
			vexs[0] = begin;
			vexs[1] = end;
			vexs[2] = VecPos(begin[0],end[1]);
			vexs[3] = VecPos(end[0],begin[1]);
		}
	};
	struct RSphere : public Shape
	{
	private:
		double length;
	public:
		RSphere(VecPos c,double l):length(l){
			center = c;
		}
		RSphere():length(0){}

		bool isContain(VecPos pos){
			if (pos.SquaredDistance(center) < length * length){
				return true;
			}
			return false;
		}
	};


	struct DimItem{
	private:
		VecPos v[DIMENSION];
	public:
		inline VecPos operator [] (int i){ return v[i];}
	};


	struct RPolygon : public Shape{

	private:
		std::vector<DimItem> items;
	public:
		RPolygon(){}
		RPolygon(const AABB &items){
			computeAABB();
		}
		RPolygon(RPolygon &poly){
			items.resize(poly.items.size());
			for(unsigned i = 0; i < poly.items.size(); ++i){
				items[i] = poly.items[i];
			}
			computeAABB();
		}
		~RPolygon(){}

		inline void add(DimItem itr){items.push_back(itr); updateAABB(itr);}
		inline void clear(){items.clear();}
		///////////////////////////////////////////////////////////////////////////////////
		//Only 2D solution * problem
		//RPP
		bool isContain(VecPos pos){
			bool inside = false;
			return inside;
		}
		bool isCross(RPolygon &poly,RPolygon &cross){

			return false;
		}

		AABB getAABB(){ return aabb;}
		//RPP
		///////////////////////////////////////////////////////////////////////////////////
	protected:
		AABB aabb;
		void updateAABB(DimItem itr){
			VecPos begin,end;
			begin = aabb.begin;
			end = aabb.end;
			for(unsigned j = 0; j < DIMENSION; ++j){
				for(unsigned i = 0; i < DIMENSION; ++i){
					if (begin[i] > itr[j][i]) begin[i] = itr[j][i];
					if (end[i] < itr[j][i]) end[i] = itr[j][i];
				}
			}
			aabb.reset(begin,end);
		}
		void computeAABB(){
			VecPos vmax,vmin,cent;
			vmax.setAll(MINNUM);
			vmin.setAll(MAXNUM);
			for(unsigned j = 0; j < items.size(); ++j){
				for(unsigned k = 0; k < DIMENSION; ++k){
					for(unsigned i = 0; i < DIMENSION; ++i){
						if (vmax[i] < items[j][k][i]) vmax[i] = items[j][k][i];
						if (vmin[i] > items[j][k][i]) vmin[i] = items[j][k][i];
					}
					center += items[j][k];
				}
			}
			center /= items.size() * DIMENSION;
			aabb.reset(vmin,vmax);
			return ;
		}
	};

	struct AttackStatus{
		DirectSpeed speed;
		double mass;
	};
	struct Collision{
	public:
		Entity *first;
		Entity *second;
		AttackStatus st1,st2;
		Plan plan;

		Collision():first(NULL),second(NULL){}

		Collision(const Collision & col){
			first = col.first;
			second = col.second;
		}

		Collision(Entity *f,Entity *s):first(f),second(s){}
		~Collision(){
		}
		void reset(){
			first = NULL;
			second = NULL;
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

		///////////////////////////////////////////////////////////
		//resize * problem
		Collision * current(){
			if (_cur >= _size){
				_size = _size<<1;
				collisions.resize(_size);
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