#include "..\wapi.hpp"
#include <iostream>

using namespace std;

int main() {
    // 创建两个窗口句柄
    HWND window1 = CreateWindowHandle("WINDOW1", 90, 90, 120, 240);
    HWND window2 = CreateWindowHandle("WINDOW2", 90, 90, 120, 240);

    // 修改第一个窗口的标题
    cout << "change window1 title" << endl;
    SetWindowTextA(window1, "Hello, World!");

    return 0;
}
