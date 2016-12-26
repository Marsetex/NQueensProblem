/**
 * @file FileName
 * @brief
 * @author
 * @date
 */
#include "../common_includes/Algorithm.h"

 /* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int** ppiBoard, const int iBoardLength, int iColumn)
{
	int row = 0;
	bool bQueenAlreadySet = false;
	bool bQueen = false;

	/* base case: If all queens are placed then return true */
	if (iColumn >= iBoardLength)
	{
		bQueen = true;
	} 
	else
	{
		// Check if there is a queen set it in this column
		for (int m = 0; m < iBoardLength; m++) {
			if (ppiBoard[m][iColumn] == 1)
			{
				if (iColumn != iBoardLength - 1)
				{
					row = m;
					bQueenAlreadySet = true;
				}
				else if (iColumn == iBoardLength - 1)
				{
					row = m + 1;
					ppiBoard[m][iColumn] = 0;
				}
			}
		}

		/* Consider this column and try placing
		this queen in all rows one by one */
		for (int i = row; i < iBoardLength && bQueen == false; i++)
		{
			/* Check if queen can be placed on
			board[i][col] */
			if (isSafe(ppiBoard, i, iColumn, iBoardLength) || bQueenAlreadySet)
			{
				/* Place this queen in board[i][col] */
				ppiBoard[i][iColumn] = 1;
				bQueenAlreadySet = false;
				//printSolution(board);

				/* recur to place rest of the queens */
				if (solveNQUtil(ppiBoard, iBoardLength, iColumn + 1)) {
					bQueen = true;
				}

				if (bQueen == false) 
				{
					/* If placing queen in board[i][col]
					doesn't lead to a solution, then
					remove queen from board[i][col] */
					ppiBoard[i][iColumn] = 0; // BACKTRACK
				}
			}
		}

		/* If queen can not be place in any row in
		this colum col then return false */
		//return false;
	}

	return bQueen;
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool isSafe(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength)
{
	bool bSave = true;

	bSave = checkLeftSideOfRow(ppiBoard, iRow, iColumn);

	if (bSave == true) 
	{
		bSave = checkLeftUpperDiagonal(ppiBoard, iRow, iColumn);
	}

	if (bSave == true) 
	{
		bSave = checkLeftLowerDiagonal(ppiBoard, iRow, iColumn, iBoardLength);
	}

	return bSave;
}

	/* Check this row on left side */
bool checkLeftSideOfRow(const int** ppiBoard, const int iRow, const int iColumn)
{
	bool bLeftSideSafe = true;

	for (int i = 0; i < iColumn; i++)
	{
		if (ppiBoard[iRow][i])
		{
			bLeftSideSafe = false;
		}
	}

	return bLeftSideSafe;
}

/* Check upper diagonal on left side */
bool checkLeftUpperDiagonal(const int** ppiBoard, const int iRow, const int iColumn)
{
	int i;
	int j;
	bool bLeftUpperDiagonalSafe = true;

	for (i = iRow, j = iColumn; i >= 0 && j >= 0; i--, j--)
	{
		if (ppiBoard[i][j])
		{
			bLeftUpperDiagonalSafe = false;
		}
	}

	return bLeftUpperDiagonalSafe;
}

/* Check lower diagonal on left side */
bool checkLeftLowerDiagonal(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength)
{
	int i;
	int j;
	bool bLeftLowerDiagonalSafe = true;

	for (i = iRow, j = iColumn; j >= 0 && i < iBoardLength; i++, j--)
	{
		if (ppiBoard[i][j])
		{
			bLeftLowerDiagonalSafe = false;
		}
	}

	return bLeftLowerDiagonalSafe;
}