/**
 * @file Algorithm.h
 * @brief declarations of the functions for Algorithm.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

bool placeQueenOnBoard(int** const ppiBoard, const int iBoardLength, const int iColumn);
bool isPlacementValid(const int** const ppiBoard, const int iRow, const int iColumn, const int iBoardLength);
bool checkLeftSideOfRow(const int** const ppiBoard, const int iRow, const int iColumn);
bool checkLeftUpperDiagonal(const int** const ppiBoard, const int iRow, const int iColumn);
bool checkLeftLowerDiagonal(const int** const ppiBoard, const int iRow, const int iColumn, const int iBoardLength);