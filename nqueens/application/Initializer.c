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
 * @fn void initApplicationData(applicationData* appData) 
 * @brief initializes the application data
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initApplicationData(applicationData* appData) 
{
	generateChessBoard(&appData->ppiChessBoard, SMALLEST_BOARD);
	appData->iChessBoardLength = SMALLEST_BOARD;
	appData->iAmountOfSolutions = AMOUNT_OF_SOLUTIONS;
	strncpy(appData->acFilename, "..//resources//solutions.txt", 255);
	appData->eAlgorithmMode = MODUS_CONTINUOUS;
	appData->eSaveMode = FILE_SAVE_OFF;
	appData->fRuntime = DEFAULT_RUNTIME;
	strncpy(appData->acProgramStatus, "Pending...", 23);
}

/**
 * @fn void initUserInterface(applicationData* appData)
 * @brief initializes the user interface
 * @param applicationData* appData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initUserInterface(applicationData* appData)
{
	printUserInterface(appData);
}