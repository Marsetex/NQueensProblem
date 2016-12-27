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
#include "../common_includes/Utilities.h"
#include "../common_includes/ConsoleWindow.h"
#include "../common_includes/StringBuilder.h"
#include "../common_includes/OutputController.h"

void userInput(struct nQueens* psNQueens) 
{
	int iChar = 0;
	int iA = 1;
	int*** pppi = &psNQueens->ppiChessBoard;
	int* piBoardLength = &psNQueens->iChessBoardLength;
	int* saveMode =  &psNQueens->eSaveModus;
	int* a = &psNQueens->eAlgoModus;
	char ss[255];

	while (iA == 1) 
	{
		char s[1350] = { "" };

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
					createCharArray(s, psNQueens->ppiChessBoard, psNQueens->iChessBoardLength, psNQueens->iAmountOfSolutions);
					printUserInterface(psNQueens, s);
					break;
				case '-':
					decrementBoardLength(piBoardLength);
					freeChessBoardMemory(psNQueens->ppiChessBoard);
					generateChessBoard(pppi, *piBoardLength);
					createCharArray(s, psNQueens->ppiChessBoard, psNQueens->iChessBoardLength, psNQueens->iAmountOfSolutions);
					printUserInterface(psNQueens, s); 
					break;
				case 'f':
					changeFileSaveMode(saveMode);
					printStatusBar(psNQueens);
					break;
				case 'm':
					changeAlgorithmMode(a);
					printStatusBar(psNQueens);
					break;
				case 'n':
					setCursorPorperties(1);
					changeFileName(psNQueens->acFilename, "");
					printStatusBar(psNQueens);
					_gotoxy(3, 23);
					gets_s(ss, 76);
					changeFileName(psNQueens->acFilename, ss);
					printStatusBar(psNQueens);
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