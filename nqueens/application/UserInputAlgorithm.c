/**
 * @file UserInputAlgorithm.c
 * @brief handles the user input in algorithm mode
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/UserInputAlgorithm.h"
#include "../common_includes/UserInputLogicAlgorithm.h"

 /**
 * @fn void waitForUserInputInOneByOne(bool* bAlgorithmRunning, bool* bExitPressed)
 * @brief handles the user input, when the application is in one-by-one mode
 * @param  bool* bAlgorithmRunning, bool* bExitPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void waitForUserInputInOneByOne(bool* bAlgorithmRunning, bool* bExitPressed)
{
	bool bInterruptActive = true;

	while (bInterruptActive)
	{
		if (_kbhit())
		{
			int iChar = tolower(_getch());

			switch (iChar)
			{
				case 's':
					sPressedInAlgorithmMode(bAlgorithmRunning);
					bInterruptActive = false;
					break;
				case 'e':
					ePressedInAlgorithmMode(bAlgorithmRunning, bExitPressed);
					bInterruptActive = false;
					break;
				default:
					bInterruptActive = false;
					break;
			}
		}
	}
}

/**
* @fn void waitForUserInputInContinuous(bool* bAlgorithmRunning, bool* bExitPressed)
* @brief handles the user input, when the application is in continuous mode
* @param bool* bAlgorithmRunning, bool* bExitPressed
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void waitForUserInputInContinuous(bool* bAlgorithmRunning, bool* bExitPressed)
{
	if (_kbhit())
	{
		int iChar = tolower(_getch());

		if (iChar == 'e')
		{
			ePressedInAlgorithmMode(bAlgorithmRunning, bExitPressed);
		}
	}
}