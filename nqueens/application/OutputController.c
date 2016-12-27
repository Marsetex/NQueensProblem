/**
 * @file FileName
 * @brief
 * @author
 * @date
 */
#include "../common_includes/NQueensData.h"
#include "../common_includes/OutputController.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/StringBuilder.h"

void printUserInterface(struct nQueens* psNQueens)
{
	char s[1350] = { "" };
	createCharArray(s, psNQueens->ppiChessBoard, psNQueens->iChessBoardLength, psNQueens->iAmountOfSolutions);

	_clrscr();
	printMenu();
	printBoard(s, psNQueens->iChessBoardLength);
	printStatusBar(psNQueens);
}

void printChessBoard(int** ppiChessBoard, int iChessBoardLength, int iAmountOfSolutions)
{
	char s[1350] = { "" };
	createCharArray(s, ppiChessBoard, iChessBoardLength, iAmountOfSolutions);
	printBoard(s, iChessBoardLength);
}

void printStatusBar(struct nQueens* psNQueens)
{
	char acBoardLength[6];
	char acModus[11];
	char acFileSave[4];
	char acProgramStatus[23] = { "Pending..." };

	// TODO: Converter class
	strncpy(acModus, psNQueens->eAlgoModus == 1 ? "Continious" : "One by One", 11);
	strncpy(acFileSave, psNQueens->eSaveModus == 1 ? "ON" : "OFF", 4);

	printStatus(psNQueens->iChessBoardLength, acModus, acFileSave, "Pending...", psNQueens->iAmountOfSolutions, psNQueens->fRuntime, psNQueens->acFilename);
}