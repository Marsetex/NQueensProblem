/**
* @file Kap12_Auf02_Header.c
* @brief contains the functions of Kap12_Auf02_DLL.c
* @author Marcel Gruessinger
* @date 17.12.2016
*/
#ifdef DLL_EXPORTS
	#define DLL_TYPE __declspec(dllexport)
#else
	#define DLL_TYPE __declspec(dllimport)
#endif

DLL_TYPE void appendToFile(char acS[], char acFile[]);