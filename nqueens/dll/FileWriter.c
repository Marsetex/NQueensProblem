/**
 * @file FileWriter.c
 * @brief contains functions to write to a file
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "../common_includes/FileWriter.h"

/**
 * @fn __declspec(dllexport) void writeToFile(int aiNumbers[], int iNumberOfElements)
 * @brief write an int array to a file
 * @param int aiNumbers[], int iNumberOfElements
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
__declspec(dllexport) void appendToFile(char acS[], char acFile[])
{
	FILE* psFile;

	// Open file for appending content
	psFile = fopen(acFile, "a");

	if (psFile != 0)
	{
		// Write to file
		fputs(acS, psFile);

		fclose(psFile);
	}
	else
	{
		printf("Cannot open file! \n");
	}
}

/**
 * @fn __declspec(dllexport) void clearContentOfFile(char acFile[])
 * @brief clears the content of a file
 * @param char acFile[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
__declspec(dllexport) void clearContentOfFile(char acFile[]) 
{
	FILE* psFile;

	// Open file for writing
	psFile = fopen(acFile, "w");

	if (psFile != 0)
	{
		fclose(psFile);
	}
	else
	{
		printf("Cannot open file! \n");
	}
}