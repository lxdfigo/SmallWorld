#pragma once
#include "../SmallWorld/SmallWorld.h"

using namespace swd;

class Role : public RigidEntity
{
public:
	Role(SWID id,RPolygon p,double ma):RigidEntity(id,p,ma){}
	~Role(void);

	virtual void callbackCollision(Collision *col){}
};
