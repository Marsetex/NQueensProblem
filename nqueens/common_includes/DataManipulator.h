/**
 * @file Initializer.h
 * @brief
 * @author
 * @date
 */

void generateChessBoard(int*** pppiBoard, int iBoardLength);
void incrementBoardLength(int* piBoardLength);
void decrementBoardLength(int* piBoardLength);
void freeChessBoardMemory(int** ppiBoard);
void changeFileSaveMode(fileSaveActive* eSaveMode);
void changeAlgorithmMode(algorithmModus* eAlgoMode);