/**
 * @file DataManipulator.h
 * @brief declarations of the functions for DataManipulator.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

void generateChessBoard(int*** const pppiBoard, const int iBoardLength);
void freeChessBoardMemory(int** const ppiBoard);
void incrementBoardLength(int* const piBoardLength);
void decrementBoardLength(int* const piBoardLength);
void changeFileSaveMode(FileSaveMode_t* const peSaveMode);
void changeAlgorithmMode(AlgorithmMode_t* const peAlgoMode);
void changeFileName(char acOldFileName[], const char acNewFileName[]);