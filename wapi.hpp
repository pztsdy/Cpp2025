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

#ifndef __INC_HEADER_
#define __INC_HEADER_ \0
#define RETURN_CHANGES_Inc 0x2418b9cc
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

void MouseMaster(POINT mouse, int x, int y){
	srand(time(0));
	GetCursorPos(&mouse);
	mouse.x=x;
	mouse.y=y;
	// printf("%d %d\n",mouse.x,mouse.y);  if you want print it, please del "\\"
	SetCursorPos(mouse.x,mouse.y);

	return ;
}
