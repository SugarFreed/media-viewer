#pragma once
typedef struct WinProcClass
{
	HWND hwnd;

	int (*WinPaint)(HWND);
	int (*WinSize)(HWND, LPARAM, WPARAM);
}WinProcClass;

WinProcClass* WinProcClassConstructor();
void WinProcClassDestructor(WinClass);