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
 * @fn void plusPressed(AppData_t* psAppData)
 * @brief increases the length of the chess board and prints the updated board
 * @param AppData_t* psAppData
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void plusPressed(AppData_t* psAppData)
{
	int*** pppiBoard = &psAppData->ppiChessBoard;
	int* piBoardLength = &psAppData->iChessBoardLength;

	incrementBoardLength(piBoardLength);
	freeChessBoardMemory(psAppData->ppiChessBoard);
	generateChessBoard(pppiBoard, *piBoardLength);
	printUserInterface(psAppData);
}

/**
 * @fn void minusPressed(AppData_t* psAppData)
 * @brief decreases the length of the chess board and prints the updated board
 * @param AppData_t* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void minusPressed(AppData_t* psAppData)
{
	int*** pppiBoard = &psAppData->ppiChessBoard;
	int* piBoardLength = &psAppData->iChessBoardLength;

	decrementBoardLength(piBoardLength);
	freeChessBoardMemory(psAppData->ppiChessBoard);
	generateChessBoard(pppiBoard, *piBoardLength);
	printUserInterface(psAppData);
}

/**
 * @fn void fPressed(AppData_t* psAppData)
 * @brief changes the file save mode and updates the status bar
 * @param AppData_t* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void fPressed(AppData_t* psAppData)
{
	changeFileSaveMode(&psAppData->eFileSaveMode);
	printStatusBar(psAppData);
}

/**
 * @fn void mPressed(AppData_t* psAppData)
 * @brief changes the algorithm mode and updates the status bar
 * @param AppData_t* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void mPressed(AppData_t* psAppData)
{
	changeAlgorithmMode(&psAppData->eAlgorithmMode);
	printStatusBar(psAppData);
}

/**
 * @fn void nPressed(AppData_t* psAppData)
 * @brief changes the file name and updates the status bar
 * @param AppData_t* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void nPressed(AppData_t* psAppData)
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
 * @fn void rPressed(AppData_t* psAppData)
 * @brief run algorithm to find solutions
 * @param AppData_t* psAppData
 * @return void 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void rPressed(AppData_t* psAppData)
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