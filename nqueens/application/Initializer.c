/**
 * @file Initializer.c
 * @brief
 * @author
 * @date
 */
#include <string.h>

#include "../common_includes/Initializer.h"
#include "../common_includes/NQueensData.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/DataManipulator.h"

#pragma warning(disable:4996)

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void initializeProgram(struct nQueens* psNQueens)
{
	// Init data
	setConsoleWindowProperties();
	psNQueens->iChessBoardLength = SMALLEST_BOARD;
	psNQueens->iAmountOfSolutions = AMOUNT_OF_SOLUTIONS;
	strncpy(psNQueens->acFilename, "solutions", 255);
	psNQueens->eAlgoModus = MODUS_CONTINUOUS;
	psNQueens->eSaveModus = FILE_SAVE_OFF;
	psNQueens->fRuntime = DEFAULT_RUNTIME;
	generateChessBoard(&psNQueens->ppiChessBoard, SMALLEST_BOARD);

	// Init gui
	printUserInterface(psNQueens);
}