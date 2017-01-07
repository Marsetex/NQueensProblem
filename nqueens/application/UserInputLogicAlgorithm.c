/**
 * @file UserInputLogicAlgorithm.c
 * @brief handles the business logic after a key is pressed (in algorithm mode)
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include "../common_includes/UserInputLogicAlgorithm.h"

/**
 * @fn void waitForUserInputInOneByOne(bool* bInterruptActive, bool* bAlgorithmRunning, bool* bExitPressed)
 * @brief waits for user input in one-by-one-mode
 * @param bool* bInterruptActive, bool* bAlgorithmRunning, bool* bExitPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void waitForUserInputInOneByOne(bool* bInterruptActive, bool* bAlgorithmRunning, bool* bExitPressed)
{
	if (_kbhit())
	{
		int iChar = tolower(_getch());

		switch (iChar)
		{
			case 's':
				*bAlgorithmRunning = false;
				*bInterruptActive = false;
				break;
			case 'e':
				*bAlgorithmRunning = false;
				*bInterruptActive = false;
				*bExitPressed = true;
				break;
			default:
				*bInterruptActive = false;
				break;
		}
	}
}

/**
 * @fn void waitForUserInputInContinuous(bool* bAlgorithmRunning, bool* bExitPressed)
 * @brief waits for user input in continuous-mode
 * @param bool* bAlgorithmRunning, bool* bExitPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void waitForUserInputInContinuous(bool* bAlgorithmRunning, bool* bExitPressed) 
{
	if (_kbhit())
	{
		if (_getch() == 'e')
		{
			*bAlgorithmRunning = false;
			*bExitPressed = true;
		}
	}
}