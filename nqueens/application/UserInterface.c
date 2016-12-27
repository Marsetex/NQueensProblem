/**
 * @file UserInterface.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"

#pragma warning(disable:4996)

void printMenu(void) 
{
	_gotoxy(0, 0);

	printf("==== Menu =======================================================================\n");
	printf("|  Increase board size: +     Toggle save mode:   f     Toggle mode:        m   |\n");
	printf("|  Decrease board size: -     Change file name:   n     Exit application:   e   |\n");
	printf("|  Run algorithm:       r     Stop algorithm:     s                             |\n");
	printf("=================================================================================\n");
}

void printBoard(char acBoard[], int iBoardLength) 
{
	short x = 30 - (short)iBoardLength;
	short y = 7;
	int i = 0;
	const char s[2] = "\n";
	char *token;
	
	/* get the first token */
	token = strtok(acBoard, s);

	/* walk through other tokens */
	while (token != NULL)
	{
		_gotoxy(x, y + i);

		if (strstr(token, "-") || strstr(token, "|"))
		{
			printf("%s \n", token);
			i++;
		}

		token = strtok(NULL, s);
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