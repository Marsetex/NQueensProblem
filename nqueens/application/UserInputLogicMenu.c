/**
 * @file UserInputLogicMenu.c
 * @brief handles the business logic after a key is pressed (in menu mode)
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <stdbool.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/UserInputLogicMenu.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/DataManipulator.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/OutputController.h"

/**
 * @fn void plusPressed(applicationData* psAppData)
 * @brief increases the length of the chess board and prints the updated board
 * @param applicationData* psAppData
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void plusPressed(applicationData* psAppData)
{
	int*** pppiBoard = &psAppData->ppiChessBoard;
	int* piBoardLength = &psAppData->iChessBoardLength;

	incrementBoardLength(piBoardLength);
	freeChessBoardMemory(psAppData->ppiChessBoard);
	generateChessBoard(pppiBoard, *piBoardLength);
	printUserInterface(psAppData);
}

/**
 * @fn void minusPressed(applicationData* psAppData)
 * @brief decreases the length of the chess board and prints the updated board
 * @param applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void minusPressed(applicationData* psAppData)
{
	int*** pppiBoard = &psAppData->ppiChessBoard;
	int* piBoardLength = &psAppData->iChessBoardLength;

	decrementBoardLength(piBoardLength);
	freeChessBoardMemory(psAppData->ppiChessBoard);
	generateChessBoard(pppiBoard, *piBoardLength);
	printUserInterface(psAppData);
}

/**
 * @fn void fPressed(applicationData* psAppData)
 * @brief changes the file save mode and updates the status bar
 * @param applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void fPressed(applicationData* psAppData)
{
	changeFileSaveMode(&psAppData->eSaveMode);
	printStatusBar(psAppData);
}

/**
 * @fn void mPressed(applicationData* psAppData)
 * @brief changes the algorithm mode and updates the status bar
 * @param applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void mPressed(applicationData* psAppData)
{
	changeAlgorithmMode(&psAppData->eAlgorithmMode);
	printStatusBar(psAppData);
}

/**
 * @fn void nPressed(applicationData* psAppData)
 * @brief changes the file name and updates the status bar
 * @param applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void nPressed(applicationData* psAppData)
{
	char acFileNameInput[255];

	// show cursor
	setCursorVisibility(1);
	
	// clear file name
	changeFileName(psAppData->acFilename, "");
	printStatusBar(psAppData);

	// get new file name
	_gotoxy(3, 23 + ((short int)psAppData->iChessBoardLength - SMALLEST_BOARD) * 2);
	gets_s(acFileNameInput, 76);
	changeFileName(psAppData->acFilename, acFileNameInput);
	printStatusBar(psAppData);

	// hide cursor
	setCursorVisibility(0);
}

/**
 * @fn void rPressed(applicationData* psAppData)
 * @brief run algorithm to find solutions
 * @param applicationData* psAppData
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void rPressed(applicationData* psAppData)
{
	runAlgorithm(psAppData);
}

/**
 * @fn void ePressed(bool* bExitKeyPressed)
 * @brief sets the token, which says the application to wait for user input, to false (stop waiting for user input)
 * @param bool* bExitKeyPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void ePressed(bool* bExitKeyPressed)
{
	*bExitKeyPressed = true;
}