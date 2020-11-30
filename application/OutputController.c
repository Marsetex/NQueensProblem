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
 * @fn void printUserInterface(const AppData_t* const psAppData)
 * @brief prepares and prints the whole user interface
 * @param const AppData_t* const psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printUserInterface(const AppData_t* const psAppData)
{
	char acBoard[1350] = { "" };

	convertChessBoardToString(acBoard, psAppData->ppiChessBoard, psAppData->iChessBoardLength, psAppData->iAmountOfSolutions);

	_clrscr();
	printMenu();
	printBoard(acBoard, psAppData->iChessBoardLength);
	printStatusBar(psAppData);
}

/**
 * @fn void printChessBoard(const int** const ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions)
 * @brief prepares and prints the chess board
 * @param const int** const ppiChessBoard
 * @param const int iChessBoardLength
 * @param const int iAmountOfSolutions
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printChessBoard(const int** const ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions)
{
	char acBoard[1350] = { "" };

	convertChessBoardToString(acBoard, ppiChessBoard, iChessBoardLength, iAmountOfSolutions);

	printBoard(acBoard, iChessBoardLength);
}

/**
 * @fn void printStatusBar(const AppData_t* const psAppData)
 * @brief prepares and prints the status bar
 * @param const AppData_t* const psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void printStatusBar(const AppData_t* const psAppData)
{
	char acModus[11];
	char acFileSave[4];

	convertAlgorithmModeToString(acModus, psAppData->eAlgorithmMode);
	convertSaveModeToString(acFileSave, psAppData->eFileSaveMode);

	printStatus(psAppData, acModus, acFileSave);
}