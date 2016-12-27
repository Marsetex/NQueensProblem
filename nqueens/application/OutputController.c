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
	printStatus(psNQueens);
}

void printChessBoard(int** ppiChessBoard, int iChessBoardLength, int iAmountOfSolutions)
{
	char s[1350] = { "" };
	createCharArray(s, ppiChessBoard, iChessBoardLength, iAmountOfSolutions);
	printBoard(s, iChessBoardLength);
}

void printStatusBar(struct nQueens* psNQueens)
{
	printStatus(psNQueens);
}