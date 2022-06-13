#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <windef.h>

#include "WinProcClass.h"

int APIENTRY WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ PSTR cmdline, _In_ int cmdshow)
{
    // Create procedure object
    WinProcClass* winProcObj = WinProcClassConstructor();

    if (winProcObj == NULL)
    {
        return 0;
    }

    // Create window instance
    PCWSTR CLASSNAME = L"Media Viewer";

    WNDCLASS wc = {0};
    wc.lpszClassName = CLASSNAME;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                            
        CLASSNAME,                     
        L"Hello World",    
        WS_OVERLAPPEDWINDOW,  

        // Size and position of window
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        // Values passed to window
        NULL,       
        NULL,       
        hInst,  
        winProcObj  // Pass process object to window
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, cmdshow);  // Display window based on cmdshow value

    // Begin message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    WinProcClass* winProcObj;
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
    {
        winProcObj->WinPaint(hwnd);
    }
    case WM_SIZE:
    {
        winProcObj->WinSize(hwnd, lParam, wParam);
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}