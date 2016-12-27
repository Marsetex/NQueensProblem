/**
 * @file UserInput.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include <conio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/AlgorithmHandler.h"
#include "../common_includes/DataManipulator.h"
#include "../common_includes/UserInterface.h"
#include "../common_includes/Utilities.h"
#include "../common_includes/ConsoleWindow.h"

void userInput(struct nQueens* psNQueens) 
{
	int iChar = 0;
	int iA = 1;
	int*** pppi = &psNQueens->ppiChessBoard;
	int* piBoardLength = &psNQueens->iChessBoardLength;
	int* s =  &psNQueens->eSaveModus;
	int* a = &psNQueens->eAlgoModus;
	char ss[255];

	while (iA == 1) 
	{
		if(_kbhit()) 
		{
			iChar = _getch();
			// TODO: Make char lower case 

			switch (iChar)
			{
				case '+':
					incrementBoardLength(piBoardLength);
					freeChessBoardMemory(psNQueens->ppiChessBoard);
					generateChessBoard(pppi, *piBoardLength);
					printUserInterface(psNQueens);
					break;
				case '-':
					decrementBoardLength(piBoardLength);
					freeChessBoardMemory(psNQueens->ppiChessBoard);
					generateChessBoard(pppi, *piBoardLength);
					printUserInterface(psNQueens);
					break;
				case 'f':
					changeFileSaveMode(s);
					printStatus(psNQueens);
					break;
				case 'm':
					changeAlgorithmMode(a);
					printStatus(psNQueens);
					break;
				case 'n':
					setCursorPorperties(1);
					changeFileName(psNQueens->acFilename, "");
					printStatus(psNQueens);
					_gotoxy(3, 23);
					gets_s(ss, 76);
					changeFileName(psNQueens->acFilename, ss);
					printStatus(psNQueens);
					setCursorPorperties(0);
					break;
				case 'r':
					runAlgorithm(psNQueens);
					break;
				case 'e':
					iA = 0;
					break;
				default:
					break;
			}
		}
	}
}