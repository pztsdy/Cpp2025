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

// 创建一个窗口并返回句柄
HWND CreateWindowHandle(const char *title, int x, int y, int width, int height)
{
	return CreateWindowA("STATIC", title, WS_OVERLAPPEDWINDOW, x, y, width, height, NULL, NULL, NULL, NULL);
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

// 获取窗口线程ID
DWORD GetWindowThreadId(HWND hwnd)
{
	return GetWindowThreadProcessId(hwnd, NULL);
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

// 获取窗口上一个窗口
HWND GetWindowPrev(HWND hwnd)
{
	return GetWindow(hwnd, GW_HWNDPREV);
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

// 获取窗口样式
DWORD GetWindowStyle(HWND hwnd)
{
	return GetWindowLong(hwnd, GWL_STYLE);
}

// 获取窗口扩展样式
DWORD GetWindowExStyle(HWND hwnd)
{
	return GetWindowLong(hwnd, GWL_EXSTYLE);
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

// 获取窗口线程句柄
HANDLE GetWindowThreadHandle(HWND hwnd)
{
	return OpenThread(THREAD_ALL_ACCESS, FALSE, GetWindowThreadId(hwnd));
}

// 获取窗口模块句柄
HANDLE GetWindowModuleHandle(HWND hwnd)
{
	HANDLE hModule;
	DWORD processId;
	GetWindowThreadProcessId(hwnd, &processId);
	return OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
}

// 获取窗口模块文件名
void GetWindowModuleFileName(HWND hwnd, char *fileName)
{
	HMODULE hModule = (HMODULE)GetWindowModuleHandle(hwnd);
	GetModuleFileNameA(hModule, fileName, 256);
}

// 获取窗口模块路径
void GetWindowModulePath(HWND hwnd, char *path)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	strcpy(path, fileName);
	char *p = strrchr(path, '\\');
	if (p != NULL)
	{
		*(p + 1) = '\0';
	}
}

// 获取窗口模块名称
void GetWindowModuleName(HWND hwnd, char *name)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	char *p = strrchr(fileName, '\\');
	if (p != NULL)
	{
		strcpy(name, p + 1);
	}
	else
	{
		strcpy(name, fileName);
	}
}

// 获取窗口模块版本
void GetWindowModuleVersion(HWND hwnd, char *version)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			VS_FIXEDFILEINFO *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\", (LPVOID *)&pInfo, &uLen))
			{
				sprintf(version, "%d.%d.%d.%d",
						HIWORD(pInfo->dwFileVersionMS),
						LOWORD(pInfo->dwFileVersionMS),
						HIWORD(pInfo->dwFileVersionLS),
						LOWORD(pInfo->dwFileVersionLS));
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块描述
void GetWindowModuleDescription(HWND hwnd, char *description)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\FileDescription", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(description, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块公司
void GetWindowModuleCompany(HWND hwnd, char *company)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\CompanyName", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(company, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块版权
void GetWindowModuleCopyRight(HWND hwnd, char *copyRight)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\LegalCopyright", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(copyRight, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块产品名
void GetWindowModuleProductName(HWND hwnd, char *productName)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\ProductName", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(productName, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块产品版本
void GetWindowModuleProductVersion(HWND hwnd, char *productVersion)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\ProductVersion", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(productVersion, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块内部名
void GetWindowModuleInternalName(HWND hwnd, char *internalName)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\InternalName", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(internalName, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块原始文件名
void GetWindowModuleOriginalFileName(HWND hwnd, char *originalFileName)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\OriginalFilename", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(originalFileName, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块私有版本号
void GetWindowModulePrivateVersion(HWND hwnd, char *privateVersion)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\PrivateBuild", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(privateVersion, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块特殊版本
void GetWindowModuleSpecialBuild(HWND hwnd, char *specialBuild)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\StringFileInfo\\040904E4\\SpecialBuild", (LPVOID *)&pInfo, &uLen))
			{
				strcpy(specialBuild, pInfo);
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块语言
void GetWindowModuleLanguage(HWND hwnd, char *language)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	DWORD dwHandle;
	DWORD dwLen = GetFileVersionInfoSizeA(fileName, &dwHandle);
	if (dwLen > 0)
	{
		char *pBuf = new char[dwLen];
		if (GetFileVersionInfoA(fileName, dwHandle, dwLen, pBuf))
		{
			char *pInfo;
			UINT uLen;
			if (VerQueryValueA(pBuf, "\\VarFileInfo\\Translation", (LPVOID *)&pInfo, &uLen))
			{
				sprintf(language, "%04X%04X", LOWORD(*(DWORD *)pInfo), HIWORD(*(DWORD *)pInfo));
			}
		}
		delete[] pBuf;
	}
}

// 获取窗口模块编译时间
void GetWindowModuleBuildTime(HWND hwnd, char *buildTime)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	HANDLE hFile = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		FILETIME ftCreate, ftAccess, ftWrite;
		GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite);
		CloseHandle(hFile);
		SYSTEMTIME st;
		FileTimeToSystemTime(&ftWrite, &st);
		sprintf(buildTime, "%04d-%02d-%02d %02d:%02d:%02d",
				st.wYear, st.wMonth, st.wDay,
				st.wHour, st.wMinute, st.wSecond);
	}
}

// 获取窗口模块大小
DWORD GetWindowModuleSize(HWND hwnd)
{
	char fileName[256];
	GetWindowModuleFileName(hwnd, fileName);
	HANDLE hFile = CreateFileA(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD dwSize = GetFileSize(hFile, NULL);
		CloseHandle(hFile);
		return dwSize;
	}
	return 0;
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