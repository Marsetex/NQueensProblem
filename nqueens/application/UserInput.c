/**
 * @file UserInput.c
 * @brief
 * @author
 * @date
 */
#include <stdio.h>
#include <conio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/UserInput.h"
#include "../common_includes/UserInputLogic.h"

void userInput(struct nQueens* psNQueens) 
{
	int iChar = 0;
	bool bWaitingForInputActive = true;
	
	while (bWaitingForInputActive)
	{
		if(_kbhit()) 
		{
			// TODO: Make char lower case 
			iChar = _getch();

			switch (iChar)
			{
				case '+':
					plusPressed(psNQueens);
					break;
				case '-':
					minusPressed(psNQueens);
					break;
				case 'f':
					fPressed(psNQueens);
					break;
				case 'm':
					mPressed(psNQueens);
					break;
				case 'n':
					nPressed(psNQueens);
					break;
				case 'r':
					rPressed(psNQueens);
					break;
				case 'e':
					ePressed(&bWaitingForInputActive);
					break;
				default:
					break;
			}
		}
	}
}