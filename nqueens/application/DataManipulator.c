/**
 * @file DataManipulator.c
 * @brief
 * @author
 * @date
 */
#include <stdlib.h>
#include <string.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/DataManipulator.h"

 /**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
void generateChessBoard(int*** pppiBoard, int iBoardLength)
{
	*pppiBoard = (int**)calloc(iBoardLength, sizeof(int*));
	for (int i = 0; i < iBoardLength; i++) {
		(*pppiBoard)[i] = (int*)calloc(iBoardLength, sizeof(int));
	}
}

void freeChessBoardMemory(int** ppiBoard)
{
	free(ppiBoard);
}

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

void changeFileSaveMode(fileSaveActive* eSaveMode)
{
	if (*eSaveMode == ON)
	{
		*eSaveMode = OFF;
	}
	else {
		*eSaveMode = ON;
	}
}

void changeAlgorithmMode(algorithmModus* eAlgoMode) 
{
	if (*eAlgoMode == MODUS_ONE_BY_ONE)
	{
		*eAlgoMode = MODUS_CONTINUOUS;
	}
	else {
		*eAlgoMode = MODUS_ONE_BY_ONE;
	}
}

void changeFileName(char fileName[], char newFileName[]) {
	strncpy(fileName, newFileName, 76);
}