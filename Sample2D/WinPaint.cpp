#include "StdAfx.h"
#include "WinPaint.h"

WinPaint::WinPaint(void)
{
}

WinPaint::~WinPaint(void)
{
}

RECT WinPaint::getRect(AABB aabb){
	VecPos begin = aabb.begin;
	VecPos end = aabb.end;
	RECT rect;
	rect.left = 100 * begin[0];
	rect.top = 100 *begin[1];
	rect.right = 100 * end[0];
	rect.bottom = 100 * end[1];
	return rect;
}
void WinPaint::paint(HDC hdc){

	HPEN hP;    //定义画笔句柄
	HBRUSH  hB;   //定义画刷句柄

	SetMapMode(hdc,MM_TEXT); 
	hB=CreateSolidBrush(RGB(255,255,255));
	SelectObject(hdc,hB);
	Rectangle(hdc,0,0,2000,2000);

	hP=CreatePen(PS_SOLID,1,RGB(255,0,0));
	SelectObject(hdc,hP);
	DeleteObject(hB);
	DeleteObject(hP);
	for(unsigned i = 0; i < roles.size(); i++){
		hB=CreateSolidBrush(RGB(i*37 % 255,i*111 % 255,i*153 % 255));
		SelectObject(hdc,hB);
		RECT rect = getRect(roles[i]->getAABB());
		Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
		DeleteObject(hB);
	}
	hP=CreatePen(PS_SOLID,1,RGB(0,0,255));
	hB=CreateHatchBrush(HS_CROSS,RGB(0,255,0));//绿色网状

	SelectObject(hdc,hP);
	SelectObject(hdc,hB); //更新画刷，用“绿色网状”
	for(unsigned i = 0; i < houses.size(); i++){
		RECT rect = getRect(houses[i]->getAABB());
		Rectangle(hdc,rect.left,rect.top,rect.right,rect.bottom);
	}
	DeleteObject(hB);
	DeleteObject(hP);
}