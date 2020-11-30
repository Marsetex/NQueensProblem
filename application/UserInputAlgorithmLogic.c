/**
 * @file UserInputAlgorithmLogic.c
 * @brief handles the business logic after a key is pressed (in algorithm mode)
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include "../common_includes/UserInputAlgorithmLogic.h"

/**
 * @fn void sPressedInAlgorithmMode(bool* const pbAlgorithmRunning)
 * @brief interrupts the algorithm by setting the boolean to false
 * @param bool* const pbAlgorithmRunning
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void sPressedInAlgorithmMode(bool* const pbAlgorithmRunning)
{
	*pbAlgorithmRunning = false;
}

/**
 * @fn void ePressedInAlgorithmMode(bool* const pbAlgorithmRunning, bool* const pbExitKeyPressed)
 * @brief sets the tokens to stop the application
 * @param bool* const pbAlgorithmRunning
 * @param bool* const pbExitKeyPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void ePressedInAlgorithmMode(bool* const pbAlgorithmRunning, bool* const pbExitKeyPressed)
{
	*pbAlgorithmRunning = false;
	*pbExitKeyPressed = true;
}