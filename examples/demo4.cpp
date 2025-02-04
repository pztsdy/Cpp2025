#include "..\wapi.hpp"
#include <iostream>

using namespace std;

int main() {
    // It's have some error. Can not "显示窗口"

    // 创建两个窗口句柄
    HWND window1 = CreateWindowHandle("WINDOW1", 90, 90, 120, 240);
    HWND window2 = CreateWindowHandle("WINDOW2", 90, 90, 120, 240);

    // 修改第一个窗口的标题
    cout << "change window1 title" << endl;
    SetWindowTextA(window1, "Hello, World!");

    std::cout << "press any key to continue..." << std::endl;
    cin.get();
    return 0;
}


// test