/**
 * @file RuntimeCalculator.c
 * @brief handles runtime calculation
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include <time.h>
#include "../common_includes/RuntimeCalculator.h"

/**
 * @fn void calculateRuntime(const clock_t lTicksStart, const clock_t lTicksEnd, float* const pfRuntime)
 * @brief calculates the runtime by the given start and end ticks
 * @param const clock_t lTicksStart
 * @param const clock_t lTicksEnd
 * @param float* const pfRuntime
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void calculateRuntime(const clock_t lTicksStart, const clock_t lTicksEnd, float* const pfRuntime)
{
	clock_t lTicksResult = lTicksEnd - lTicksStart;
	*pfRuntime = *pfRuntime + ((float)lTicksResult / CLOCKS_PER_SEC);
}