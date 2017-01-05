/**
 * @file OutputController.h
 * @brief declarations of the functions for OutputController.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

void printUserInterface(applicationData* psNQueens);
void printChessBoard(int** ppiChessBoard, int iChessBoardLength, int iAmountOfSolutions);
void printStatusBar(applicationData* psNQueens);