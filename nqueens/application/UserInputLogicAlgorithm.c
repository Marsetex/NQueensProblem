/**
 * @file UserInputLogicAlgorithm.c
 * @brief handles the business logic after a key is pressed (in algorithm mode)
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include "../common_includes/UserInputLogicAlgorithm.h"

/**
 * @fn void sPressedInAlgorithmMode(bool* bAlgorithmRunning)
 * @brief interrupts the algorithm by setting the boolean to false
 * @param bool* bAlgorithmRunning
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void sPressedInAlgorithmMode(bool* bAlgorithmRunning)
{
	*bAlgorithmRunning = false;
}

/**
 * @fn void ePressedInAlgorithmMode(bool* bAlgorithmRunning, bool* bExitKeyPressed)
 * @brief sets the tokens to stop the application
 * @param bool* bAlgorithmRunning, bool* bExitKeyPressed
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void ePressedInAlgorithmMode(bool* bAlgorithmRunning, bool* bExitKeyPressed)
{
	*bAlgorithmRunning = false;
	*bExitKeyPressed = true;
}