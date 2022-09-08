#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <windef.h>
#include <objbase.h>
#include <shobjidl.h>

#include "WinProcClass.h"

int APIENTRY WinMain(_In_ HINSTANCE hInst, _In_opt_ HINSTANCE hInstPrev, _In_ PSTR cmdline, _In_ int cmdshow)
{
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr))
    {
        
    }
    // Create process object
    WinProcClass* winProcObj = WinProcClassConstructor();

    if (winProcObj == NULL)
    {
        return 0;
    }

    // Create window instance
    PCWSTR CLASSNAME = L"Media Viewer";

    WNDCLASS wc = {0};
    wc.lpszClassName = CLASSNAME;
    wc.lpfnWndProc = WinProc;
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
        winProcObj  // Pass procedure object to window
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
    CoUninitialize();
    return 0;
}

//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
//{
//    WinProcClass* winProcObj = NULL;
//    if (uMsg == WM_CREATE)
//    {
//        CREATESTRUCT* createptr = (CREATESTRUCT*)lParam; // Extract CREATESTRUCT containing data
//        LONG lptr = (createptr->lpCreateParams); // Extract params from createptr
//        SetWindowLongPtr(hwnd, GWLP_USERDATA, lptr); // Store data in GWLP_USERDATA
//    }
//    else
//    {
//        winProcObj = (WinProcClass*)GetWindowLongPtr(hwnd, GWLP_USERDATA); // Retrieve data from GWLP_USERDATA
//    }
//    return winProcObj->WinProc(hwnd, uMsg, wParam, lParam);
//}