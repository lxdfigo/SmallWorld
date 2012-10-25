#pragma once

#define FPS 60

void InitWorld();
void UpdateWorld(WPARAM wParam,LPARAM lparam);
void UpdatePaint(HDC hdc);
void DestroyWorld();