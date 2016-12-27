/**
 * @file NQueensData.h
 * @brief
 * @author
 * @date
 */
#define SMALLEST_BOARD 4

#define BIGGEST_BOARD 12

#define MODUS_ONE_BY_ONE 0

#define MODUS_CONTINUOUS 1 

#define FILE_SAVE_ON 1

#define FILE_SAVE_OFF 0 

#define AMOUNT_OF_SOLUTIONS 0

#define DEFAULT_RUNTIME 0

typedef enum algorithmModus algorithmModus;
typedef enum fileSaveActive fileSaveActive;
typedef struct nQueens nQueensData;

enum algorithmModus
{
	ONE_BY_ONE,
	CONTINIOUS
};

enum fileSaveActive
{
	OFF,
	ON
};

/**
* @struct nQueens
* @brief Complex data type for solving the nQueens problem
*/
struct nQueens
{
	int iChessBoardLength;             ///< current dimension of the chessboard
	int** ppiChessBoard;               ///< the chessboard itself or use int** ppiBoard; (mit malloc)
	algorithmModus eAlgoModus;			 ///< STEP or CONTINUOUS 
	fileSaveActive eSaveModus;			///< SAVE_OFF, SAVE_ON
	int iAmountOfSolutions;				 ///< actual found solutions
	char acFilename[255];             ///< path and filename where data shall be stored via DLL
	float fRuntime;            ///< Variable for measuring the runtime of the algorithm
};