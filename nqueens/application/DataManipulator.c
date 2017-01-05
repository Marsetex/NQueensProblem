/**
 * @file DataManipulator.c
 * @brief utils for manipulation application data
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdlib.h>
#include <string.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/DataManipulator.h"

 /**
 * @fn void generateChessBoard(int*** pppiBoard, int iBoardLength)
 * @brief generates a chessboard for the given size
 * @param int*** pppiBoard, int iBoardLength
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void generateChessBoard(int*** pppiBoard, int iBoardLength)
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
 * @fn void changeFileSaveMode(fileSaveActive* eSavingActive)
 * @brief toogles between the existing file save modes
 * @param algorithmMode* eAlgoMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeFileSaveMode(fileSaveActive* eSavingActive)
{
	if (*eSavingActive == ON)
	{
		*eSavingActive = OFF;
	}
	else 
	{
		*eSavingActive = ON;
	}
}

/**
 * @fn void changeAlgorithmMode(algorithmMode* eAlgoMode)
 * @brief toogles between the existing algorithm modes
 * @param algorithmMode* eAlgoMode
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeAlgorithmMode(algorithmMode* eAlgoMode) 
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
 * @fn void changeFileName(char fileName[], char newFileName[])
 * @brief copies the file name into the destination array
 * @param char fileName[], char newFileName[]
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void changeFileName(char fileName[], char newFileName[]) {
	strncpy(fileName, newFileName, 76);
}