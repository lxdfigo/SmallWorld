#pragma once
#include "Role.h"

class WinPaint
{
public:
	WinPaint(void);
	~WinPaint(void);

	RECT getRect(AABB aabb);
	void add(Role* r){roles.push_back(r);}
	void addHouse(House* r){houses.push_back(r);}
	void paint(HDC hdc);
private:
	std::vector<Role *>roles;
	std::vector<House *>houses;
};
