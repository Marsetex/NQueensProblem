#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "../common_includes/Algorithm.h"
#include "../common_includes/Menu.h"

void init(void);

#define N 4

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console.

int main(void) {
	int board[N][N];
	
	// init board
	for (int m = 0; m < N; m++) {
		for (int l = 0; l < N; l++) {
			board[m][l] = 0;
		}
	}

	init();
	printMenu();
	printBoard(board);
	printStatus();
	//solveNQ();



	getchar();

	// Exit
	return 0;
}

void init(void) 
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