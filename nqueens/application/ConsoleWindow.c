/**
 * @file ConsoleWindow.c
 * @brief
 * @author
 * @date
 */
#include <windows.h>
#include "../common_includes/ConsoleWindow.h"

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void setConsoleWindowProperties(void)
{
	// Set up the handles for reading/writing:
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	// Change the window title:
	SetConsoleTitleA("NQueens Problem");
	// Cursor
	/*CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(wHnd, &info);*/
	// Set up the required window size:
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
	// Change the console window size:
	// Create a COORD to hold the buffer size:
	COORD bufferSize = { 10, 10 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}