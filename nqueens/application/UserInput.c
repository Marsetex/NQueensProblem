/**
 * @file UserInput.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/Algorithm.h"

void userInput(struct nQueens* psNQueens) 
{
	solveNQ(psNQueens->ppiChessBoard, psNQueens->iChessBoardLength);

	getchar();
}