#pragma once
#include "Role.h"

class WinPaint
{
public:
	WinPaint(void);
	~WinPaint(void);

	RECT getRect(Role *b);
	void add(Role* r){role = r;}
	void addhouse(Role* h){house = h;}
	void paint(HDC hdc);
private:
	Role *role;
	Role *house;
};
