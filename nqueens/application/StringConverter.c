/**
 * @file StringConverter.c
 * @brief functions to convert application data to string
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/StringConverter.h"

/**
 * @fn void convertChessBoardToString(char acBoard[], const int** const ppiBoard, const int iBoardLength, const int iSolutionNumber) 
 * @brief convertes the chess board from int to a string representation
 * @param char acBoard[], const int** const ppiBoard, const int iBoardLength, const int iSolutionNumber
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 *
 * Format after the conversion:
 *
 * Solution #x
 *
 * ---------
 * |   | Q |
 * ---------
 * |   |   |
 * ---------
 */
void convertChessBoardToString(char acBoard[], const int** const ppiBoard, const int iBoardLength, const int iSolutionNumber)
{
	char acBuffer[51];
	char acHorizontalLine[51] = { "-" };

	// Create horizontal chess board lines for the board length
	for (int i = 0; i < iBoardLength; i++)
	{
		strcat(acHorizontalLine, "----");
	}

	sprintf(acBuffer, " \nSolution #%d \n \n", iSolutionNumber);
	strcat(acBoard, acBuffer);

	for (int i = 0; i < iBoardLength; i++)
	{
		strcat(acBoard, acHorizontalLine);
		strcat(acBoard, "\n");

		for (int m = 0; m < iBoardLength; m++) 
		{
			if (ppiBoard[i][m] == 1)
			{
				strcat(acBoard, "| Q ");
			}
			else 
			{
				strcat(acBoard, "|   ");
			}

			if (m + 1 == iBoardLength) 
			{
				strcat(acBoard, "|");
			}
		}

		strcat(acBoard, "\n");
	}

	strcat(acBoard, acHorizontalLine);
	strcat(acBoard, "\n");
}

/**
 * @fn void convertAlgorithmModeToString(char acBuffer[], const AlgorithmMode_t eAlgoMode)
 * @brief converts the alogrithm mode enum to a string representation
 * @param char acBuffer[], const AlgorithmMode_t eAlgoMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void convertAlgorithmModeToString(char acBuffer[], const AlgorithmMode_t eAlgoMode) 
{
	if (eAlgoMode == MODUS_CONTINUOUS)
	{
		strncpy(acBuffer, "Continious", 11);
	}
	else 
	{
		strncpy(acBuffer, "One by One", 11);
	}
}

/**
 * @fn void convertSaveModeToString(char acBuffer[], const FileSaveActive_t saveMode)
 * @brief converts the file save active enum to a string representation
 * @param char acBuffer[], const fileSaveActive saveMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void convertSaveModeToString(char acBuffer[], const FileSaveMode_t eSaveMode)
{
	if (eSaveMode == ON)
	{
		strncpy(acBuffer, "ON", 4);
	}
	else
	{
		strncpy(acBuffer, "OFF", 4);
	}
}