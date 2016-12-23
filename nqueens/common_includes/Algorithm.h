/**
 * @file Kap12_Auf02_Header.h
 * @brief contains the functions of Kap12_Auf02_DLL.c
 * @author Marcel Gruessinger
 * @date 17.12.2016
 */
#include <stdbool.h>

bool solveNQ();
bool isSafe(int board[4][4], int row, int col);
bool solveNQUtil(int board[4][4], int col);
bool isSafe(int board[4][4], int row, int col);
bool checkLeftSideOfRow(int board[4][4], int row, int col);
bool checkLeftUpperDiagonal(int board[4][4], int row, int col);
bool checkLeftLowerDiagonal(int board[4][4], int row, int col);
void printSolution(int board[4][4]);