/**
 * @file FileName
 * @brief
 * @author
 * @date
 */
#include <time.h>
#include <conio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/Algorithm.h"
#include "../common_includes/StringBuilder.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/FileWriter.h"

#define START_COLUMN 0

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
	bool active = true;
	data->iAmountOfSolutions = 0;
	char ha[500] = { "" };
	//char acSolutionString[500000] = { "" };

	// ticks since start of program
	clock_t lTicksStart = clock();

	while (active) 
	{
		if (solveNQUtil(data->ppiChessBoard, data->iChessBoardLength, 0) == false)
		{
			active = false;
		}
		else 
		{
			data->iAmountOfSolutions++;
			printStatus(data);


			if (data->eSaveModus == ON)
			{
				createCharArray(ha, data->ppiChessBoard, data->iChessBoardLength, data->iAmountOfSolutions);
				appendToFile(ha, data->acFilename);
			}

			if (data->eAlgoModus == MODUS_ONE_BY_ONE)
			{
				// any key -> advance; s -> stop
				printBoard(data->ppiChessBoard, data->iChessBoardLength);

				while (!_kbhit()) {

				}
			}
			//printSolution(data->ppiChessBoard, data->iChessBoardLength);
			//printf("Solution %d found \n   ----- \n", solutionCounter);
		}

		// passed ticks
		clock_t lTicksEnd = clock();

		clock_t lTicksS = lTicksEnd - lTicksStart;
		data->fRuntime = (float)lTicksS / CLOCKS_PER_SEC;
		//printf("%f seconds \n", fSeconds);

		
	}
}