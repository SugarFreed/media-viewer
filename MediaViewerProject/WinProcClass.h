#pragma once
typedef struct VTABLE
{
	int (*WinProc)(HWND, UINT, WPARAM, LPARAM);
	int (*WinPaint)(HWND);
	int (*WinClose)(HWND);
	int (*WinSize)(HWND, LPARAM, WPARAM);
}VTABLE;

typedef struct WinProcClass
{
	VTABLE* vTble;
	HWND hwnd;

}WinProcClass;

WinProcClass* WinProcClassConstructor();
void WinProcClassDestructor(WinClass);