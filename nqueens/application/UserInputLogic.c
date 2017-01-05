/**
 * @file UserInputLogic.c
 * @brief handles the business logic after a key is pressed
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/DataManipulator.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/StringBuilder.h"
#include "../common_includes/OutputController.h"

/**
 * @fn void plusPressed(applicationData* appData)
 * @brief increases the length of the chess board and prints the updated board
 * @param applicationData* appData
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void plusPressed(applicationData* appData)
{
	int*** pppi = &appData->ppiChessBoard;
	int* piBoardLength = &appData->iChessBoardLength;

	incrementBoardLength(piBoardLength);
	freeChessBoardMemory(appData->ppiChessBoard);
	generateChessBoard(pppi, *piBoardLength);
	printUserInterface(appData);
}

/**
 * @fn void minusPressed(applicationData* appData)
 * @brief decreases the length of the chess board and prints the updated board
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void minusPressed(applicationData* appData)
{
	int*** pppi = &appData->ppiChessBoard;
	int* piBoardLength = &appData->iChessBoardLength;

	decrementBoardLength(piBoardLength);
	freeChessBoardMemory(appData->ppiChessBoard);
	generateChessBoard(pppi, *piBoardLength);
	printUserInterface(appData);
}

/**
 * @fn void fPressed(applicationData* appData)
 * @brief changes the file save mode and updates the status bar
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void fPressed(applicationData* appData)
{
	changeFileSaveMode(&appData->eSaveMode);
	printStatusBar(appData);
}

/**
 * @fn void mPressed(applicationData* appData)
 * @brief changes the algorithm mode and updates the status bar
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void mPressed(applicationData* appData)
{
	changeAlgorithmMode(&appData->eAlgorithmMode);
	printStatusBar(appData);
}

/**
 * @fn void nPressed(applicationData* appData)
 * @brief changes the file name and updates the status bar
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void nPressed(applicationData* appData)
{
	char acFileNameInput[255];

	// show cursor
	setCursorVisibility(1);
	
	// clear file name
	changeFileName(appData->acFilename, "");
	printStatusBar(appData);

	// get new file name
	_gotoxy((short)3, (short)23 + ((short)appData->iChessBoardLength - SMALLEST_BOARD) * 2);
	gets_s(acFileNameInput, 76);
	changeFileName(appData->acFilename, acFileNameInput);
	printStatusBar(appData);

	// hide cursor
	setCursorVisibility(0);
}

/**
 * @fn bool rPressed(applicationData* appData)
 * @brief run algorithm to find solutions
 * @param applicationData* appData
 * @return bool user wants to exit 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
bool rPressed(applicationData* appData)
{
	return runAlgorithm(appData);
}

/**
 * @fn void ePressed(int* iWaitingForInputActive)
 * @brief sets the token, which says the application to wait for user input, to 0 (stop waiting for user input)
 * @param int* iWaitingForInputActive
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void ePressed(int* iWaitingForInputActive) 
{
	*iWaitingForInputActive = 0;
}