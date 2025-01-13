# Cpp2025



这是一个C++头文件库，提供了多种功能以及丰富的WinApi接口，它由[pztsdy](http://www.github.com/pztsdy)维护。

# 运行环境及使用方法
 - 操作系统
 Windows（为保证稳定性，**请勿**擅自修改代码以在其它系统（如Linux, MacOS））
 - 系统架构
 x86_64, x64 \(,x32 有待考证\)
 - 系统版本
 Windows 7及以上，尽量使用64位系统
 - 软件
 编译器g++.exe，需要mingw或mingw-w64

开始使用：克隆此存储库以开始使用，或定位到release页面下载某版本使用

# 函数及功能说明
## `all.h`
使用`#include <Cpp2025/all.h>`以开始使用，若导入了`all.h`就相当于导入了所有C++2025头文件

## `sortcmp.hpp`
这是一个快速排序的自定义排序函数头文件，其中包含多个快排自定义函数（**返回值均为bool类型**），包括：
### `int_small_to_big(int x, int y)`
用于int类型，从小到大
### `int_big_to_small(int x, int y)`
用于int类型，从大到小
### `int_oFjS(int x, int y)`
用于int类型，偶数先，奇数后，其余从大到小
### `ll_small_to_big(long long x, long long y)`
用于long long 类型，从小到大
### `ll_big_to_small(long long x, long long y)`
用于long long 类型，从大到小
注：在`define.h`已经定义`#define ll long long`，所以，`ll`即可表示`long long` 类型

## `wapi.hpp`
这是一个Windows API参考代码库，定义了一些常用的Windows程序接口和功能。

### 预定义常量
用于设置控制台文本颜色：
- `TEXT_RED`, `TEXT_GREEN`, `TEXT_BLUE`, `TEXT_LIGHT` - 文本颜色
- `BG_RED`, `BG_GREEN`, `BG_BLUE`, `BG_LIGHT` - 背景颜色

### 函数说明
#### 基础控制台操作
- `pause()` - 显示"按任意键继续..."并等待用户按键
- `cls()` - 清空控制台屏幕
- `clearcolor(HANDLE handle, bool isUseDosMode, bool isUseDosCommandCls)` - 重置控制台文本颜色
  - `handle`: 控制台句柄
  - `isUseDosMode`: 是否使用DOS命令 `color` 重置
  - `isUseDosCommandCls`: 是否同时清屏
- `colorclear(HANDLE handle)` - clearcolor()的简化版本，相当于参数2和3为false

#### 鼠标和窗口操作
- `MoveMouse(POINT &mouse, int x, int y)` - 移动鼠标到指定坐标
- `SetWindowTitle(HWND hwnd, const char *title)` - 设置窗口标题
- `GetScreenResolution(int &width, int &height)` - 获取屏幕分辨率

#### 系统功能
- `SetSystemVolume(DWORD volume)` - 设置系统音量(0-100)
- `GetSystemTimeStr(char *timeStr)` - 获取系统时间字符串
- `SimulateKeyPress(WORD key)` - 模拟键盘按键