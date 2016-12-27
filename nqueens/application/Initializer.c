/**
 * @file Initializer.c
 * @brief
 * @author
 * @date
 */
#include <string.h>

#include "../common_includes/NQueensData.h"
#include "../common_includes/Initializer.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/DataManipulator.h"
#include "../common_includes/StringBuilder.h"
#include "../common_includes/OutputController.h"

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void initializeProgram(nQueensData* psNQueens)
{
	// Init Console window
	setConsoleWindowProperties();
	setCursorPorperties(0);

	// Init data
	psNQueens->iChessBoardLength = SMALLEST_BOARD;
	psNQueens->iAmountOfSolutions = AMOUNT_OF_SOLUTIONS;
	strncpy(psNQueens->acFilename, "..//resources//solutions.txt", 255);
	psNQueens->eAlgoModus = MODUS_CONTINUOUS;
	psNQueens->eSaveModus = FILE_SAVE_OFF;
	psNQueens->fRuntime = DEFAULT_RUNTIME;
	strncpy(psNQueens->acProgramStatus, "Pending...", 23);
	generateChessBoard(&psNQueens->ppiChessBoard, SMALLEST_BOARD);

	// Init gui
	printUserInterface(psNQueens);
}