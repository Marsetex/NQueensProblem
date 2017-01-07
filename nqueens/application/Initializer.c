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
 * @fn void initApplicationData(applicationData* psAppData) 
 * @brief initializes the application data
 * @param applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initApplicationData(applicationData* psAppData)
{
	generateChessBoard(&psAppData->ppiChessBoard, SMALLEST_BOARD);
	psAppData->iChessBoardLength = SMALLEST_BOARD;
	psAppData->iAmountOfSolutions = AMOUNT_OF_SOLUTIONS;
	strncpy(psAppData->acFilename, "..//resources//solutions.txt", 255);
	psAppData->eAlgorithmMode = MODUS_CONTINUOUS;
	psAppData->eSaveMode = FILE_SAVE_OFF;
	psAppData->fRuntime = DEFAULT_RUNTIME;
	strncpy(psAppData->acProgramStatus, "Pending...", 23);
}

/**
 * @fn void initUserInterface(const applicationData* psAppData)
 * @brief initializes the user interface
 * @param const applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void initUserInterface(const applicationData* psAppData)
{
	printUserInterface(psAppData);
}