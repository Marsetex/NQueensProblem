/**
 * @file UserInterface.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/UserInterface.h"

void printUserInterface(struct nQueens* psNQueens)
{
	_clrscr();
	printMenu();
	printBoard(psNQueens->ppiChessBoard, psNQueens->iChessBoardLength);
	printStatus(psNQueens);
}

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

void printStatus(struct nQueens* psNQueens)
{
	int iBoardLength = psNQueens->iChessBoardLength;

	char acBoardLength[6];
	char acModus[11];
	char acFileSave[4];

	if (iBoardLength < 10)
	{
		sprintf(acBoardLength, "0%dx0%d", iBoardLength, iBoardLength);
	}
	else 
	{
		sprintf(acBoardLength, "%dx%d", iBoardLength, iBoardLength);
	}
	strncpy(acModus, psNQueens->eAlgoModus == 1 ? "CONTINIOUS" : "ONE BY ONE", 11);
	strncpy(acFileSave, psNQueens->eSaveModus == 1 ? "ON" : "OFF", 4);
	_gotoxy(0, MENU_HEIGHT + iBoardLength*2 + PADDING_STATUS_BAR);

	printf("==== NQueens status =============================================================\n");
	printf("|  Amount of solutions: %-5d                           Runtime: %-9f      |\n", psNQueens->iAmountOfSolutions, psNQueens->fRuntime);
	printf("|  Board size: %s         Modus: %s          File saving: %-3s        |\n", acBoardLength, acModus, acFileSave);
	printf("|  File name: %-14s                                                    |\n", psNQueens->acFilename);
	printf("=================================================================================\n");
}