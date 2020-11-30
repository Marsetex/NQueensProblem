/**
 * @file StringBuilder.h
 * @brief declarations of the functions for StringConverter.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

void convertChessBoardToString(char acBoard[], const int** const ppiBoard, const int iBoardLength, const int iSolutionNumber);
void convertAlgorithmModeToString(char acBuffer[], const AlgorithmMode_t eAlgoMode);
void convertSaveModeToString(char acBuffer[], const FileSaveMode_t eSaveMode);