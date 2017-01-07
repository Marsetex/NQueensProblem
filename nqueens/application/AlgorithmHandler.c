/**
 * @file AlgorithmHandler.c
 * @brief handles the tasks after a solution was found
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/Algorithm.h"
#include "../common_includes/StringConverter.h"
#include "../common_includes/FileWriter.h"
#include "../common_includes/OutputController.h"
#include "../common_includes/RuntimeCalculator.h"

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

/**
 * @fn void saveSolutionToFile(applicationData* appData, bool* bFirstTryToWrite)
 * @brief saves the solution to file; also clears the file if it is the first append 
 * @param applicationData* appData, bool* bFirstTryToWrite
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void saveSolutionToFile(applicationData* appData, bool* bFirstTryToWrite) 
{
	char acBoard[1350] = { "" };

	if (*bFirstTryToWrite == true)
	{
		*bFirstTryToWrite = false;
		clearContentOfFile(appData->acFilename);
	}

	convertChessBoardToString(acBoard, appData->ppiChessBoard, appData->iChessBoardLength, appData->iAmountOfSolutions);
	appendToFile(acBoard, appData->acFilename);
}

/**
 * @fn void handleOneByOneMode(applicationData* appData, bool* bAlgorithmRunning, bool* bExitPressed) 
 * @brief waits for user input in ony-by-one-mode and handles it
 * @param applicationData* appData, bool* bAlgorithmRunning, bool* bExitPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void handleOneByOneMode(applicationData* appData, bool* bAlgorithmRunning, bool* bExitPressed) 
{
	bool bInterruptActive = true;

	printChessBoard(appData->ppiChessBoard, appData->iChessBoardLength, appData->iAmountOfSolutions);
	strncpy(appData->acProgramStatus, "Any key to advance...", 23);
	printStatusBar(appData);

	while (bInterruptActive) {
		int iChar = _getch();

		switch (iChar)
		{
			case 's':
				*bAlgorithmRunning = false;
				bInterruptActive = false;
				break;
			case 'e':
				*bAlgorithmRunning = false;
				bInterruptActive = false;
				*bExitPressed = true;
				break;
			default:
				bInterruptActive = false;
				break;
		}
	}
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
	if (_kbhit())
	{
		if (_getch() == 'e')
		{
			*bAlgorithmRunning = false;
			*bExitPressed = true;
		}
	}
}