#include <stdlib.h>
#include <unistd.h>
#include <xdo.h>

int main(void)
{
	// Variables used as output parameters whose values we're not interested.
	int ignore_int;
	Window ignore_window;

	// Proceed with ritual.
	xdo_t *xdo = xdo_new(NULL);

	if (xdo == NULL) {
		// Something went wrong and there seems to be no way of knowing
		// what.
		return 1;
	}

	// We're going to wait for the first mouse click. It will be at that
	// position that we're going to dispatch our simulated mouse clicks.
	xdo_select_window_with_click(xdo, &ignore_window);

	// These are going to remember mouse positions so we can end the
	// program when we detect that the mouse moved away the bullseye.
	struct {
		int x;
		int y;
	} before, after;

	xdo_get_mouse_location(xdo, &before.x, &before.x, &ignore_int);

	// Let's start firing.
	for (;;) {
		xdo_click_window(xdo, CURRENTWINDOW, 1);

		// This places a (small) delay between clicks so we don't
		// overwhelm the system.
		usleep(50 * 1000);

		xdo_get_mouse_location(xdo, &after.x, &after.x, &ignore_int);

		if (before.x != after.x || before.y != after.y) {
			// It moved so it's over.
			break;
		}
	}

	// Tell it to clean it up and leave.
	xdo_free(xdo);

	return 0;
}
