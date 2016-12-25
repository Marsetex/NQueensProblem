/**
 * @file Main.c
 * @brief
 * @author
 * @date
 */
#include <stdlib.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/Initializer.h"
#include "../common_includes/UserInput.h"

/**
 * @fn FunctionName
 * @brief
 * @param
 * @return
 * @author
 * @date
 */
int main(void) {
	struct nQueens sNQueens;

	initializeProgram(&sNQueens);

	userInput(&sNQueens);

	return EXIT_SUCCESS;
}