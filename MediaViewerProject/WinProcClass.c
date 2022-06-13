#include <windows.h>
#include <windef.h>

#include "WinProcClass.h"

// Object control
WinProcClass* WinProcClassConstructor()
{
    WinProcClass* object = (WinProcClass*)malloc(sizeof(WinProcClass));

    object->WinPaint = WinPaint;
    object->WinSize = WinSize;

    return object;
}
void WinProcClassDestructor(WinProcClass *object)
{
    free(object);
}

// Message functions
int WinPaint(HWND hwnd)
{
    PAINTSTRUCT winPaintStruct;
    HDC hdc = BeginPaint(hwnd, &winPaintStruct);

    // Painting space
    FillRect(hdc, &winPaintStruct.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

    EndPaint(hwnd, &winPaintStruct);
    return 0;
}
int WinSize(HWND hwnd, LPARAM lParam, WPARAM wParam)
{
    int width = LOWORD(lParam); // Lower 16 bits of lParam
    int height = HIWORD(lParam); // Higher 16 bits of lParam

    OnSize(hwnd, (UINT)wParam, width, height);
    return 0;
}

// Helper functions
void OnSize(HWND hwnd, UINT flag, int width, int height)
{
    //RECT rc;
    //GetWindowRect(hwnd, &rc);
    switch (flag)
    {
        // Flag logic goes here
    }
    return;
}
