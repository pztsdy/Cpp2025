#include "..\wapi.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    // 创建两个窗口句柄
    HWND window1 = CreateWindowExW(
        0,                              // Optional window styles.
        L"STATIC",                      // Window class
        L"Window 1",                    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    HWND window2 = CreateWindowExW(
        0,                              // Optional window styles.
        L"STATIC",                      // Window class
        L"Window 2",                    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    if (window1 == NULL || window2 == NULL) {
        cout << "Failed to create windows" << endl;
        return 1;
    }

    // Show the windows
    ShowWindow(window1, SW_SHOW);
    ShowWindow(window2, SW_SHOW);

    // 修改第一个窗口的标题
    cout << "change window1 title" << endl;
    SetWindowTextW(window1, L"Hello, World!");

    // 隐藏窗口
    cout << "Hide window2" << endl;
    ShowWindow(window2, SW_HIDE);

    std::cout << "press any key to continue..." << std::endl;
    cin.get();
    return 0;
}