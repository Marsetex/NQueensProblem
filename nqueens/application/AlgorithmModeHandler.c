/**
 * @file AlgorithmModeHandler.c
 * @brief functions for handling the algorithm mode tasks after a solution was found 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/AlgorithmModeHandler.h"
#include "../common_includes/OutputController.h"
#include "../common_includes/UserInputAlgorithm.h"

/**
* @fn void handleOneByOneMode(AppData_t* psAppData, bool* bAlgorithmRunning, bool* bExitPressed)
* @brief waits for user input in ony-by-one-mode and handles it
* @param AppData_t* psAppData, bool* bAlgorithmRunning, bool* bExitPressed
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void handleOneByOneMode(AppData_t* psAppData, bool* bAlgorithmRunning, bool* bExitPressed)
{
	printChessBoard(psAppData->ppiChessBoard, psAppData->iChessBoardLength, psAppData->iAmountOfSolutions);
	strncpy(psAppData->acProgramStatus, "Any key to advance...", 23);
	printStatusBar(psAppData);

	waitForUserInputInOneByOne(bAlgorithmRunning, bExitPressed);
}

/**
* @fn void handleContinuousMode(bool* bAlgorithmRunning, bool* bExitPressed)
* @brief waits for user input in continuous-mode and handles it
* @param bool* bAlgorithmRunning, bool* bExitPressed
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void handleContinuousMode(bool* bAlgorithmRunning, bool* bExitPressed)
{
	waitForUserInputInContinuous(bAlgorithmRunning, bExitPressed);
}