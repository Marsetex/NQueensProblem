#include <stdio.h>
#include <string.h>
#include "../common_includes/StringBuilder.h"

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