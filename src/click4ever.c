#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <unistd.h>
#include <xdo.h>
#include <time.h>

/*
 * Delay between clicks in milliseconds.
 */
const uint64_t delay = 50;

/*
 * Current time in milliseconds.
 */
static inline uint64_t millis()
{
	struct timespec now;
	clock_gettime(CLOCK_REALTIME, &now);
	return ((uint64_t) now.tv_sec) * 1000 + ((uint64_t) now.tv_nsec) / 1000000;
}

/*
 * This is a program that lets the user choose a position on the screen where
 * mouse clicks will be generated quickly in succession until the mouse is
 * moved away.
 */
int main(void)
{
	// Variables used as output parameters whose values we're not
	// interested in.
	int ignore_int;
	Window ignore_window;

	// Connect to the display.
	xdo_t *xdo = xdo_new(NULL);

	if (xdo == NULL) {
		// Something went wrong and there seems to be no way of knowing
		// what.
		fprintf(stderr, "Unable to connect to the display.\n");
		return 1;
	}

	// Tracks the mouse position before and after a click so we can detect
	// if the mouse moved away.
	struct {
		int x;
		int y;
	} before, after;

	// Now we're going to wait for a mouse click.
	xdo_select_window_with_click(xdo, &ignore_window);

	// We got a click so let's get the coordinates of the mouse. This will
	// be the position where we're going to dispatch mouse clicks.
	xdo_get_mouse_location(xdo, &before.x, &before.y, &ignore_int);

	// Begin the process of dispatching mouse clicks quickly in succession.
	for (;;) {
		uint64_t begin = millis();

		// Checks mouse position.
		{
			xdo_get_mouse_location(xdo, &after.x, &after.y, &ignore_int);

			if (before.x != after.x || before.y != after.y) {
				// The mouse moved away so that's our queue to stop.
				break;
			}
		}

		// Performs mouse click.
		{
			xdo_click_window(xdo, CURRENTWINDOW, 1);
		}

		uint64_t execution_time = millis() - begin;

		// Delay
		{
			if (execution_time < delay) {
				uint64_t remaining_time = delay - execution_time;
				usleep(remaining_time * 1000);
			} else {
				// No need to sleep.
			}
		}

		uint64_t total_time = millis() - begin;
	}

	// Disconnect from the display.
	xdo_free(xdo);

	return 0;
}
