/**
 * @file UserInput.c
 * @brief handles the user input from different modes
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/UserInput.h"
#include "../common_includes/UserInputLogicMenu.h"

/**
 * @fn void userInput(applicationData* psAppData)
 * @brief handles the user input, when the application is in menu mode
 * @param applicationData* psAppData
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void waitForUserInputInMenu(applicationData* psAppData)
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
					plusPressed(psAppData);
					break;
				case '-':
					minusPressed(psAppData);
					break;
				case 'f':
					fPressed(psAppData);
					break;
				case 'm':
					mPressed(psAppData);
					break;
				case 'n':
					nPressed(psAppData);
					break;
				case 'r':
					bExitPressed = rPressed(psAppData);
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