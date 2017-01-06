/**
 * @file StringBuilder.c
 * @brief handles conversion to string
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/StringBuilder.h"

/**
 * @fn void createCharArray(char dest[], int** source, int iBoardLength, int iSolutionNumber) 
 * @brief convertes the chess board from int to char
 * @param char dest[], int** source, int iBoardLength, int iSolutionNumber
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
void createCharArray(char dest[], int** source, int iBoardLength, int iSolutionNumber) 
{
	char acBuffer[51];
	char acTrennlinie[51] = { "-" };

	for (int i = 0; i < iBoardLength; i++)
	{
		strcat(acTrennlinie, "----");
	}

	sprintf(acBuffer, " \nSolution #%d \n \n", iSolutionNumber);
	strcat(dest, acBuffer);

	for (int i = 0; i < iBoardLength; i++)
	{
		strcat(dest, acTrennlinie);
		strcat(dest, "\n");

		for (int m = 0; m < iBoardLength; m++) 
		{
			if (source[i][m] == 1)
			{
				strcat(dest, "| Q ");
			}
			else 
			{
				strcat(dest, "|   ");
			}

			if (m + 1 == iBoardLength) 
			{
				strcat(dest,"|");
			}
		}

		strcat(dest, "\n");
	}

	strcat(dest, acTrennlinie);
	strcat(dest, "\n");
}

/**
 * @fn void convertAlgorithmModeToString(char acBuffer[], algorithmMode algoMode)
 * @brief converts the alogrithm mode enum to a string representation
 * @param char acBuffer[], algorithmMode algoMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void convertAlgorithmModeToString(char acBuffer[], algorithmMode algoMode) 
{
	if (algoMode == MODUS_CONTINUOUS) 
	{
		strncpy(acBuffer, "Continious", 11);
	}
	else 
	{
		strncpy(acBuffer, "One by One", 11);
	}
}

/**
 * @fn void convertSaveModeToString(char acBuffer[], fileSaveActive saveMode)
 * @brief converts the file save active enum to a string representation
 * @param char acBuffer[], fileSaveActive saveMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void convertSaveModeToString(char acBuffer[], fileSaveMode eSaveMode)
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