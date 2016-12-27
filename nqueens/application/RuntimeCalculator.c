#include "../common_includes/RuntimeCalculator.h"

void calculateRuntime(clock_t lTicksStart, clock_t lTicksEnd, float* fRuntime)
{
	clock_t lTicksResult = lTicksEnd - lTicksStart;
	*fRuntime = *fRuntime + ((float)lTicksResult / CLOCKS_PER_SEC);
}