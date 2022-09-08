#pragma once
typedef struct WinProcClass
{
	HWND hwnd;

	int (*WinProc)(HWND, UINT, WPARAM, LPARAM);

	int (*WinPaint)(HWND);
	int (*WinSize)(HWND, LPARAM, WPARAM);
}WinProcClass;

int WinProc(HWND, UINT, WPARAM, LPARAM);

int WinPaint(HWND);
int WinSize(HWND, LPARAM, WPARAM);

WinProcClass* WinProcClassConstructor();
void WinProcClassDestructor(WinClass);