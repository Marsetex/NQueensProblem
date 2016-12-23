#include <stdio.h>
#include <stdbool.h>
#include "../common_includes/Algorithm.h"

#define N 4

/* This function solves the N Queen problem using
Backtracking. It mainly uses solveNQUtil() to
solve the problem. It returns false if queens
cannot be placed, otherwise return true and
prints placement of queens in the form of 1s.
Please note that there may be more than one
solutions, this function prints one of the
feasible solutions.*/
bool solveNQ()
{
	int board[N][N];

	// init board
	for (int m = 0; m < N; m++) {
		for (int l = 0; l < N; l++) {
			board[m][l] = 0;
		}
	}

	int solutionCounter = 0;
	int row = 0;
	bool active = true;

	while (active) {

		if (solveNQUtil(board, 0) == false)
		{
			if (solutionCounter == 0)
			{
				printf("Solution does not exist");
			}
			active = false;
		}
		else {
			solutionCounter++;
			printSolution(board);
			printf("Solution %d found \n   ----- \n", solutionCounter);
		}
	}
	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int board[N][N], int col)
{
	int row = 0;
	bool bQueenAlreadySet = false;
	bool bQueen = false;

	/* base case: If all queens are placed then return true */
	if (col >= N) 
	{
		bQueen = true;
	} 
	else
	{
		// Check if there is a queen set it in this column
		for (int m = 0; m < N; m++) {
			if (board[m][col] == 1)
			{
				if (col != N - 1)
				{
					row = m;
					bQueenAlreadySet = true;
				}
				else if (col == N - 1)
				{
					//printf("Last colum");
					row = m + 1;
					board[m][col] = 0;
				}
			}
		}

		/* Consider this column and try placing
		this queen in all rows one by one */
		for (int i = row; i < N && bQueen == false; i++)
		{
			/* Check if queen can be placed on
			board[i][col] */
			if (isSafe(board, i, col) || bQueenAlreadySet)
			{
				/* Place this queen in board[i][col] */
				board[i][col] = 1;
				bQueenAlreadySet = false;
				//printSolution(board);

				/* recur to place rest of the queens */
				if (solveNQUtil(board, col + 1)) {
					bQueen = true;
				}

				//printf("Backtrack Col %d \n", col);

				if (bQueen == false) 
				{
					/* If placing queen in board[i][col]
					doesn't lead to a solution, then
					remove queen from board[i][col] */
					board[i][col] = 0; // BACKTRACK
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
bool isSafe(int board[N][N], int row, int col)
{
	bool bSave = true;

	bSave = checkLeftSideOfRow(board, row, col);

	if (bSave == true) 
	{
		bSave = checkLeftUpperDiagonal(board, row, col);
	}

	if (bSave == true) 
	{
		bSave = checkLeftLowerDiagonal(board, row, col);
	}

	return bSave;
}

	/* Check this row on left side */
bool checkLeftSideOfRow(const int board[N][N], const int row, const int col)
{
	bool bLeftSideSafe = true;

	for (int i = 0; i < col; i++)
	{
		if (board[row][i])
		{
			bLeftSideSafe = false;
		}
	}

	return bLeftSideSafe;
}

/* Check upper diagonal on left side */
bool checkLeftUpperDiagonal(const int board[N][N], const int row, const int col)
{
	int i;
	int j;
	bool bLeftUpperDiagonalSafe = true;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
		{
			bLeftUpperDiagonalSafe = false;
		}
	}

	return bLeftUpperDiagonalSafe;
}

/* Check lower diagonal on left side */
bool checkLeftLowerDiagonal(const int board[N][N], const int row, const int col)
{
	int i;
	int j;
	bool bLeftLowerDiagonalSafe = true;

	for (i = row, j = col; j >= 0 && i < N; i++, j--) 
	{
		if (board[i][j]) 
		{
			bLeftLowerDiagonalSafe = false;
		}
	}

	return bLeftLowerDiagonalSafe;
}

/* A utility function to print solution */
void printSolution(int board[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}

	printf("---------- \n");
}