#include <stdio.h>
#include <string.h>

void createCharArray(char dest[], int** source, int iBoardLength, int iSolutionNumber) 
{
	char acBuffer[30];

	sprintf(acBuffer, "\nSolution #%d \n \n", iSolutionNumber);
	strcat(dest, acBuffer);

	for (int i = 0; i < iBoardLength; i++)
	{
		for (int m = 0; m < iBoardLength; m++) 
		{
			sprintf(acBuffer, "%d ", source[i][m]);
			strcat(dest, acBuffer);
		}

		sprintf(acBuffer, "\n");
		strcat(dest, "\n");
	}
}