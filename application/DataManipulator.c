/**
 * @file DataManipulator.c
 * @brief functions for manipulation the application data
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdlib.h>
#include <string.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/DataManipulator.h"

 /**
 * @fn void generateChessBoard(int*** const pppiBoard, const int iBoardLength)
 * @brief generates a chessboard for the given length
 * @param int*** const pppiBoard
 * @param const int iBoardLength
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void generateChessBoard(int*** const pppiBoard, const int iBoardLength)
{
	*pppiBoard = (int**)calloc(iBoardLength, sizeof(int*));
	for (int i = 0; i < iBoardLength; i++) 
	{
		(*pppiBoard)[i] = (int*)calloc(iBoardLength, sizeof(int));
	}
}

/**
 * @fn void freeChessBoardMemory(int** const ppiBoard)
 * @brief frees the memory allocated for the chessboard
 * @param int** const ppiBoard
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void freeChessBoardMemory(int** const ppiBoard)
{
	free(ppiBoard);
}

/**
 * @fn void incrementBoardLength(int* const piBoardLength)
 * @brief increases the length of the chess board
 * @param int* const piBoardLength
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 * 
 * If the board reached the length of 12 it will be reset to 4.
 */
void incrementBoardLength(int* const piBoardLength)
{ 
	if (*piBoardLength == 12) 
	{
		*piBoardLength = 4;
	}
	else 
	{
		*piBoardLength = *piBoardLength + 1;
	}
}

/**
* @fn void decrementBoardLength(int* const piBoardLength)
* @brief decreases the length of the chess board
* @param int* const piBoardLength
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*
* If the board reached the length of 4 it will be reset to 12.
*/
void decrementBoardLength(int* const piBoardLength)
{
	if (*piBoardLength == 4)
	{
		*piBoardLength = 12;
	}
	else
	{
		*piBoardLength = *piBoardLength - 1;
	}
}

/**
 * @fn void changeFileSaveMode(FileSaveMode_t* const peSaveMode)
 * @brief toogles between the existing file save modes
 * @param FileSaveMode_t* const peSaveMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeFileSaveMode(FileSaveMode_t* const peSaveMode)
{
	if (*peSaveMode == ON)
	{
		*peSaveMode = OFF;
	}
	else 
	{
		*peSaveMode = ON;
	}
}

/**
 * @fn void changeAlgorithmMode(AlgorithmMode_t* const peAlgoMode)
 * @brief toogles between the existing algorithm modes
 * @param AlgorithmMode_t* const peAlgoMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeAlgorithmMode(AlgorithmMode_t* const peAlgoMode)
{
	if (*peAlgoMode == MODUS_ONE_BY_ONE)
	{
		*peAlgoMode = MODUS_CONTINUOUS;
	}
	else
	{
		*peAlgoMode = MODUS_ONE_BY_ONE;
	}
}

/**
 * @fn void changeFileName(char acOldFileName[], const char acNewFileName[]) 
 * @brief copies the new file name into the old file name
 * @param char acOldFileName[]
 * @param const char acNewFileName[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeFileName(char acOldFileName[], const char acNewFileName[]) 
{
	strncpy(acOldFileName, acNewFileName, 76);
}