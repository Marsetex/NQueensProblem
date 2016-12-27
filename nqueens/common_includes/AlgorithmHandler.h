/**
 * @file Kap12_Auf02_Header.h
 * @brief contains the functions of Kap12_Auf02_DLL.c
 * @author Marcel Gruessinger
 * @date 17.12.2016
 */
#include <time.h>

#define START_COLUMN 0
#define true 1
#define false 0

typedef int bool;
typedef struct nQueens nQueensData;

void runAlgorithm(nQueensData* data);