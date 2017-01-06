/**
 * @file ApplicationData.h
 * @brief declarations of structs, enums, ... for the application 
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#define SMALLEST_BOARD 4

#define BIGGEST_BOARD 12

#define MODUS_ONE_BY_ONE 0

#define MODUS_CONTINUOUS 1 

#define FILE_SAVE_ON 1

#define FILE_SAVE_OFF 0 

#define AMOUNT_OF_SOLUTIONS 0

#define DEFAULT_RUNTIME 0

typedef enum algorithmMode algorithmMode;
typedef enum fileSaveMode fileSaveMode;
typedef struct applicationData applicationData;

enum algorithmModus
{
	ONE_BY_ONE,
	CONTINIOUS
};

enum fileSaveMode
{
	OFF,
	ON
};

struct applicationData
{
	int iChessBoardLength;            
	int** ppiChessBoard;               
	int iAmountOfSolutions;				
	algorithmMode eAlgorithmMode;		 
	fileSaveMode eSaveMode;
	char acFilename[255];             
	float fRuntime;
	char acProgramStatus[23];
};