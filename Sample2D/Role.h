#pragma once
#include "../SmallWorld/SmallWorld.h"

using namespace swd;

class Role : public RigidEntity
{
public:
	Role(SWID id,RPolygon p):RigidEntity(id,p){}
	Role(SWID id,VecPos p1,VecPos p2):RigidEntity(id,p1,p2){}
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