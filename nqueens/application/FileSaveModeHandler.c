/**
 * @file FileSaveModeHandler.c
 * @brief functions for handling the file save mode tasks after a solution was found
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdbool.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/FileSaveModeHandler.h"
#include "../common_includes/FileWriter.h"
#include "../common_includes/StringConverter.h"

/**
* @fn void saveSolutionToFile(AppData_t* appData, bool* bFirstTryToWrite)
* @brief saves the solution to file; also clears the file if it is the first append
* @param AppData_t* appData, bool* bFirstTryToWrite
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*/
void saveSolutionToFile(AppData_t* psAppData, bool* bFirstTryToWrite)
{
	char acBoard[1350] = { "" };

	if (*bFirstTryToWrite == true)
	{
		*bFirstTryToWrite = false;
		clearContentOfFile(psAppData->acFilename, psAppData->acErrorDescription);
	}

	convertChessBoardToString(acBoard, psAppData->ppiChessBoard, psAppData->iChessBoardLength, psAppData->iAmountOfSolutions);
	appendToFile(acBoard, psAppData->acFilename, psAppData->acErrorDescription);
}