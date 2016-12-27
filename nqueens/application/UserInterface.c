/**
 * @file UserInterface.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"

/**
 * @fn FunctionName
 * @brief
 * @param 
 * @return
 * @author
 * @date
 */
void printMenu(void) 
{
	_gotoxy(0, 0);

	printf("==== Menu =======================================================================\n");
	printf("|  Increase board size: +     Toggle save mode:   f     Toggle mode:        m   |\n");
	printf("|  Decrease board size: -     Change file name:   n     Exit application:   e   |\n");
	printf("|  Run algorithm:       r     Stop algorithm:     s                             |\n");
	printf("=================================================================================\n");
}

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void printBoard(char acBoard[], int iBoardLength) 
{
	short sBoardXCoordinats[13] = { 0, 0, 0, 0, 31, 30, 29, 26, 25, 23, 21, 19, 16 };
	
	short x = sBoardXCoordinats[iBoardLength];
	short y = 7;
	short i = 0;
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

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void printStatus(int iBoardLength, char acAlgorithmMode[], char acFileSave[], char acProgramStatus[], int iAmountOfSolutions, float fRuntime, char acFilename[])
{
	_gotoxy((short)0, (short)MENU_HEIGHT + (short)iBoardLength * 2 + (short)PADDING_STATUS_BAR);

	printf("==== Status =====================================================================\n");
	printf("|  Amount of solutions: %-5d  |  %-22s  |  Runtime: %-8f  |\n", iAmountOfSolutions, acProgramStatus , fRuntime);
	printf("|-------------------------------------------------------------------------------|\n");
	printf("|  Mode: %s               Board size: %2dx%2d          Save to file: %-3s  |\n", acAlgorithmMode, iBoardLength, iBoardLength, acFileSave);
	printf("|  Path to file and name (max. length: 75):                                     |\n");
	printf("|  %-75s  |\n", acFilename);
	printf("=================================================================================\n");
}