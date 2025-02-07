# Cpp2025

这是一个C++头文件库，提供了多种功能以及丰富的WinApi接口，它由[pztsdy](http://www.github.com/pztsdy)维护。

## 运行环境及使用方法
- 操作系统
  Windows（为保证稳定性，**请勿**擅自修改代码以在其它系统（如Linux, MacOS））
- 系统架构
  x86_64, x64 \(,x32 有待考证\)
- 系统版本
  Windows 7及以上，尽量使用64位系统
- 软件
  编译器g++.exe，需要mingw或mingw-w64

开始使用：克隆此存储库以开始使用，或定位到release页面下载某版本使用

## ⚠编译时的重要提示！⚠
在您编译您的程序时，如果您引用的头文件**包含** `wapi.hpp` ，那么请您注意，在使用g++编译时添加 `-lole32` 命令。否则会导致编译不通过。

## 将Cpp2025导入到自己的编译器中
1. 打开你的编译器IncludePath
2. 新建目录Cpp2025
3. 将release中的版本归档文件解压并释放到Cpp2025目录中
4. 要使用时，将你需要的头文件导入，如：`#include <Cpp2025/Algorithm.hpp>`

## 函数及功能说明

### `all.h`
使用`#include <Cpp2025/all.h>`以开始使用，若导入了`all.h`就相当于导入了所有C++2025头文件

### `sortcmp.hpp`
这是一个快速排序的自定义排序函数头文件，其中包含多个快排自定义函数（**返回值均为bool类型**），包括：
- `int_small_to_big(int x, int y)` - 用于int类型，从小到大
- `int_big_to_small(int x, int y)` - 用于int类型，从大到小
- `int_oFjS(int x, int y)` - 用于int类型，偶数先，奇数后，其余从大到小
- `ll_small_to_big(long long x, long long y)` - 用于long long 类型，从小到大
- `ll_big_to_small(long long x, long long y)` - 用于long long 类型，从大到小

注：在[`define.h`](define.h)已经定义`#define ll long long`，所以，`ll`即可表示`long long` 类型

### `wapi.hpp`
这是一个Windows API参考代码库，定义了一些常用的Windows程序接口和功能。

#### 预定义常量
用于设置控制台文本颜色：
- `TEXT_RED`, `TEXT_GREEN`, `TEXT_BLUE`, `TEXT_LIGHT` - 文本颜色
- `BG_RED`, `BG_GREEN`, `BG_BLUE`, `BG_LIGHT` - 背景颜色

#### 函数说明
##### 基础控制台操作
- `pause()` - 显示"按任意键继续..."并等待用户按键
- `cls()` - 清空控制台屏幕
- `clearcolor(HANDLE handle, bool isUseDosMode, bool isUseDosCommandCls)` - 重置控制台文本颜色
  - `handle`: 控制台句柄
  - `isUseDosMode`: 是否使用DOS命令 `color` 重置
  - `isUseDosCommandCls`: 是否同时清屏
- `colorclear(HANDLE handle)` - clearcolor()的简化版本，相当于参数2和3为false
- `HideCursor` - 隐藏控制台光标
- `ShowCursor` - 显示控制台光标

##### 鼠标和窗口操作
- `MoveMouse(POINT &mouse, int x, int y)` - 移动鼠标到指定坐标
- `SetWindowTitle(HWND hwnd, const char *title)` - 设置窗口标题
- `GetScreenResolution(int &width, int &height)` - 获取屏幕分辨率
##### 系统功能
- `SetSystemVolume(DWORD volume)` - 设置系统音量(0-100)
- `GetSystemTimeStr(char *timeStr)` - 获取系统时间字符串
- `SimulateKeyPress(WORD key)` - 模拟键盘按键
- `SimulateMouseClick(int x, int y)` - 模拟鼠标点击
- `SimulateMouseMove(int x, int y)` - 模拟鼠标移动
- `GetMousePosition(int &x, int &y)` - 获取鼠标位置
- `GetWindowHandle(const char *title)` - 获取窗口句柄
- `GetWindowPosition(HWND hwnd, int &x, int &y)` - 获取窗口位置
- `SetWindowPosition(HWND hwnd, int x, int y)` - 设置窗口位置
- `GetWindowSize(HWND hwnd, int &width, int &height)` - 获取窗口大小
- `SetWindowSize(HWND hwnd, int width, int height)` - 设置窗口大小
- `GetWindowTitle(HWND hwnd, char *title)` - 获取窗口标题
- `GetWindowClassName(HWND hwnd, char *className)` - 获取窗口类名
- `GetWindowProcessId(HWND hwnd)` - 获取窗口进程ID
- `GetWindowThreadId(HWND hwnd)` - 获取窗口线程ID
- `GetWindowParent(HWND hwnd)` - 获取窗口父窗口
- `GetWindowChild(HWND hwnd)` - 获取窗口子窗口
- `GetWindowNext(HWND hwnd)` - 获取窗口兄弟窗口
- `GetWindowLevel(HWND hwnd)` - 获取窗口层级
- `GetWindowStyle(HWND hwnd)` - 获取窗口样式
- `GetWindowClassStyle(HWND hwnd)` - 获取窗口类样式
- `GetWindowProcessHandle(HWND hwnd)` - 获取窗口进程句柄
- `SetWindowChild(HWND hwnd, HWND parent)` - 设置一个窗口为另一个窗口的子窗口
- `SetWindowParent(HWND hwnd, HWND child)` - 设置一个窗口为另一个窗口的父窗口

### `Algorithm.hpp`
包含了一些常用的算法函数，包括递归和数学运算。

#### 函数列表
- `int factorial(int n)` - 计算整数 `n` 的阶乘
- `int fibonacci(int n)` - 计算第 `n` 个斐波那契数
- `int Pow(int x, int n)` - 计算 `x` 的 `n` 次幂
- `int gcd(int a, int b)` - 计算两个整数 `a` 和 `b` 的最大公约数
- `int lcm(int a, int b)` - 计算两个整数 `a` 和 `b` 的最小公倍数
- `bool isPrime(int n)` - 判断整数 `n` 是否为素数
- `std::vector<int> sieve_prime(int n)` - 使用埃拉托色尼筛法找出小于等于 `n` 的所有素数
- `int binarySearch(const std::vector<int>& arr, int target)` - 在有序数组中查找目标值
- `int quickSelect(std::vector<int>& arr, int left, int right, int k)` - 在数组中查找第 `k` 小的元素
- `int selectKthSmallest(std::vector<int>& arr, int k)` - 查找数组中第 `k` 小的元素
- `int partition(std::vector<int>& arr, int left, int right, int pivotIndex)` - 分区函数，用于快速选择算法

### 示例程序
#### `demo1.cpp`
展示了如何使用 `wapi.hpp` 中的函数进行一些基本的Windows操作。

#### `demo2.cpp`
展示了如何使用 `sortcmp.hpp` 中的函数进行排序操作。

#### `demo3.cpp`
展示了如何使用 `Algorithm.hpp` 中的函数进行一些基本的算法操作。

### 许可证
本项目使用MIT许可证，详见[`LICENSE`](LICENSE)文件。
