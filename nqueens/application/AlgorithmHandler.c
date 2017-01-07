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
 * @fn void runAlgorithm(applicationData* data)
 * @brief correct handling of the tasks after a solution was found
 * @param nQueensData* data
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 *
 * Appends solution to file, handles one-by-one and continious 
 * mode, refreshes the user interface
 */
void runAlgorithm(applicationData* psAppData)
{
	bool bAlgorithmRunning = true;
	bool bFirstTryToWrite = true;
	psAppData->bExitKeyPressed = false;
	psAppData->iAmountOfSolutions = 0;
	psAppData->fRuntime = 0.0f;

	// Update status of the application
	strncpy(psAppData->acProgramStatus, "Algorithm running...", 23);
	printStatusBar(psAppData);

	while (bAlgorithmRunning)
	{
		// ticks since start of program
		clock_t lTicksStart = clock();

		bool bSolutionFound = placeQueenOnBoard(psAppData->ppiChessBoard, psAppData->iChessBoardLength, 0);
		
		// passed ticks
		clock_t lTicksEnd = clock();

		// Calculate current runtime
		calculateRuntime(lTicksStart, lTicksEnd, &psAppData->fRuntime);

		if (bSolutionFound == false)
		{
			bAlgorithmRunning = false;
		}
		else 
		{
			psAppData->iAmountOfSolutions++;
			printStatusBar(psAppData);

			if (psAppData->eSaveMode == ON)
			{
				saveSolutionToFile(psAppData, &bFirstTryToWrite);
			}

			if (psAppData->eAlgorithmMode == MODUS_ONE_BY_ONE)
			{
				handleOneByOneMode(psAppData, &bAlgorithmRunning, &psAppData->bExitKeyPressed);
			}

			if (psAppData->eAlgorithmMode == MODUS_CONTINUOUS)
			{
				handleContinuousMode(&bAlgorithmRunning, &psAppData->bExitKeyPressed);
			}
		}
	}

	// Update status of the application
	strncpy(psAppData->acProgramStatus, "Pending...", 23);
	printStatusBar(psAppData);
}