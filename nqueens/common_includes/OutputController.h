/**
 * @file OutputController.h
 * @brief declarations of the functions for OutputController.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

void printUserInterface(const applicationData* appData);
void printChessBoard(const int** ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions);
void printStatusBar(const applicationData* psAppData);