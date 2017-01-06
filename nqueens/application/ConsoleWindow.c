/**
 * @file ConsoleWindow.c
 * @brief sets different properties of the console
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <windows.h>
#include "../common_includes/ConsoleWindow.h"

/**
 * @fn setTitleOfConsoleWindow(const char acTitle[])
 * @brief sets the title of the console window
 * @param const char acTitle[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void setTitleOfConsoleWindow(const char acTitle[])
{
	SetConsoleTitleA(acTitle);
}

/**
 * @fn void setSizeOfConsoleWindow(void)
 * @brief sets the size of the console window
 * @param const short sRows
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void setSizeOfConsoleWindow(void)
{
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, 80, 25 };

	SetConsoleWindowInfo(wHnd, 1, &windowSize);
}

/**
 * @fn void setCursorVisibility(int iVisibility)
 * @brief changes the visibility of the cursor
 * @param int iVisibilty
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void setCursorVisibility(const int iVisibility) 
{
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = iVisibility;

	SetConsoleCursorInfo(wHnd, &info);
}