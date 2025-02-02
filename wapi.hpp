#include "define.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <VersionHelpers.h>

/*

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(handle, BG_RED | ...);
*/

/*
	POINT mouse;
	srand(time(0));
	GetCursorPos(&mouse);
	mouse.x=rand()%1920;
	mouse.y=rand()%1080;
	// printf("%d %d\n",mouse.x,mouse.y);
	SetCursorPos(mouse.x,mouse.y);
	Sleep(2000);
*/

#define TEXT_RED 4
#define TEXT_GREEN 2
#define TEXT_BLUE 1
#define TEXT_LIGHT 8
#define BG_RED 64
#define BG_GREEN 32
#define BG_BLUE 16
#define BG_LIGHT 128

#ifdef _WINDOWS_
#include <_mingw.h>
#define __winsystem__ true
#endif

#ifndef _WINDOWS_
#define __winsystem__ false
#endif

void pause()
{
	system("pause");

	return;
}

void cls()
{
	if (__winsystem__) // system judge
	{
		system("cls");
	}
	else
	{
		system("clear");
	}

	return;
}

#ifdef _WIN32
void clearcolor(HANDLE handle, bool isUseDosMode, bool isUseDosCommandCls)
{
	SetConsoleTextAttribute(handle, TEXT_RED | TEXT_BLUE | TEXT_GREEN);
	if (isUseDosMode)
	{
		system("color 07");
	}
	if (isUseDosCommandCls)
	{
		cls();
	}

	return;
}
#endif

void colorclear(HANDLE handle)
{ // support for old-vision code
	clearcolor(handle, false, false);

	return;
}

void MoveMouse(POINT &mouse, int x, int y)
{
	// srand(time(0));
	GetCursorPos(&mouse);
	mouse.x = x;
	mouse.y = y;
	// printf("%d %d\n",mouse.x,mouse.y);  if you want print it, please del "\\"
	SetCursorPos(mouse.x, mouse.y);

	return;
}

void HideCursor() {
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void ShowCursor() {
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = TRUE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

// 窗口操作
void SetWindowTitle(HWND hwnd, const char *title)
{
	SetWindowTextA(hwnd, title);
}

// 获取屏幕分辨率
void GetScreenResolution(int &width, int &height)
{
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);
}

// 系统音量控制
void SetSystemVolume(DWORD volume)
{ // volume: 0-100
	HRESULT hr;
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoInitialize(NULL);
	if (FAILED(hr)) {
		std::cerr << "Failed to initialize COM library." << std::endl;
		return;
	}

	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL,
						  __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	if (FAILED(hr)) {
		std::cerr << "Failed to create device enumerator." << std::endl;
		CoUninitialize();
		return;
	}

	IMMDevice *defaultDevice = NULL;
	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	if (FAILED(hr)) {
		std::cerr << "Failed to get default audio endpoint." << std::endl;
		deviceEnumerator->Release();
		CoUninitialize();
		return;
	}

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
								 CLSCTX_ALL, NULL, (LPVOID *)&endpointVolume);
	if (FAILED(hr)) {
		std::cerr << "Failed to activate endpoint volume." << std::endl;
		defaultDevice->Release();
		deviceEnumerator->Release();
		CoUninitialize();
		return;
	}

	float vol = volume / 100.0f;
	hr = endpointVolume->SetMasterVolumeLevelScalar(vol, NULL);
	if (FAILED(hr)) {
		std::cerr << "Failed to set master volume level." << std::endl;
	}

	endpointVolume->Release();
	defaultDevice->Release();
	deviceEnumerator->Release();
	CoUninitialize();
}

// 获取系统时间
void GetSystemTimeStr(char *timeStr)
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	sprintf(timeStr, "%04d-%02d-%02d %02d:%02d:%02d",
			st.wYear, st.wMonth, st.wDay,
			st.wHour, st.wMinute, st.wSecond);
}

