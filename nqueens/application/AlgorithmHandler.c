/**
 * @file AlgorithmHandler.c
 * @brief handles the tasks after a solution was found
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/Algorithm.h"
#include "../common_includes/OutputController.h"
#include "../common_includes/RuntimeCalculator.h"
#include "../common_includes/AlgorithmModeHandler.h"
#include "../common_includes/FileSaveModeHandler.h"

/**
 * @fn bool runAlgorithm(applicationData* data)
 * @brief correct handling of the tasks after a solution was found
 * @param nQueensData* data
 * @return bool
 * @author Marcel Gruessinger
 * @date 27.12.2016
 *
 * Appends solution to file, handles one-by-one and continious 
 * mode, refreshes the user interface
 */
bool runAlgorithm(applicationData* appData)
{
	bool bAlgorithmRunning = true;
	bool bFirstTryToWrite = true;
	bool bExitPressed = false;
	appData->iAmountOfSolutions = 0;
	appData->fRuntime = 0.0f;

	// Update status of the application
	strncpy(appData->acProgramStatus, "Algorithm running...", 23);
	printStatusBar(appData);

	while (bAlgorithmRunning)
	{
		// ticks since start of program
		clock_t lTicksStart = clock();

		bool bSolutionFound = placeQueenOnBoard(appData->ppiChessBoard, appData->iChessBoardLength, 0);
		
		// passed ticks
		clock_t lTicksEnd = clock();

		// Calculate current runtime
		calculateRuntime(lTicksStart, lTicksEnd, &appData->fRuntime);

		if (bSolutionFound == false)
		{
			bAlgorithmRunning = false;
		}
		else 
		{
			appData->iAmountOfSolutions++;
			printStatusBar(appData);

			if (appData->eSaveMode == ON)
			{
				saveSolutionToFile(appData, &bFirstTryToWrite);
			}

			if (appData->eAlgorithmMode == MODUS_ONE_BY_ONE)
			{
				handleOneByOneMode(appData, &bAlgorithmRunning, &bExitPressed);
			}

			if (appData->eAlgorithmMode == MODUS_CONTINUOUS)
			{
				handleContinuousMode(&bAlgorithmRunning, &bExitPressed);
			}
		}
	}

	// Update status of the application
	strncpy(appData->acProgramStatus, "Pending...", 23);
	printStatusBar(appData);

	return bExitPressed;
}