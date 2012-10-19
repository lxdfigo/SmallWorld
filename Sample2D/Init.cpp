#include "stdafx.h"
#include "Init.h"
#include "Role.h"
#include "WinPaint.h"

SmallWorld *world;
WinPaint winPaint;
void InitWorld(){
	RPolygon poly;
	VecPos p = VecPos(2);
	poly.add(p);
	p.Elements[0] = 3;
	p.Elements[1] = 2;
	poly.add(p);
	p.Elements[0] = 3;
	p.Elements[1] = 3;
	poly.add(p);
	p.Elements[0] = 2;
	p.Elements[1] = 3;
	poly.add(p);
	Role *role = new Role("player",poly,1.0);
	RPolygon poly2;
	p.Elements[0] = 0;
	p.Elements[1] = 3;
	poly2.add(p);
	p.Elements[0] = 6;
	p.Elements[1] = 3;
	poly2.add(p);
	p.Elements[0] = 6;
	p.Elements[1] = 4;
	poly2.add(p);
	p.Elements[0] = 0;
	p.Elements[1] = 4;
	poly2.add(p);
	Role *house = new Role("house",poly2,1.0);
	house->setMask(STATIC);
	VecPos grav;
	grav.Elements[1] = 9.8;
	WorldConfig config;
	config.envCfg.gravity = grav;
	config.tmCfg.step = 0.1;
	world = swCreateWorld("world");
	swInitWorld("world",config);
	swRegisteEntity("world",role);
	swRegisteEntity("world",house);
	winPaint.add(role);
	winPaint.addhouse(house);
}
void UpdatePaint(HDC hdc){
	swUpdateWorld("world");
	winPaint.paint(hdc);
}
void UpdateWorld(WPARAM wParam,LPARAM lparam){
	AppliedForce force;
	if (wParam == VK_LEFT){
		force.Elements[0] = -10;
	}else if (wParam == VK_RIGHT){
		force.Elements[0] = 10;
	}else if (wParam == VK_UP){
		force.Elements[1] = -10;
	}else if (wParam == VK_DOWN){
		force.Elements[1] = 10;
	}
	swGetEntity("world","player")->addForce(force);
}
void DestroyWorld(){
	swDestroyAllWorld();
}