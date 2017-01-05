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
 * @brief handles the first steps, which have to be done at application start
 * @param void
 * @return int
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
int main(void) {
	applicationData appData;

	initConsoleWindow();
	initApplicationData(&appData);
	initUserInterface(&appData);

	userInput(&appData);

	return EXIT_SUCCESS;
}