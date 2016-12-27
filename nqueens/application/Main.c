/**
 * @file Main.c
 * @brief starting point of the application
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdlib.h>
#include "../common_includes/NQueensData.h"
#include "../common_includes/Initializer.h"
#include "../common_includes/UserInput.h"

/**
 * @fn int main(void)
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