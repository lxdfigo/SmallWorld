#pragma once
#include "EntityTree.h"
#include "Enviroment.h"
#include "Timer.h"
#include <map>

namespace swd{
	struct WorldConfig{
		EnvConfig envCfg;
		TimeConfig tmCfg;
	};
	class SmallWorld
	{
	public:
		SmallWorld(SWID id):wID(id){}
		~SmallWorld(void){}

		void init(WorldConfig config);
		void update();
		bool registe(Entity *obj);
		Entity *getEntity(SWID oid);
	private:
		SWID	wID;
		Timer timer;
		EntityTree entityTree;
		Enviroment enviroment;

		void advance();
		void updateEntitys();
	};

	typedef std::map<SWID,SmallWorld*> SmallWorlds;
}