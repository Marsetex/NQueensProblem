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
 * @fn void generateChessBoard(int*** pppiBoard, const int iBoardLength)
 * @brief generates a chessboard for the given length
 * @param int*** pppiBoard, const int iBoardLength
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void generateChessBoard(int*** pppiBoard, const int iBoardLength)
{
	*pppiBoard = (int**)calloc(iBoardLength, sizeof(int*));
	for (int i = 0; i < iBoardLength; i++) 
	{
		(*pppiBoard)[i] = (int*)calloc(iBoardLength, sizeof(int));
	}
}

/**
 * @fn void freeChessBoardMemory(int** ppiBoard)
 * @brief frees the memory allocated for the chessboard
 * @param int** ppiBoard
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void freeChessBoardMemory(int** ppiBoard)
{
	free(ppiBoard);
}

/**
 * @fn void incrementBoardLength(int* piBoardLength)
 * @brief increases the length of the chess board
 * @param int* piBoardLength
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 * 
 * If the board reached the length of 12 it will be reset to 4.
 */
void incrementBoardLength(int* piBoardLength)
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
* @fn void decrementBoardLength(int* piBoardLength)
* @brief decreases the length of the chess board
* @param int* piBoardLength
* @return void
* @author Marcel Gruessinger
* @date 27.12.2016
*
* If the board reached the length of 4 it will be reset to 12.
*/
void decrementBoardLength(int* piBoardLength) 
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
 * @fn void changeFileSaveMode(FileSaveMode_t* eSaveMode)
 * @brief toogles between the existing file save modes
 * @param FileSaveMode_t* eSaveMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeFileSaveMode(FileSaveMode_t* eSaveMode)
{
	if (*eSaveMode == ON)
	{
		*eSaveMode = OFF;
	}
	else 
	{
		*eSaveMode = ON;
	}
}

/**
 * @fn void changeAlgorithmMode(AlgorithmMode_t* eAlgoMode)
 * @brief toogles between the existing algorithm modes
 * @param AlgorithmMode_t* eAlgoMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeAlgorithmMode(AlgorithmMode_t* eAlgoMode) 
{
	if (*eAlgoMode == MODUS_ONE_BY_ONE)
	{
		*eAlgoMode = MODUS_CONTINUOUS;
	}
	else
	{
		*eAlgoMode = MODUS_ONE_BY_ONE;
	}
}

/**
 * @fn void changeFileName(char acOldFileName[], const char acNewFileName[]) 
 * @brief copies the new file name into the old file name
 * @param char acOldFileName[], const char acNewFileName[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeFileName(char acOldFileName[], const char acNewFileName[]) 
{
	strncpy(acOldFileName, acNewFileName, 76);
}