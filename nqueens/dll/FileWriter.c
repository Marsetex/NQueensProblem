/**
* @file Kap12_Auf02_DLL.c
* @brief contains functions to write to a file
* @author Marcel Gruessinger
* @date 17.12.2016
*/
#include <stdio.h>
#include <stdlib.h>
#include "../common_includes/FileWriter.h"

/**
* @fn __declspec(dllexport) void writeToFile(int aiNumbers[], int iNumberOfElements)
* @brief Write an int array to a file
* @param int aiNumbers[], int iNumberOfElements
* @return void
* @author Marcel Gruessinger
* @date 17.12.2016
*/
__declspec(dllexport) void appendToFile(char acS[], char acFile[])
{
	FILE* psFile;

	// Open file for writing
	psFile = fopen("..\\resources\\zahlen2.txt", "w");

	if (psFile != 0)
	{
		// Write to file
		fputs(acS, psFile);
		//printf("Writing to file completed. \n");

		fclose(psFile);
	}
	else
	{
		printf("Cannot open file! \n");
	}
}