#include "funcs.h"
/////////////////////////////////////////////////////////////////////////
using namespace swd;

static SmallWorlds szSmallWorlds;

SmallWorld* swd::swCreateWorld(SWID wid){ 
	if (szSmallWorlds[wid] == NULL)
		szSmallWorlds[wid] = new SmallWorld(wid);

	return szSmallWorlds[wid];
}
void swd::swInitWorld(SWID wid,WorldConfig config){
	swGetWorld(wid)->init(config);
}

SmallWorld* swd::swGetWorld(SWID wid){ 
	return szSmallWorlds[wid];
}
void swd::swRegisteEntity(SWID wid, Entity *obj){ 
	szSmallWorlds[wid]->registe(obj);
}
Entity* swd::swGetEntity(SWID wid, SWID oid){
	return swGetWorld(wid)->getEntity(oid);
}
void swd::swUpdateWorld(SWID wid){ 
	szSmallWorlds[wid]->update();
}
void swd::swDestroyWorld(SWID wid){ 
	delete szSmallWorlds[wid];
	szSmallWorlds[wid] = NULL;
}
void swd::swDestroyAllWorld(){ 
	SmallWorlds::iterator itr = szSmallWorlds.begin();
	for(;itr != szSmallWorlds.end(); itr++){
		delete itr->second;
	}
	szSmallWorlds.clear();
}