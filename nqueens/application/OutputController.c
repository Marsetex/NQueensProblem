/**
 * @file OutputController.c
 * @brief the interface for outputting information to the console window
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include "../common_includes/ApplicationData.h"
#include "../common_includes/OutputController.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/StringConverter.h"

/**
 * @fn void printUserInterface(applicationData* appData)
 * @brief prepares and prints the whole user interface
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printUserInterface(const applicationData* appData)
{
	char acBoard[1350] = { "" };

	convertChessBoardToString(acBoard, appData->ppiChessBoard, appData->iChessBoardLength, appData->iAmountOfSolutions);

	_clrscr();
	printMenu();
	printBoard(acBoard, appData->iChessBoardLength);
	printStatusBar(appData);
}

/**
 * @fn void printChessBoard(const int** ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions)
 * @brief prepares and prints the chess board
 * @param const int** ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printChessBoard(const int** ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions)
{
	char acBoard[1350] = { "" };

	convertChessBoardToString(acBoard, ppiChessBoard, iChessBoardLength, iAmountOfSolutions);

	printBoard(acBoard, iChessBoardLength);
}

/**
 * @fn void printStatusBar(const applicationData* psAppData)
 * @brief prepares and prints the status bar
 * @param const applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printStatusBar(const applicationData* psAppData)
{
	char acModus[11];
	char acFileSave[4];

	convertAlgorithmModeToString(acModus, psAppData->eAlgorithmMode);
	convertSaveModeToString(acFileSave, psAppData->eSaveMode);

	printStatus(psAppData->iChessBoardLength, acModus, acFileSave, psAppData->acProgramStatus, psAppData->iAmountOfSolutions, psAppData->fRuntime, psAppData->acFilename);
}