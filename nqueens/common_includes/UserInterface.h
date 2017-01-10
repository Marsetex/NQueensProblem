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
void printStatus(const AppData_t* const psAppData, const char acAlgorithmMode[], const char acFileSave[]);