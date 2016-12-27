/**
 * @file UserInterface.h
 * @brief contains the functions of Kap12_Auf02_DLL.c
 * @author Marcel Gruessinger
 * @date 17.12.2016
 */
#pragma warning(disable:4996)

#define MENU_HEIGHT 5
#define PADDING_STATUS_BAR 5

void printMenu(void);
void printBoard(char s[], int iBoardLength);
void printStatus(int iBoardLength, char acAlgorithmMode[], char acFileSave[], char acProgramStatus[], int iAmountOfSolutions, float fRuntime, char acFilename[]);