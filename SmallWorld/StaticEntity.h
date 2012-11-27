#pragma once
#include "RigidEntity.h"

namespace swd{
	class StaticEntity :
		public RigidEntity
	{
	public:
		StaticEntity(SWID id,VecPos pos,VecPos size);
		StaticEntity(SWID id,RPolygon poly);
		~StaticEntity(void);

		virtual void addForce(AppliedForce force);
		virtual void addForceOnPoint(AppliedForce force,VecPos point);

		virtual void setStep(Timer &timer) ;
		virtual bool update();
		virtual bool integrate();
	};
}
