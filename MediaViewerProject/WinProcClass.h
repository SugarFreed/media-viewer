#pragma once
typedef struct VTABLE
{
	int (*WinProc)(HWND, UINT, WPARAM, LPARAM);
	int (*WinPaint)(HWND);
	int (*WinSize)(HWND, LPARAM, WPARAM);
}VTABLE;

typedef struct WinProcClass
{
	VTABLE* vTable;
	HWND hwnd;

}WinProcClass;

WinProcClass* WinProcClassConstructor();
void WinProcClassDestructor(WinClass);