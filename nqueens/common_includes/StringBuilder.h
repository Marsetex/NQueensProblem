/**
 * @file StringBuilder.h
 * @brief declarations of the functions for StringBuilder.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#pragma warning(disable:4996)

void createCharArray(char dest[], int** source, int iBoardLength, int iSolutionNumber);
void convertAlgorithmModeToString(char acBuffer[], algorithmMode algoMode);
void convertSaveModeToString(char acBuffer[], fileSaveActive saveMode);