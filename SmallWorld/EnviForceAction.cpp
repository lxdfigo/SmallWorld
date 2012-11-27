#include "EnviForceAction.h"
#include "Entity.h"

using namespace swd;

EnviForceAction::EnviForceAction(SWID id):Action(id)
{
}

EnviForceAction::~EnviForceAction(void)
{
}

void EnviForceAction::apply(Entity *entity){
	entity->addForce(force);
}