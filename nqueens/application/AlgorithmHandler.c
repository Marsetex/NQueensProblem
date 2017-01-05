/**
 * @file AlgorithmHandler.c
 * @brief handles the tasks after a solution was found
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <string.h>
#include <conio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/Algorithm.h"
#include "../common_includes/StringBuilder.h"
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
bool runAlgorithm(applicationData* data)
{
	bool bAlgorithmRunning = true;
	bool bFirstTryToWrite = true;
	bool bInterruptActive = true;
	bool bExitPressed = false;
	data->iAmountOfSolutions = 0;
	data->fRuntime = 0.0f;

	strncpy(data->acProgramStatus, "Algorithm running...", 23);
	printStatusBar(data);

	while (bAlgorithmRunning)
	{
		// ticks since start of program
		clock_t lTicksStart = clock();

		bool solutionFound = solveNQUtil(data->ppiChessBoard, data->iChessBoardLength, 0);
		
		// passed ticks
		clock_t lTicksEnd = clock();

		calculateRuntime(lTicksStart, lTicksEnd, &data->fRuntime);

		if (solutionFound == false)
		{
			bAlgorithmRunning = false;
		}
		else 
		{
			data->iAmountOfSolutions++;
			printStatusBar(data);

			if (data->eSaveMode == ON)
			{
				if (bFirstTryToWrite == true)
				{
					bFirstTryToWrite = false;
					clearContentOfFile(data->acFilename);
				}

				char ha[1350] = { "" };
				createCharArray(ha, data->ppiChessBoard, data->iChessBoardLength, data->iAmountOfSolutions);
				appendToFile(ha, data->acFilename);
			}

			if (data->eAlgorithmMode == MODUS_ONE_BY_ONE)
			{
				printChessBoard(data->ppiChessBoard, data->iChessBoardLength, data->iAmountOfSolutions);
				strncpy(data->acProgramStatus, "Any key to advance...", 23);
				printStatusBar(data);

				while (bInterruptActive) {
					int iChar = _getch();

					switch (iChar)
					{
						case 's':
							bAlgorithmRunning = false;
							bInterruptActive = false;
							break;
						case 'e':
							bAlgorithmRunning = false;
							bInterruptActive = false;
							bExitPressed = true;
							break;
						default:
							bInterruptActive = false;
							break;
					}
				}

				bInterruptActive = true;
			}

			if (data->eAlgorithmMode == MODUS_CONTINUOUS)
			{
				if (_kbhit()) 
				{
					if(_getch() == 'e') 
					{
						bAlgorithmRunning = false;
						bExitPressed = true;
					}
				}
			}
		}
	}

	strncpy(data->acProgramStatus, "Pending...", 23);
	printStatusBar(data);

	return bExitPressed;
}