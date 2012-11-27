#pragma once
#include "Entity.h"
namespace swd{
	class ComEntity :
		public Entity
	{
	public:
		ComEntity(void);
		~ComEntity(void);

		virtual bool isCross(Entity *entity,CollideInfo *col);
		virtual bool isCrossSingleEntity(Entity *entity,CollideInfo *col);
		virtual void setStep(Timer &timer) = 0;
		virtual bool integrate() = 0;
		virtual void transform(Transform& trans);
		virtual AABB getAABB(){return aabb;}

		virtual bool update();
		virtual void computeInertia();
	private:
		//private function;
		virtual void computeMassAndCentroid();
		virtual void computeAABB();
		MomentInertia getDisInertia(VecPos len);
	private:
		std::vector<Entity*> entitys;
		AABB aabb;
	};

}
