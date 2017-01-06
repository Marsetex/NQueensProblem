/**
 * @file Algorithm.h
 * @brief declarations of the functions for Algorithm.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

bool solveNQUtil(int** ppiBoard, const int iBoardLength, int iColumn);
bool isPlacementValid(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength);
bool checkLeftSideOfRow(const int** ppiBoard, const int iRow, const int iColumn);
bool checkLeftUpperDiagonal(const int** ppiBoard, const int iRow, const int iColumn);
bool checkLeftLowerDiagonal(const int** ppiBoard, const int iRow, const int iColumn, const int iBoardLength);