// 模拟键盘输入
void SimulateKeyPress(WORD key)
{
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wVk = key;
	input.ki.dwFlags = 0;
	SendInput(1, &input, sizeof(INPUT));

	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

// 模拟鼠标点击
void SimulateMouseClick(int x, int y)
{
	SetCursorPos(x, y);
	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}

// 模拟鼠标移动
void SimulateMouseMove(int x, int y)
{
	SetCursorPos(x, y);
}

// 获取鼠标位置
void GetMousePosition(int &x, int &y)
{
	POINT p;
	GetCursorPos(&p);
	x = p.x;
	y = p.y;
}

// 注册窗口类并返回窗口句柄
HWND CreateWindowHandle(const char *title, int x, int y, int width, int height)
{
	const char CLASS_NAME[] = "winapi_window_class";

	WNDCLASSA wc = { };

	wc.lpfnWndProc   = DefWindowProcA;
	wc.hInstance     = GetModuleHandle(NULL);
	wc.lpszClassName = CLASS_NAME;

	RegisterClassA(&wc);

	return CreateWindowA(CLASS_NAME, title, WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, GetModuleHandle(NULL), NULL);
}

// 获取窗口句柄
HWND GetWindowHandle(const char *title)
{
	return FindWindowA(NULL, title);
}

// 获取窗口位置
void GetWindowPosition(HWND hwnd, int &x, int &y)
{
	RECT rect;
	GetWindowRect(hwnd, &rect);
	x = rect.left;
	y = rect.top;
}

// 设置窗口位置
void SetWindowPosition(HWND hwnd, int x, int y)
{
	SetWindowPos(hwnd, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);
}

// 获取窗口大小
void GetWindowSize(HWND hwnd, int &width, int &height)
{
	RECT rect;
	GetWindowRect(hwnd, &rect);
	width = rect.right - rect.left;
	height = rect.bottom - rect.top;
}

// 设置窗口大小
void SetWindowSize(HWND hwnd, int width, int height)
{
	SetWindowPos(hwnd, HWND_TOP, 0, 0, width, height, SWP_NOMOVE);
}

// 获取窗口标题
void GetWindowTitle(HWND hwnd, char *title)
{
	GetWindowTextA(hwnd, title, 256);
}

// 获取窗口类名
void GetWindowClassName(HWND hwnd, char *className)
{
	GetClassNameA(hwnd, className, 256);
}

// 获取窗口进程ID
DWORD GetWindowProcessId(HWND hwnd)
{
	DWORD pid;
	GetWindowThreadProcessId(hwnd, &pid);
	return pid;
}

// 获取窗口父窗口
HWND GetWindowParent(HWND hwnd)
{
	return GetParent(hwnd);
}

// 获取窗口子窗口
HWND GetWindowChild(HWND hwnd)
{
	return GetWindow(hwnd, GW_CHILD);
}

// 获取窗口兄弟窗口
HWND GetWindowNext(HWND hwnd)
{
	return GetWindow(hwnd, GW_HWNDNEXT);
}

// 获取窗口层级
int GetWindowLevel(HWND hwnd)
{
    HWND parent = GetParent(hwnd);
    int level = 0;
    while (parent != NULL)
    {
        level++;
        parent = GetParent(parent);
    }
    return level;
}

// 获取窗口类样式
DWORD GetWindowClassStyle(HWND hwnd)
{
    char className[256];
    GetClassNameA(hwnd, className, sizeof(className));
    WNDCLASSEXA wc;
    if (GetClassInfoExA(GetModuleHandle(NULL), className, &wc))
    {
        return wc.style;
    }
    return 0;
}

// 获取窗口进程句柄
HANDLE GetWindowProcessHandle(HWND hwnd)
{
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetWindowProcessId(hwnd));
}

// 设置一个窗口为另一个窗口的子窗口
void SetWindowChild(HWND hwnd, HWND parent)
{
	SetParent(hwnd, parent);
}

// 设置一个窗口为另一个窗口的父窗口
void SetWindowParent(HWND hwnd, HWND child)
{
	SetParent(child, hwnd);
}