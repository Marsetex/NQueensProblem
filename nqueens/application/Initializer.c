/**
 * @file Initializer.c
 * @brief contains methods to initialize the application
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <string.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/Initializer.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/DataManipulator.h"
#include "../common_includes/OutputController.h"

/**
 * @fn void initConsoleWindow(void)
 * @brief initializes the console window
 * @param void
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initConsoleWindow(void)
{
	setTitleOfConsoleWindow("NQueens-Problem");
	setSizeOfConsoleWindow();
	setCursorVisibility(0);
}

/**
 * @fn void initApplicationData(AppData_t* const psAppData) 
 * @brief initializes the application data
 * @param AppData_t* const psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initApplicationData(AppData_t* const psAppData)
{
	generateChessBoard(&psAppData->ppiChessBoard, SMALLEST_BOARD);
	psAppData->iChessBoardLength = SMALLEST_BOARD;
	psAppData->iAmountOfSolutions = AMOUNT_OF_SOLUTIONS;
	strncpy(psAppData->acFilename, "..//resources//solutions.txt", 75);
	psAppData->eAlgorithmMode = MODUS_CONTINUOUS;
	psAppData->eFileSaveMode = FILE_SAVE_OFF;
	psAppData->fRuntime = DEFAULT_RUNTIME;
	strncpy(psAppData->acProgramStatus, "Pending...", 23);
	strncpy(psAppData->acErrorDescription, "Error: -", 75);
	psAppData->bExitKeyPressed = false;
}

/**
 * @fn void initUserInterface(const AppData_t* const psAppData)
 * @brief initializes the user interface
 * @param const AppData_t* const psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initUserInterface(const AppData_t* const psAppData)
{
	printUserInterface(psAppData);
}