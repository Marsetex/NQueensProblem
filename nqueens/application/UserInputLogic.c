/**
 * @file FileName
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/DataManipulator.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/StringBuilder.h"
#include "../common_includes/OutputController.h"

void plusPressed(struct nQueens* psNQueens)
{
	int*** pppi = &psNQueens->ppiChessBoard;
	int* piBoardLength = &psNQueens->iChessBoardLength;

	incrementBoardLength(piBoardLength);
	freeChessBoardMemory(psNQueens->ppiChessBoard);
	generateChessBoard(pppi, *piBoardLength);
	printUserInterface(psNQueens);
}

void minusPressed(struct nQueens* psNQueens)
{
	int*** pppi = &psNQueens->ppiChessBoard;
	int* piBoardLength = &psNQueens->iChessBoardLength;

	decrementBoardLength(piBoardLength);
	freeChessBoardMemory(psNQueens->ppiChessBoard);
	generateChessBoard(pppi, *piBoardLength);
	printUserInterface(psNQueens);
}

void fPressed(struct nQueens* psNQueens)
{
	int* saveMode = (int*) &psNQueens->eSaveModus;

	changeFileSaveMode(saveMode);
	printStatusBar(psNQueens);
}

void mPressed(struct nQueens* psNQueens)
{
	int* a = (int*) &psNQueens->eAlgoModus;

	changeAlgorithmMode(a);
	printStatusBar(psNQueens);
}

void nPressed(struct nQueens* psNQueens)
{
	char ss[255];

	setCursorPorperties(1);
	changeFileName(psNQueens->acFilename, "");
	printStatusBar(psNQueens);
	_gotoxy((short)3, (short)23 + ((short)psNQueens->iChessBoardLength - SMALLEST_BOARD) * 2);
	gets_s(ss, 76);
	changeFileName(psNQueens->acFilename, ss);
	printStatusBar(psNQueens);
	setCursorPorperties(0);
}

void rPressed(struct nQueens* psNQueens)
{
	runAlgorithm(psNQueens);
}

void ePressed(int* iWaitingForInputActive) 
{
	*iWaitingForInputActive = 0;
}