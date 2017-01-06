/**
 * @file AlgorithmHandler.h
 * @brief declarations of the functions for AlgorithmHandler.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

bool runAlgorithm(applicationData* data);
void saveSolutionToFile(applicationData* appData, bool* bFirstTryToWrite);
void handleOneByOneMode(applicationData* appData, bool* bAlgorithmRunning, bool* bExitPressed);
void handleContinuousMode(bool* bAlgorithmRunning, bool* bExitPressed);