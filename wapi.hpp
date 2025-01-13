#include "define.h"

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
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL,
						  __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);

	IMMDevice *defaultDevice = NULL;
	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);

	IAudioEndpointVolume *endpointVolume = NULL;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
								 CLSCTX_ALL, NULL, (LPVOID *)&endpointVolume);

	float vol = volume / 100.0f;
	endpointVolume->SetMasterVolumeLevelScalar(vol, NULL);

	endpointVolume->Release();
	defaultDevice->Release();
	deviceEnumerator->Release();
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