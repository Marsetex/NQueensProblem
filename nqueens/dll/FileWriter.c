/**
 * @file FileWriter.c
 * @brief contains functions to write to a file
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include "../common_includes/FileWriter.h"

/**
 * @fn __declspec(dllexport) void appendToFile(const char acText[], const char acFile[])
 * @brief appends a given text to the given file
 * @param const char acText[], const char acFile[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
__declspec(dllexport) void appendToFile(const char acText[], const char acFile[])
{
	FILE* psFile;

	// Open file for appending content
	psFile = fopen(acFile, "a");

	if (psFile != 0)
	{
		// Write to file
		fputs(acText, psFile);

		fclose(psFile);
	}
	else
	{
		printf("Cannot open file! \n");
	}
}

/**
 * @fn __declspec(dllexport) void clearContentOfFile(const char acFile[])
 * @brief clears the content of the given file
 * @param const char acFile[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
__declspec(dllexport) void clearContentOfFile(const char acFile[]) 
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