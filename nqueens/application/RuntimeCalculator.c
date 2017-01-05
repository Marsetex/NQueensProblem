/**
 * @file RuntimeCalculator.c
 * @brief handles runtime calculation
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
#include "../common_includes/RuntimeCalculator.h"

/**
 * @fn void calculateRuntime(clock_t lTicksStart, clock_t lTicksEnd, float* fRuntime)
 * @brief calculates the runtime by the given start and end ticks
 * @param clock_t lTicksStart, clock_t lTicksEnd, float* fRuntime
 * @return void
 * @author Marcel Gruessinger
 * @date 27.12.2016
 */
void calculateRuntime(clock_t lTicksStart, clock_t lTicksEnd, float* fRuntime)
{
	clock_t lTicksResult = lTicksEnd - lTicksStart;
	*fRuntime = *fRuntime + ((float)lTicksResult / CLOCKS_PER_SEC);
}