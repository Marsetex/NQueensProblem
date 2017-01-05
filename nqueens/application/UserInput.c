/**
 * @file UserInput.c
 * @brief handles user input
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <conio.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/UserInput.h"
#include "../common_includes/UserInputLogic.h"

#define true 1
#define false 0

typedef int bool;

/**
 * @fn void userInput(applicationData* psNQueens)
 * @brief handles the user input, when the application is in menu mode
 * @param applicationData* psNQueens
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void userInput(applicationData* psNQueens) 
{
	int iChar = 0;
	bool bWaitingForInputActive = true;
	bool bExitPressed = false;
	
	while (bWaitingForInputActive && !bExitPressed)
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
					bExitPressed = rPressed(psNQueens);
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