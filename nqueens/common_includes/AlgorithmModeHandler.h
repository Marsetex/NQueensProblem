/**
 * @file AlgorithmModeHandler.h
 * @brief declarations of the functions for AlgorithmModeHandler.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

void handleOneByOneMode(applicationData* appData, bool* bAlgorithmRunning, bool* bExitPressed);
void handleContinuousMode(bool* bAlgorithmRunning, bool* bExitPressed);