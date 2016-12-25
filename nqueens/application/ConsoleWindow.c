/**
 * @file ConsoleWindow.c
 * @brief
 * @author
 * @date
 */
#include <windows.h>
#include "../common_includes/ConsoleWindow.h"

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

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
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	// Change the window title:
	SetConsoleTitleA("NQueens Problem");
	// Set up the required window size:
	SMALL_RECT windowSize = { 0, 0, 80, 20 };
	SetConsoleWindowInfo(wHnd, 1, &windowSize);
	// Change the console window size:
	// Create a COORD to hold the buffer size:
	COORD bufferSize = { 10, 10 };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}