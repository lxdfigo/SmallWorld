#pragma once
#include "Basic.h"

namespace swd{
	class Entity;

	class Action
	{
	public:
		Action(SWID id);
		~Action(void);

		virtual void apply(Entity *entity) = 0;
		SWID getID(){return aid;}
	private:
		SWID aid;
	};
	typedef std::map<SWID,Action*> ActionMap;
	//Actions
	Action *addAction(SWID aid,Action *action);
	Action *getAction(SWID aid);
	void removeAction(SWID aid);
}