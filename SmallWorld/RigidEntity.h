#pragma once
#include "Entity.h"

namespace swd{
	class RigidEntity :
		public Entity
	{
	public:
		RigidEntity(SWID id,VecPos pos,VecPos size);
		RigidEntity(SWID id,RPolygon poly);
		~RigidEntity(void);


		virtual bool isCrossSingleEntity(Entity *entity,CollideInfo *col){ 
			return body->isCross(entity->getBody(),col);
		}
		virtual void transform(Transform& trans){ body->transform(trans);}
		virtual AABB getAABB(){ return body->getAABB();}

		virtual void setStep(Timer &timer);
		virtual bool update();
		virtual bool integrate();

		virtual void addForce(AppliedForce force);
		virtual void addForceOnPoint(AppliedForce force,VecPos point);

		virtual void computeInertia(){ inertia = body->getInertia(); }
	};
}