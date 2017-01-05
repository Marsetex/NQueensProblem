/**
 * @file OutputController.c
 * @brief the interface for outputting information
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <string.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/OutputController.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/StringBuilder.h"

/**
 * @fn void printUserInterface(applicationData* appData)
 * @brief prepares and prints the whole user interface
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printUserInterface(applicationData* appData)
{
	char acBoard[1350] = { "" };
	createCharArray(acBoard, appData->ppiChessBoard, appData->iChessBoardLength, appData->iAmountOfSolutions);

	_clrscr();
	printMenu();
	printBoard(acBoard, appData->iChessBoardLength);
	printStatusBar(appData);
}

/**
 * @fn void printChessBoard(int** ppiChessBoard, int iChessBoardLength, int iAmountOfSolutions)
 * @brief prepares and prints the chess board
 * @param int** ppiChessBoard, int iChessBoardLength, int iAmountOfSolutions
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printChessBoard(int** ppiChessBoard, int iChessBoardLength, int iAmountOfSolutions)
{
	char acBoard[1350] = { "" };
	createCharArray(acBoard, ppiChessBoard, iChessBoardLength, iAmountOfSolutions);
	printBoard(acBoard, iChessBoardLength);
}

/**
 * @fn void printStatusBar(applicationData* appData)
 * @brief prepares and prints the status bar
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printStatusBar(applicationData* appData)
{
	char acModus[11];
	char acFileSave[4];

	convertAlgorithmModeToString(acModus, appData->eAlgorithmMode);
	convertSaveModeToString(acFileSave, appData->eSaveMode);

	printStatus(appData->iChessBoardLength, acModus, acFileSave, appData->acProgramStatus, appData->iAmountOfSolutions, appData->fRuntime, appData->acFilename);
}