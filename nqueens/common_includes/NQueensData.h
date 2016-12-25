/**
 * @file NQueensData.h
 * @brief
 * @author
 * @date
 */
#define SMALLEST_BOARD 4

#define BIGGEST_BOARD 12

/**
* @struct nQueens
* @brief Complex data type for solving the nQueens problem
*/
struct nQueens
{
	int iChessBoardLength;             ///< current dimension of the chessboard
	int** ppiChessBoard;               ///< the chessboard itself or use int** ppiBoard; (mit malloc)
									   //unsigned bitAppMode : 1;         ///< STEP or CONTINUOUS 
									   //unsigned bitSaveMode : 1;         ///< SAVE_OFF, SAVE_ON
									   //int iCountOfSolutions;            ///< actual found solutions
									   //struct AppTime sAppTime;          ///< Variable for measuring the runtime of the algorithm
									   //char acFilename[255];             ///< path and filename where data shall be stored via DLL
};