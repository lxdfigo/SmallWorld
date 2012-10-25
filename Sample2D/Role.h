#pragma once
#include "../SmallWorld/SmallWorld.h"

using namespace swd;

class Role : public RigidEntity
{
public:
	Role(SWID id,RPolygon p,double ma):RigidEntity(id,p,ma){}
	Role(SWID id,VecPos p1,VecPos p2,double ma):RigidEntity(id,p1,p2,ma){}
	~Role(void);

	virtual void callbackCollision(Collision *col){}
};

class House : public StaticEntity
{
public:
	House(SWID id,RPolygon p):StaticEntity(id,p){}
	House(SWID id,VecPos p1,VecPos p2):StaticEntity(id,p1,p2){}
	~House(void){}

	virtual void callbackCollision(Collision *col){}
};