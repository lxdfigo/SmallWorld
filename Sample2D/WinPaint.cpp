#include "StdAfx.h"
#include "WinPaint.h"

WinPaint::WinPaint(void)
{
}

WinPaint::~WinPaint(void)
{
}

RECT WinPaint::getRect(Role *role){
	RECT rect;
	rect.left = 100 * role->getAABB().begin.Elements[0];
	rect.top = 100 * role->getAABB().begin.Elements[1];
	rect.right = 100 * role->getAABB().end.Elements[0];
	rect.bottom = 100 * role->getAABB().end.Elements[1];
	return rect;
}
void WinPaint::paint(HDC hdc){
	//::SetBkColor(hdc,COLORREF(0));
	RECT rect = getRect(role);

	DrawFocusRect(hdc,&rect);

	rect = getRect(house);
	DrawFocusRect(hdc,&rect);
}