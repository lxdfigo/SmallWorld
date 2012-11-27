#pragma once
#include "World.h"

namespace swd{
	//Worlds
	SmallWorld* swCreateWorld(SWID wid);
	void swInitWorld(SWID wid,WorldConfig config);
	SmallWorld* swGetWorld(SWID wid);
	void swUpdateWorld(SWID wid);
	void swDestroyWorld(SWID wid);
	void swDestroyAllWorld();
	//Entitys
	Entity* swGetEntity(SWID wid, SWID oid);
	void swRegisteEntity(SWID wid, Entity *obj);
}