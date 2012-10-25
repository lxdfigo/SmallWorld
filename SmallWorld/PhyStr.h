#pragma once
#include "Basic.h"

namespace swd{

	class Entity;


	struct DimItem{
	private:
		VecPos v[DIMENSION];
	public:
		inline VecPos & operator [] (int i){ return v[i];}
		inline VecPos   operator [] (int i) const { return v[i]; }
	};

	struct Line{
	public:
		VecPos begin;
		VecPos end;

	public:
		Line(const Line& line):begin(line.begin),end(line.end){	}
		Line(VecPos b,VecPos e):begin(b),end(e){}
		Line(const DimItem &items):begin(items[0]),end(items[1]){}

		VecPos getPos(int d,double v){
			VecPos result;
			result[d] = v;
#ifdef TWO_DIMENSION_PHYSICAL_ENGINE
			for(int i = 0; i < DIMENSION; ++i){
				if (d != i){
					if (end[d] != begin[d])
						result[i] = (end[i] - begin[i]) * (result[d] - begin[d]) / (end[d] - begin[d]) + begin[i];
					else
						result[i] = begin[i];
				}
			}
#else

#endif
			return result;
		}
		VecPos getVec(){
			return begin - end;
		}
	};


	struct Triangle{
	private:
		VecPos v1,v2,v3;
	public:
		Triangle(const Triangle& tri):v1(tri.v1),v2(tri.v2),v3(tri.v3){}
		Triangle(VecPos p1,VecPos p2,VecPos p3):v1(p1),v2(p2),v3(p3){}
		Triangle(const DimItem &items):v1(items[0]),v2(items[1]),v3(items[2]){}		
	};

	struct AABB
	{
	private:
		VecPos begin;
		VecPos end;
	public:
		AABB(const AABB& aabb):begin(aabb.begin),end(aabb.end){	}
		AABB(VecPos b,VecPos e):begin(b),end(e){
			standardizate();
		}
		AABB(){}
		VecPos getBegin(){return begin;}
		VecPos getEnd(){return end;}

		void reset(VecPos b,VecPos e){
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
		}

		bool isCross(AABB &aabb){
			VecPos result;
			for(int i = 0; i < DIMENSION; i++){
				if (aabb.begin[i] > begin[i] && aabb.begin[i] < end[i]) result[i] = 1.0;
				if (aabb.end[i] > begin[i] && aabb.end[i] < end[i]) result[i] = 1.0;
			}
			if (result > VecPos()) return true;
			result.zero();
			for(int i = 0; i < DIMENSION; i++){
				if (begin[i] > aabb.begin[i] && begin[i] < aabb.end[i]) result[i] = 1.0;
				if (end[i] > aabb.begin[i] && end[i] < aabb.end[i]) result[i] = 1.0;
			}
			if (result > VecPos()) return true;
			
			return false;
		}
		bool isContain(VecPos pos){
			if ( pos > begin && pos < end){
				return true;
			}
			return false;
		}
		bool isCross(Line line){
#ifdef TWO_DIMENSION_PHYSICAL_ENGINE
			VecPos v1 = line.getPos(0,begin[0]);
			VecPos v2 = line.getPos(0,end[0]);
			if ((v1[0] - v1[1]) * (v2[0] * v2[1]) < 0){
				return true;
			}
#else
#endif
			return false;
		}
		bool solveLine(Line &line){
			double dis = MAXNUM;
			bool sign = false;
			for(int i = 0; i < DIMENSION; ++i){
				VecPos v1 = line.getPos(i,begin[i]);
				VecPos v2 = line.getPos(i,end[i]);
				if (isOnBox(v1)){
					double tmp = line.begin.SquaredDistance(v1);
					if (tmp < dis){
						line.end = v1;
						dis = tmp;
						sign = true;
					}
				}
				if (isOnBox(v2)){
					double tmp = line.begin.SquaredDistance(v2);
					if (tmp < dis){
						line.end = v2;
						dis = tmp;
						sign = true;
					}
				}
			}
			return sign;
		}
		bool isOnBox(VecPos &pos){
			VecPos EpsilonVec;
			EpsilonVec.setAll(0.01);
			if ( pos > begin - EpsilonVec && pos < end + EpsilonVec){
				return true;
			}
			return false;
		}
	};
	struct RSphere
	{
	private:
		VecPos center;
		double length;
	public:
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

		inline DimItem & operator [] (int i){ return items[i];}
		inline DimItem   operator [] (int i) const { return items[i]; }
		inline unsigned size(){return items.size();}
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
	private:
		AABB aabb;
		void updateAABB(DimItem itr){
			VecPos begin,end;
			begin = aabb.getBegin();
			end = aabb.getEnd();
			for(unsigned j = 0; j < DIMENSION; ++j){
				for(unsigned i = 0; i < DIMENSION; ++i){
					if (begin[i] > itr[j][i]) begin[i] = itr[j][i];
					if (end[i] < itr[j][i]) end[i] = itr[j][i];
				}
			}
			aabb.reset(begin,end);
		}
		void computeAABB(){
			VecPos vmax,vmin;
			vmax.setAll(MINNUM);
			vmin.setAll(MAXNUM);
			for(unsigned j = 0; j < items.size(); ++j){
				for(unsigned k = 0; k < DIMENSION; ++k){
					for(unsigned i = 0; i < DIMENSION; ++i){
						if (vmax[i] < items[j][k][i]) vmax[i] = items[j][k][i];
						if (vmin[i] > items[j][k][i]) vmin[i] = items[j][k][i];
					}
				}
			}
			aabb.reset(vmin,vmax);
			return ;
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