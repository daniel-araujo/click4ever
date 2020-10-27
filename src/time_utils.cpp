#include <time.h>

#include <unistd.h>

#include "time_utils.hpp"

/*
 * Current time in milliseconds.
 */
uint64_t millis()
{
	struct timespec now;
	clock_gettime(CLOCK_REALTIME, &now);
	return ((uint64_t) now.tv_sec) * 1000 + ((uint64_t) now.tv_nsec) / 1000000;
}