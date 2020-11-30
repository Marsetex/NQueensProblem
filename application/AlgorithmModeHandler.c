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
* @fn void handleOneByOneMode(AppData_t* const psAppData, bool* const pbAlgorithmRunning, bool* const pbExitPressed)
* @brief waits for user input in ony-by-one-mode and handles it
* @param AppData_t* const psAppData
* @param bool* const pbAlgorithmRunning
* @param bool* const pbExitPressed
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void handleOneByOneMode(AppData_t* const psAppData, bool* const pbAlgorithmRunning, bool* const pbExitPressed)
{
	printChessBoard(psAppData->ppiChessBoard, psAppData->iChessBoardLength, psAppData->iAmountOfSolutions);
	strncpy(psAppData->acProgramStatus, "Any key to advance...", 23);
	printStatusBar(psAppData);

	waitForUserInputInOneByOne(pbAlgorithmRunning, pbExitPressed);
}

/**
* @fn void handleContinuousMode(bool* const pbAlgorithmRunning, bool* const pbExitPressed)
* @brief waits for user input in continuous-mode and handles it
* @param bool* const pbAlgorithmRunning
* @param bool* const pbExitPressed
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void handleContinuousMode(bool* const pbAlgorithmRunning, bool* const pbExitPressed)
{
	waitForUserInputInContinuous(pbAlgorithmRunning, pbExitPressed);
}