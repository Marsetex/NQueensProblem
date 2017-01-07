/**
 * @file UserInputLogicAlgorithm.h
 * @brief declarations of the functions for UserInputLogicAlgorithm.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

void waitForUserInputInOneByOne(bool* bInterruptActive, bool* bAlgorithmRunning, bool* bExitPressed);
void waitForUserInputInContinuous(bool* bAlgorithmRunning, bool* bExitPressed);