/**
 * @file UserInterface.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include "../common_includes/Utilities.h"
#include "../common_includes/UserInterface.h"

void printMenu(void) 
{
	_gotoxy(0, 0);

	printf("==== NQueens problem menu =======================================================\n");
	printf("|  Increase board size: +     Modus (one by one): o     Toggle file saving: f   |\n");
	printf("|  Decrease board size: -     Modus (continous):  c     File name:          n   |\n");
	printf("|  Run algorithm:       r     Stop algorithm:     s     Exit application:   e   |\n");
	printf("=================================================================================\n");
}

void printBoard(int** ppiBoard, int iBoardLength)
{
	int x = 35;
	int y = 6;

	_gotoxy(x, y);
	printf("---------");
	
	for (int i = 0; i < iBoardLength; i++)
	{
		_gotoxy(35, 7 + i*2);
		for (int j = 0; j < iBoardLength; j++) {
			printf("|%d", ppiBoard[i][j]);
			if (j + 1 == iBoardLength) {
				printf("|");
			}
		}
		_gotoxy(35, 7 + i*2 + 1);
		printf("---------");
	}
}

void printStatus(int iBoardLength) 
{
	_gotoxy(0, MENU_HEIGHT + iBoardLength*2 + PADDING_STATUS_BAR);

	printf("==== NQueens status =============================================================\n");
	printf("|  Amount of solutions: 14200                            Runtime: 14,56568      |\n");
	printf("|  Board size: 12x12         Modus: One by one           File saving: OFF       |\n");
	printf("|  File name: C:\\temp\\hi.txt                                                    |\n");
	printf("=================================================================================\n");
}