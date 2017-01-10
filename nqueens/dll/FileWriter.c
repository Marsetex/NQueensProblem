/**
 * @file FileWriter.c
 * @brief contains functions to write to a file
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdio.h>
#include <string.h>
#include "../common_includes/FileWriter.h"

/**
 * @fn __declspec(dllexport) void appendToFile(const char acText[], const char acFile[], char acErrorDescription[])
 * @brief appends a given text to the given file
 * @param const char acText[], const char acFile[], char acErrorDescription[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
DLL_TYPE void appendToFile(const char acText[], const char acFile[], char acErrorDescription[])
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
		strncpy(acErrorDescription, "Error: Cannot open file!", 75);
	}
}

/**
 * @fn __declspec(dllexport) void clearContentOfFile(const char acFile[], char acErrorDescription[])
 * @brief clears the content of the given file
 * @param const char acFile[], char acErrorDescription[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
DLL_TYPE void clearContentOfFile(const char acFile[], char acErrorDescription[])
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
		strncpy(acErrorDescription, "Error: Cannot open file!", 75);
	}
}