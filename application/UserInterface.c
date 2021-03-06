/**
 * @file UserInterface.c
 * @brief contains functions to output the user interface
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"

/**
 * @fn void printMenu(void)
 * @brief prints the menu to the console window
 * @param void
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
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
 * @fn void printBoard(char acBoard[], const int iBoardLength)
 * @brief prints the chess board to the console window
 * @param char acBoard[]
 * @param const int iBoardLength
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printBoard(char acBoard[], const int iBoardLength) 
{
	short int siBoardXCoordinats[13] = { 0, 0, 0, 0, 31, 30, 29, 26, 25, 23, 21, 19, 16 };
	short int siX = siBoardXCoordinats[iBoardLength];
	short int siY = 7;
	short int siRowCounter = 0;

	const char acDelimiter[2] = "\n";
	char* pcToken;

	// The string acBoard has to be cut, because it has the wrong format (it contains the solution number). 
	pcToken = strtok(acBoard, acDelimiter);

	while (pcToken != NULL)
	{
		_gotoxy(siX, siY + siRowCounter);

		if (strstr(pcToken, "-") || strstr(pcToken, "|"))
		{
			printf("%s \n", pcToken);
			siRowCounter++;
		}

		pcToken = strtok(NULL, acDelimiter);
	}
}

/**
 * @fn void printStatus(const AppData_t* const psAppData, const char acAlgorithmMode[], const char acFileSave[])
 * @brief prints the status bar to the console window
 * @param const AppData_t* const psAppData, const char acAlgorithmMode[], const char acFileSave[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printStatus(const AppData_t* const psAppData, const char acAlgorithmMode[], const char acFileSave[])
{
	_gotoxy(0, (short int)MENU_HEIGHT + (short int)psAppData->iChessBoardLength * 2 + (short int)PADDING_STATUS_BAR);

	printf("==== Status =====================================================================\n");
	printf("|  Amount of solutions: %-5d  |  %-22s  |  Runtime: %-8f  |\n", psAppData->iAmountOfSolutions, psAppData->acProgramStatus , psAppData->fRuntime);
	printf("|-------------------------------------------------------------------------------|\n");
	printf("|  Mode: %s               Board size: %2dx%2d          Save to file: %-3s  |\n", acAlgorithmMode, psAppData->iChessBoardLength, psAppData->iChessBoardLength, acFileSave);
	printf("|  Path to file and name (max. length: 75):                                     |\n");
	printf("|  %-75s  |\n", psAppData->acFilename);
	printf("|  %-75s  |\n", psAppData->acErrorDescription);
	printf("=================================================================================\n");
}