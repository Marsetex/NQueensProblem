/**
 * @file Kap12_Auf02_Header.h
 * @brief contains the functions of Kap12_Auf02_DLL.c
 * @author Marcel Gruessinger
 * @date 17.12.2016
 */

#define true 1
#define false 0

typedef int bool;

bool solveNQ(int** ppiBoard, int iBoardLength);
bool solveNQUtil(int** ppiBoard, const int iBoardLength, int iColumn);
bool isSafe(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength);
bool checkLeftSideOfRow(const int** ppiBoard, const int iRow, const int iColumn);
bool checkLeftUpperDiagonal(const int** ppiBoard, const int iRow, const int iColumn);
bool checkLeftLowerDiagonal(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength);
void printSolution(const int** ppiBoard, const int iBoardLength);