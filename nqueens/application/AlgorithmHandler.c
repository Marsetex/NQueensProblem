/**
 * @file FileName
 * @brief
 * @author
 * @date
 */
#include <conio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/Algorithm.h"
#include "../common_includes/StringBuilder.h"
#include "../common_includes/FileWriter.h"
#include "../common_includes/OutputController.h"

 /* This function solves the N Queen problem using
 Backtracking. It mainly uses solveNQUtil() to
 solve the problem. It returns false if queens
 cannot be placed, otherwise return true and
 prints placement of queens in the form of 1s.
 Please note that there may be more than one
 solutions, this function prints one of the
 feasible solutions.*/
void runAlgorithm(nQueensData* data)
{
	bool bAlgorithmRunning = true;
	bool bFirstTryToWrite = true;
	bool bInterruptActive = true;
	data->iAmountOfSolutions = 0;
	data->fRuntime = 0.0f;
	
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

			if (data->eSaveModus == ON)
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

			if (data->eAlgoModus == MODUS_ONE_BY_ONE)
			{
				printChessBoard(data->ppiChessBoard, data->iChessBoardLength, data->iAmountOfSolutions);

				while (bInterruptActive) {
					int iChar = _getch();

					switch (iChar)
					{
						case 's':
							bAlgorithmRunning = false;
							bInterruptActive = false;
							break;
						default:
							bInterruptActive = false;
							break;
					}
				}

				bInterruptActive = true;
			}
		}
	}
}

void calculateRuntime(clock_t lTicksStart, clock_t lTicksEnd, float* fRuntime)
{
	clock_t lTicksResult = lTicksEnd - lTicksStart;
	*fRuntime = *fRuntime + ((float)lTicksResult / CLOCKS_PER_SEC);
}