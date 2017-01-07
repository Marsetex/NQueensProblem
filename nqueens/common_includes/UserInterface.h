/**
 * @file UserInterface.h
 * @brief declarations of the functions for UserInterface.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

#define MENU_HEIGHT 5
#define PADDING_STATUS_BAR 5

void printMenu(void);
void printBoard(char acBoard[], const int iBoardLength);
void printStatus(const int iBoardLength, const char acAlgorithmMode[], const char acFileSave[], const char acProgramStatus[], const int iAmountOfSolutions, const float fRuntime, const char acFilename[]);