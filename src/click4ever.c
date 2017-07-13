#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <xdo.h>

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
	xdo_get_mouse_location(xdo, &before.x, &before.x, &ignore_int);

	// Begin the process of dispatching mouse clicks quickly in succession.
	for (;;) {
		// Perform a mouse click.
		xdo_click_window(xdo, CURRENTWINDOW, 1);

		// This places a (small) delay between mouse clicks so that the
		// system won't be overloaded.
		usleep(50 * 1000);

		// Check the mouse position again to see if it has moved away.
		xdo_get_mouse_location(xdo, &after.x, &after.x, &ignore_int);

		if (before.x != after.x || before.y != after.y) {
			// The mouse moved away so that's our queue to stop.
			break;
		}
	}

	// Disconnect from the display.
	xdo_free(xdo);

	return 0;
}
