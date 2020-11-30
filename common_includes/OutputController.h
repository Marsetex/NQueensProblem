/**
 * @file OutputController.h
 * @brief declarations of the functions for OutputController.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

void printUserInterface(const AppData_t* const appData);
void printChessBoard(const int** const ppiChessBoard, const int iChessBoardLength, const int iAmountOfSolutions);
void printStatusBar(const AppData_t* const psAppData);