/**
 * @file Initializer.h
 * @brief
 * @author
 * @date
 */
#pragma warning(disable:4996)

void generateChessBoard(int*** pppiBoard, int iBoardLength);
void incrementBoardLength(int* piBoardLength);
void decrementBoardLength(int* piBoardLength);
void freeChessBoardMemory(int** ppiBoard);
void changeFileSaveMode(int* eSaveMode);
void changeAlgorithmMode(int* eAlgoMode);
void changeFileName(char fileName[], char newFileName[]);