/**
 * @file UserInputAlgorithm.c
 * @brief handles the user input while the algorithm is active
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/UserInputAlgorithm.h"
#include "../common_includes/UserInputAlgorithmLogic.h"

 /**
 * @fn void waitForUserInputInOneByOne(bool* const pbAlgorithmRunning, bool* const pbExitPressed)
 * @brief handles the user input, when the application is in one-by-one mode
 * @param  bool* const pbAlgorithmRunning, bool* const pbExitPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void waitForUserInputInOneByOne(bool* const pbAlgorithmRunning, bool* const pbExitPressed)
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
					sPressedInAlgorithmMode(pbAlgorithmRunning);
					bInterruptActive = false;
					break;
				case 'e':
					ePressedInAlgorithmMode(pbAlgorithmRunning, pbExitPressed);
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
* @fn void waitForUserInputInContinuous(bool* const pbAlgorithmRunning, bool* constp bExitPressed)
* @brief handles the user input, when the application is in continuous mode
* @param bool* const pbAlgorithmRunning, bool* const pbExitPressed
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void waitForUserInputInContinuous(bool* const pbAlgorithmRunning, bool* const pbExitPressed)
{
	if (_kbhit())
	{
		int iChar = tolower(_getch());

		if (iChar == 'e')
		{
			ePressedInAlgorithmMode(pbAlgorithmRunning, pbExitPressed);
		}
	}
}