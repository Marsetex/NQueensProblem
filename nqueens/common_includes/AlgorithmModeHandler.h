/**
 * @file AlgorithmModeHandler.h
 * @brief declarations of the functions for AlgorithmModeHandler.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

void handleOneByOneMode(AppData_t* const psAppData, bool* const pbAlgorithmRunning, bool* const pbExitPressed);
void handleContinuousMode(bool* const pbAlgorithmRunning, bool* const pbExitPressed);