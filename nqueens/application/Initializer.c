/**
 * @file Initializer.c
 * @brief
 * @author
 * @date
 */
#include <stdlib.h>
#include "../common_includes/Initializer.h"
#include "../common_includes/NQueensData.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/UserInterface.h"

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
	initChessBoard(&psNQueens->ppiChessBoard, SMALLEST_BOARD);

	// Init gui
	printMenu();
	printBoard(psNQueens->ppiChessBoard, psNQueens->iChessBoardLength);
	printStatus(psNQueens->iChessBoardLength);
}

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void initChessBoard(int*** pppiBoard, int iBoardLength)
{
	*pppiBoard = (int**) calloc(iBoardLength, sizeof(int*));
	for (int i = 0; i < iBoardLength; i++) {
		(*pppiBoard)[i] = (int*) calloc(iBoardLength, sizeof(int));
	}
}