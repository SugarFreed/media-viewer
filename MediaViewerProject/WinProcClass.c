#include <windows.h>
#include <windef.h>
#include <objbase.h>
#include <shobjidl.h>

#include "WinProcClass.h"

// Object control
WinProcClass* WinProcClassConstructor()
{
    WinProcClass* object = (WinProcClass*)malloc(sizeof(WinProcClass));
    if (object == NULL) 
    {
        return NULL;
    }

    object->WinProc = WinProc;

    object->WinPaint = WinPaint;
    object->WinSize = WinSize;

    return object;
}
void WinProcClassDestructor(WinProcClass *object)
{
    free(object);
}

// Message Handler
int WinProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    WinProcClass* winProcObj = NULL;
    if (uMsg == WM_CREATE)
    {
        CREATESTRUCT* createptr = (CREATESTRUCT*)lParam; // Extract CREATESTRUCT containing data
        LONG lptr = (createptr->lpCreateParams); // Extract params from createptr
        SetWindowLongPtr(hwnd, GWLP_USERDATA, lptr); // Store data in GWLP_USERDATA
    }
    else
    {
        winProcObj = (WinProcClass*)GetWindowLongPtr(hwnd, GWLP_USERDATA); // Retrieve data from GWLP_USERDATA
    }
    switch (uMsg)
    {
    case WM_PAINT:
        WinPaint(hwnd);
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
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

    return 0;
}

// Helper functions

