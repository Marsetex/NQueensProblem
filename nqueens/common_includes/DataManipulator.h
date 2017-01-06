/**
 * @file DataManipulator.h
 * @brief declarations of the functions for DataManipulator.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

void generateChessBoard(int*** pppiBoard, const int iBoardLength);
void freeChessBoardMemory(int** ppiBoard);
void incrementBoardLength(int* piBoardLength);
void decrementBoardLength(int* piBoardLength);
void changeFileSaveMode(fileSaveMode* eSaveMode);
void changeAlgorithmMode(algorithmMode* eAlgoMode);
void changeFileName(char acOldFileName[], const char acNewFileName[]);