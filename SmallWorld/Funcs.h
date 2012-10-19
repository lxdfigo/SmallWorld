#pragma once
#include "World.h"

namespace swd{
	SmallWorld* swCreateWorld(SWID wid);
	void swInitWorld(SWID wid,WorldConfig config);
	SmallWorld* swGetWorld(SWID wid);
	Entity* swGetEntity(SWID wid, SWID oid);
	void swRegisteEntity(SWID wid, Entity *obj);
	void swUpdateWorld(SWID wid);
	void swDestroyWorld(SWID wid);
	void swDestroyAllWorld();
}