/**
 * @file UserInput.c
 * @brief handles user input
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/UserInput.h"
#include "../common_includes/UserInputLogic.h"

/**
 * @fn void userInput(applicationData* psNQueens)
 * @brief handles the user input, when the application is in menu mode
 * @param applicationData* psNQueens
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void waitForUserInputInMenu(applicationData* psNQueens)
{
	int iChar = 0;
	bool bWaitingForInputActive = true;
	bool bExitPressed = false;
	
	while (bWaitingForInputActive && !bExitPressed)
	{
		if(_kbhit()) 
		{
			iChar = tolower(_getch());

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