/**
 * @file UserInterface.h
 * @brief contains the functions of Kap12_Auf02_DLL.c
 * @author Marcel Gruessinger
 * @date 17.12.2016
 */

#define MENU_HEIGHT 5

#define PADDING_STATUS_BAR 5

void printMenu(void);
void printBoard(int** ppiBoard, int iBoardLength);
void printBoard2(char s[], int iBoardLength);
void printStatus(struct nQueens* psNQueens);