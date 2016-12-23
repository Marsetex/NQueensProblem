#include <stdio.h>
#include "../common_includes/Menu.h"
#include "../common_includes/Utilities.h"

#define N 4

void printMenu(void) 
{
	printf("==== NQueens menu ===============================================================\n");
	printf("|                                                                               |\n");
	printf("|  Increase board size: +     Modus (one by one): o     Toggle file saving: f   |\n");
	printf("|  Decrease board size: -     Modus (continous):  c     File name:          n   |\n");
	printf("|  Run algorithm:       r     Stop algorithm:     s     Exit application:   e   |\n");
	printf("|                                                                               |\n");
	printf("=================================================================================\n");
}

void printBoard(int board[N][N])
{
	int x = 30;
	int y = 7;

	_gotoxy(35, 9);
	printf("---------");
	
	for (int i = 0; i < N; i++)
	{
		_gotoxy(35, 10 + i*2);
		for (int j = 0; j < N; j++) {
			printf("|%d", board[i][j]);
			if (j + 1 == N) {
				printf("|");
			}
		}
		_gotoxy(35, 10 + i*2 + 1);
		printf("---------");
	}
}

void printStatus(void) 
{
	_gotoxy(0, 20);

	printf("==== NQueens status =============================================================\n");
	printf("|                                                                               |\n");
	printf("|  Amount of solutions: 14200                            Runtime: 14,56568      |\n");
	printf("|  Board size: 12x12         Modus: One by one           File saving: OFF       |\n");
	printf("|  File name: C:\\temp\\hi.txt                                                    |\n");
	printf("|                                                                               |\n");
	printf("=================================================================================\n");
}