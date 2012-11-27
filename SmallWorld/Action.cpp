#include "Action.h"
#include "Entity.h"
#include "Funcs.h"

using namespace swd;

static ActionMap szActions;

Action::Action(SWID id):aid(id){
	addAction(aid,this);
}

Action::~Action(void){
	removeAction(aid);
}


Action *swd::addAction(SWID aid,Action *action){
	if (szActions[aid] == NULL)
		szActions[aid] = action;
	return szActions[aid];
}
Action *swd::getAction(SWID aid){
	return szActions[aid];
}
void swd::removeAction(SWID aid){
	if (szActions[aid] != NULL)
		delete szActions[aid];
	szActions[aid] = NULL;
}