/**
 * @file FileWriter.h
 * @brief declarations of the functions for FileWriter.c
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */

#pragma warning(disable:4996)

#ifdef DLL_EXPORTS
	#define DLL_TYPE __declspec(dllexport)
#else
	#define DLL_TYPE __declspec(dllimport)
#endif

DLL_TYPE void appendToFile(const char acText[], const char acFile[]);
DLL_TYPE void clearContentOfFile(const char acFile[]);