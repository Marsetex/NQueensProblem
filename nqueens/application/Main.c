/**
 * @file Main.c
 * @brief starting point of the application
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <stdlib.h>
#include "../common_includes/ApplicationData.h"
#include "../common_includes/Initializer.h"
#include "../common_includes/UserInputMenu.h"

/**
 * @fn int main(void)
 * @brief handles the first steps, which have to be done at application start
 * @param void
 * @return int
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
int main(void) {
	applicationData sAppData;

	// Init application
	initConsoleWindow();
	initApplicationData(&sAppData);
	initUserInterface(&sAppData);

	// Start waiting for user input
	waitForUserInputInMenu(&sAppData);

	return EXIT_SUCCESS;
}