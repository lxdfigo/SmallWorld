#include "stdafx.h"
#include "Init.h"
#include "Role.h"
#include "WinPaint.h"

SmallWorld *world;
WinPaint winPaint;
void InitWorld(){
	VecPos grav(0,9.8);
	WorldConfig config;
	config.envCfg.gravity = grav;
	config.tmCfg.step = 1.0/FPS;
	world = swCreateWorld("world");
	swInitWorld("world",config);

	Role *role;

	//role = new Role("rock1",VecPos(2,0),VecPos(3,1),1.0);
	//swRegisteEntity("world",role);
	//winPaint.add(role);

	House *house = new House("house",VecPos(0,4),VecPos(10,5));
	swRegisteEntity("world",house);
	winPaint.addHouse(house);

	for (int i = 0; i < 3; i++){
		char str[64];
		sprintf(str,"role_%d",i);
		double p1 = 2;//i%17 * 0.4;
		double p2 = i%13 ;
		role = new Role(str,VecPos(p1,p2),VecPos(p1 + 0.1,p2+ 0.1),1.0);
		swRegisteEntity("world",role);
		winPaint.add(role);
	}
}
void UpdatePaint(HDC hdc){
	swUpdateWorld("world");
	winPaint.paint(hdc);
}
void UpdateWorld(WPARAM wParam,LPARAM lparam){
	AppliedForce force;
	if (wParam == VK_LEFT){
		force[0] = -10;
	}else if (wParam == VK_RIGHT){
		force[0] = 10;
	}else if (wParam == VK_UP){
		force[1] = -10;
	}else if (wParam == VK_DOWN){
		force[1] = 10;
	}
	swGetEntity("world","role_0")->addForce(force);
}
void DestroyWorld(){
	swDestroyAllWorld();
}