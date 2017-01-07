/**
 * @file Algorithm.c
 * @brief contains the recursive algorithm to find the solutions
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include "../common_includes/Algorithm.h"

/**
 * @fn bool placeQueenOnBoard(int** ppiBoard, const int iBoardLength, const int iColumn)
 * @brief tries to place a queen in the given column
 * @param int** ppiBoard, const int iBoardLength, const int iColumn
 * @return bool true and only if a queen was placed; other case false
 * @author Marcel Gruessinger
 * @date 27.12.2016
 *
 * Checks first if there is already a queen placed. If and only if that case happens the algorithm will move to the next column.
 * If the other case occurs it will try to set a queen in the given column.
 */
bool placeQueenOnBoard(int** ppiBoard, const int iBoardLength, const int iColumn)
{
	int iRow = 0;
	bool bQueenAlreadyPlaced = false;
	bool bValidPlacement = false;

	// If the board end is reached, then return true
	if (iColumn >= iBoardLength)
	{
		bValidPlacement = true;
	} 
	else
	{
		// Check if there is already queen set in this column
		for (int m = 0; m < iBoardLength; m++) {
			if (ppiBoard[m][iColumn] == 1)
			{
				if (iColumn != iBoardLength - 1)
				{
					iRow = m;
					bQueenAlreadyPlaced = true;
				}
				else if (iColumn == iBoardLength - 1)
				{
					iRow = m + 1;
					ppiBoard[m][iColumn] = 0;
				}
			}
		}

		// Try placing this queen in all rows one by one
		for (int i = iRow; i < iBoardLength && bValidPlacement == false; i++)
		{
			if (isPlacementValid(ppiBoard, i, iColumn, iBoardLength) || bQueenAlreadyPlaced)
			{
				// Place queen
				ppiBoard[i][iColumn] = 1;
				bQueenAlreadyPlaced = false;

				// Place next queen
				if (placeQueenOnBoard(ppiBoard, iBoardLength, iColumn + 1)) {
					bValidPlacement = true;
				}

				if (bValidPlacement == false)
				{
					// remove queen from board; backtracking to find the next solution
					ppiBoard[i][iColumn] = 0;
				}
			}
		}
	}

	return bValidPlacement;
}

/**
 * @fn bool isPlacementValid(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength)
 * @brief checks if a queen can be placed safely at the given position 
 * @param const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength
 * @return bool
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
bool isPlacementValid(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength)
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

/**
 * @fn bool checkLeftSideOfRow(const int** ppiBoard, const int iRow, const int iColumn)
 * @brief checks if there is any queen on the left side (same row)
 * @param const int** ppiBoard, const int iRow, const int iColumn
 * @return bool
 * @author Marcel Gruessinger 
 * @date 27.12.2016
 */
bool checkLeftSideOfRow(const int** ppiBoard, const int iRow, const int iColumn)
{
	bool bLeftSideSafe = true;

	for (int i = 0; i < iColumn; i++)
	{
		if (ppiBoard[iRow][i] == 1)
		{
			bLeftSideSafe = false;
		}
	}

	return bLeftSideSafe;
}

/**
 * @fn bool checkLeftUpperDiagonal(const int** ppiBoard, const int iRow, const int iColumn)
 * @brief checks if there is any queen on the left upper diagonal
 * @param const int** ppiBoard, const int iRow, const int iColumn
 * @return bool
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
bool checkLeftUpperDiagonal(const int** ppiBoard, const int iRow, const int iColumn)
{
	int i;
	int j;
	bool bLeftUpperDiagonalSafe = true;

	for (i = iRow, j = iColumn; i >= 0 && j >= 0; i--, j--)
	{
		if (ppiBoard[i][j] == 1)
		{
			bLeftUpperDiagonalSafe = false;
		}
	}

	return bLeftUpperDiagonalSafe;
}

/**
 * @fn bool checkLeftLowerDiagonal(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength)
 * @brief checks if there is any queen on the left upper diagonal
 * @param const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength
 * @return bool
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
bool checkLeftLowerDiagonal(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength)
{
	int i;
	int j;
	bool bLeftLowerDiagonalSafe = true;

	for (i = iRow, j = iColumn; j >= 0 && i < iBoardLength; i++, j--)
	{
		if (ppiBoard[i][j] == 1)
		{
			bLeftLowerDiagonalSafe = false;
		}
	}

	return bLeftLowerDiagonalSafe;
}