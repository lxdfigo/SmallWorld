#include "Entity.h"
#include "Action.h"
#include "Constraint.h"

using namespace swd;
void Entity::applyActions(){
	force.zero();
	moment.zero();
	std::vector<Action *>::iterator begin = actions.begin();
	for(; begin != actions.end(); ++begin){
		(*begin)->apply(this);
	}
	update();
}

bool Entity::addAction(Action *action){
	if (action == NULL) return false;
	std::vector<Action *>::iterator begin = actions.begin();
	for(; begin != actions.end(); ++begin){
		if ((*begin)->getID() == action->getID())
			return false;
	}
	actions.push_back(action);
	return true;
}
bool Entity::removeAction(Action *action){
	std::vector<Action *>::iterator begin = actions.begin();
	for(; begin != actions.end(); ++begin){
		if ((*begin)->getID() == action->getID()){
			actions.erase(begin);
			return true;
		}
	}
	return false;
}


void Entity::applyConstraints(){
	std::vector<Constraint *>::iterator begin = constraints.begin();
	for(; begin != constraints.end(); ++begin){
		
	}

}
bool Entity::addConstraint(Constraint *constraint){
	if (constraint == NULL) return false;
	std::vector<Constraint *>::iterator begin = constraints.begin();
	for(; begin != constraints.end(); ++begin){
		if ((*begin)->getID() == constraint->getID())
			return false;
	}
	constraints.push_back(constraint);
	return true;

}
bool Entity::removeConstraint(Constraint *constraint){
	std::vector<Constraint *>::iterator begin = constraints.begin();
	for(; begin != constraints.end(); ++begin){
		if ((*begin)->getID() == constraint->getID()){
			constraints.erase(begin);
			return true;
		}
	}
	return false;

}