#pragma once
#include "ObjectTree.h"
#include "Enviroment.h"
#include "Time.h"

namespace swd{
	class SmallWorld
	{
	public:
		SmallWorld(void);
		~SmallWorld(void);

		void advance();
		bool registe(Object *obj);
	private:
		Time time;
		ObjectTree objectTree;
		Enviroment enviroment;

		void updateEnviroment();
		void updateObjects();
	};
}