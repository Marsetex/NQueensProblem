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

#pragma warning(disable:4996)

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

	printf("==== Menu =======================================================================\n");
	printf("|  Increase board size: +     Toggle save mode:   f     Toggle mode:        m   |\n");
	printf("|  Decrease board size: -     Change file name:   n     Exit application:   e   |\n");
	printf("|  Run algorithm:       r     Stop algorithm:     s                             |\n");
	printf("=================================================================================\n");
}

void printBoard(int** ppiBoard, int iBoardLength)
{
	short x = 30-(short)iBoardLength;
	short y = 7;
	char s[68] = { "-" };
	_gotoxy(x, y);

	for (int i = 0; i < iBoardLength; i++) 
	{
		strcat(s, "----");
	}
	printf("%s", s);
	
	for (int i = 0; i < iBoardLength; i++)
	{
		_gotoxy(x, y + 1 + (short)i*2);
		for (int j = 0; j < iBoardLength; j++) {
			if (ppiBoard[i][j] == 1) 
			{
				printf("| Q ", ppiBoard[i][j]);
			}
			else {
				printf("|   ", ppiBoard[i][j]);
			}

			if (j + 1 == iBoardLength) {
				printf("|");
			}
		}
		_gotoxy(x, y + 1 + (short)i*2 + 1);
		printf("%s", s);
	}
}

void printStatus(struct nQueens* psNQueens)
{
	int iBoardLength = psNQueens->iChessBoardLength;

	char acBoardLength[6];
	char acModus[11];
	char acFileSave[4];
	char acProgramStatus[23] = { "Pending..." };

	// TODO: Converter class
	if (iBoardLength < 10)
	{
		sprintf(acBoardLength, "0%dx0%d", iBoardLength, iBoardLength);
	}
	else 
	{
		sprintf(acBoardLength, "%dx%d", iBoardLength, iBoardLength);
	}
	strncpy(acModus, psNQueens->eAlgoModus == 1 ? "Continious" : "One by One", 11);
	strncpy(acFileSave, psNQueens->eSaveModus == 1 ? "ON" : "OFF", 4);
	_gotoxy((short)0, (short)MENU_HEIGHT + (short)iBoardLength*2 + (short)PADDING_STATUS_BAR);

	printf("==== Status =====================================================================\n");
	printf("|  Amount of solutions: %-5d  |  %-22s  |  Runtime: %-8f  |\n", psNQueens->iAmountOfSolutions, acProgramStatus , psNQueens->fRuntime);
	printf("|-------------------------------------------------------------------------------|\n");
	printf("|  Mode: %s               Board size: %s          Save to file: %-3s  |\n", acModus, acBoardLength, acFileSave);
	printf("|  Path to file and name (max. length: 75):                                     |\n");
	printf("|  %-75s  |\n", psNQueens->acFilename);
	printf("=================================================================================\n");
}