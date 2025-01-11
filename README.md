# Cpp2025
这是一个C++头文件库，提供了多种功能以及丰富的WinApi接口，它由[pztsdy](http://www.github.com/pztsdy)维护。

# 运行环境
 - 操作系统
 Windows
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

---

## `sortcmp.h`
这是一个快速排序的自定义排序函数头文件，其中包含多个快排自定义函数（**返回值均为bool类型**），包括：
### `int_small_to_big(int x, int y)`
用于int类型，从小到大
### `int_big_to_small(int x, int y)`
用于int类型，从大到小
### `ll_small_to_big(long long x, long long y)`
用于long long 类型，从小到大
### `ll_big_to_small(long long x, long long y)`
用于long long 类型，从大到小
注：在`define.h`已经定义`#define ll long long`，所以，`ll`即可表示`long long` 类型
### 